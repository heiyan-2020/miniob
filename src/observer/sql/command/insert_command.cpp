#include "insert_command.h"
#include "storage/common/db.h"
#include "session/session.h"
#include "type/value.h"
#include "storage/common/table.h"
#include "util/date.h"

#define CHECK_FIELD_TYPE(TYPE)                                                      \
 do {                                                                               \
    if (field_meta.type() != TYPE) {                                                \
      LOG_ERROR("Invalid value type, table name = %s, fields name = %s, type = %d", \
        table_meta.name().c_str(),                                                  \
        field_meta.name().c_str(),                                                  \
        field_meta.type());                                                         \
      return RC::SCHEMA_FIELD_MISSING;                                              \
    }                                                                               \
  } while (0)                                                                       \

InsertCommand::InsertCommand(const hsql::InsertStatement *stmt) : Command{hsql::kStmtInsert}, stmt_{stmt}
{}

RC InsertCommand::execute(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  switch (stmt_->type) {
    case hsql::kInsertValues: {
      RC rc = do_insert_values(sql_event);
      if (rc == RC::SUCCESS) {
        session_event->set_response("SUCCESS");
      } else {
        session_event->set_response("FAILURE");
      }
      return rc;
    }
    default:
      return RC::UNIMPLENMENT;
  }
}

RC InsertCommand::do_insert_values(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();

  Table *table = db->find_table(stmt_->tableName);
  RC rc = RC::SUCCESS;
  if (nullptr == table) {
    LOG_ERROR("Can't find table: %s", stmt_->tableName);
    return RC::INVALID_ARGUMENT;
  }

  const TableMeta &table_meta = table->table_meta();
  const std::vector<FieldMeta> *field_metas = table_meta.field_metas();

  std::vector<Value> insert_values;
  for (auto val_list : *stmt_->values) {
    insert_values.clear();

    if (static_cast<int>(val_list->size()) + table_meta.sys_field_num() != table_meta.field_num()) {
      LOG_WARN("Input values don't match the table's schema, table name %s", table_meta.name().c_str());
      return RC::SCHEMA_FIELD_MISSING;
    }

    size_t curr_index = table_meta.sys_field_num();
    for (auto expr : *val_list) {
      const FieldMeta &field_meta = field_metas->at(curr_index);
      switch (expr->type) {
        case hsql::ExprType::kExprLiteralInt: {
          CHECK_FIELD_TYPE(INT);
          insert_values.emplace_back(INT, static_cast<int32_t>(expr->ival));
          break;
        }
        case hsql::ExprType::kExprLiteralFloat: {
          CHECK_FIELD_TYPE(FLOAT);
          insert_values.emplace_back(FLOAT, static_cast<float>(expr->fval));
          break;
        }
        case hsql::ExprType::kExprLiteralString: {
          // handle DATE and CHAR here
          // NOTE: only `insert into t values (date '2022-10-10');` can be resolved as kExprLiteralDate
          if (field_meta.type() == DATE) {
            void *dst = calloc(1, sizeof(int32_t[3]));
            rc = Date::parse_date(dst, expr->name);
            if (rc != RC::SUCCESS) {
              free(dst);
              return rc;
            } else {
              insert_values.emplace_back(DATE, static_cast<const int32_t *>(dst));
              free(dst);
            }
          } else {
            CHECK_FIELD_TYPE(CHAR);
            insert_values.emplace_back(CHAR, expr->name, field_meta.len());
          }
          break;
        }
        default: {
          LOG_ERROR("Unsupported data type: %d", expr->type);
          return RC::UNIMPLENMENT;
        }
      }
      curr_index += 1;
    }

    rc = table->insert_record(nullptr, insert_values);
    if (rc != RC::SUCCESS) {
      return rc;
    }
  }

  return rc;
}
