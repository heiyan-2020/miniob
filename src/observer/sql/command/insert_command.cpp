#include "insert_command.h"
#include "storage/common/db.h"
#include "session/session.h"
#include "type/value.h"
#include "storage/common/table.h"
#include "util/date.h"
#include "util/type_converter.h"
#include "storage/clog/clog.h"
#include "storage/trx/trx.h"

static inline bool convertible(TypeId lhs, TypeId rhs)
{
  if (lhs != INT && lhs != FLOAT && lhs != CHAR) {
    return false;
  }
  if (rhs != INT && rhs != FLOAT && rhs != CHAR) {
    return false;
  }
  return true;
}

#define CHECK_FIELD_TYPE(TYPE)                                                      \
 do {                                                                               \
    if (field_meta.type() != TYPE && !convertible(field_meta.type(), TYPE)) {                                                \
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
        session_event->set_response("SUCCESS\n");
      } else {
        session_event->set_response("FAILURE\n");
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
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  Table *table = db->find_table(stmt_->tableName);
  RC rc = RC::SUCCESS;
  if (nullptr == table) {
    LOG_ERROR("Can't find table: %s", stmt_->tableName);
    return RC::INVALID_ARGUMENT;
  }

  const TableMeta &table_meta = table->table_meta();
  const std::vector<FieldMeta> *field_metas = table_meta.field_metas();

  std::vector<std::vector<Value>> insert_values_list{};
  // check all values before insertion
  for (auto val_list : *stmt_->values) {
    if (val_list->size() + TableMeta::sys_field_num() != table_meta.field_num()) {
      LOG_WARN("Input values don't match the table's schema, table name %s", table_meta.name().c_str());
      return RC::SCHEMA_FIELD_MISSING;
    }

    std::vector<Value> insert_values{};
    size_t curr_index = TableMeta::sys_field_num();
    for (auto expr : *val_list) {
      const FieldMeta &field_meta = field_metas->at(curr_index);
      switch (expr->type) {
        case hsql::ExprType::kExprLiteralInt: {
          CHECK_FIELD_TYPE(INT);
//          insert_values.emplace_back(INT, static_cast<int32_t>(expr->ival));
          insert_values.push_back(TypeConverter::get_from_int(field_meta.type(), static_cast<int32_t>(expr->ival)));
          break;
        }
        case hsql::ExprType::kExprLiteralFloat: {
          CHECK_FIELD_TYPE(FLOAT);
//          insert_values.emplace_back(FLOAT, static_cast<float>(expr->fval));
          insert_values.push_back(TypeConverter::get_from_float(field_meta.type(), static_cast<float>(expr->fval)));
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
//            insert_values.emplace_back(CHAR, expr->name, field_meta.len());
            insert_values.push_back(TypeConverter::get_from_char(field_meta.type(), expr->name, field_meta.len()));
          }
          break;
        }
        case hsql::ExprType::kExprLiteralNull: {
          if (!field_meta.nullable()) {
            return RC::CONSTRAINT_NOTNULL;
          }
          insert_values.emplace_back(field_meta.type());
          break;
        }
        default: {
          LOG_ERROR("Unsupported data type: %d", expr->type);
          return RC::UNIMPLENMENT;
        }
      }
      curr_index += 1;
    }
    insert_values_list.emplace_back(insert_values);
  }

  // now insert
  for (const auto& insert_values : insert_values_list) {
    rc = table->insert_record(trx, insert_values);
    if (rc != RC::SUCCESS) {
      return rc;
    }
  }

  // success
  if (!session->is_trx_multi_operation_mode()) {
    CLogRecord *clog_record = nullptr;
    rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
    if (rc != RC::SUCCESS || clog_record == nullptr) {
      return rc;
    }

    rc = clog_manager->clog_append_record(clog_record);
    if (rc != RC::SUCCESS) {
      return rc;
    }

    trx->next_current_id();
  }

  return rc;
}
