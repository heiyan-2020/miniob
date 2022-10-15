#include "update_command.h"
#include "storage/common/db.h"
#include "sql/binder/planner.h"
#include "session/session.h"
#include "type/value.h"
#include "storage/common/table.h"
#include "util/date.h"
#include "storage/record/record.h"

UpdateCommand::UpdateCommand(const hsql::UpdateStatement *stmt) : Command{hsql::kStmtUpdate}, stmt_{stmt}
{}

RC UpdateCommand::execute(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  RC rc = do_update(sql_event);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}

RC UpdateCommand::do_update(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();

  const auto* table_ref = stmt_->table;
  Table *table = db->find_table(table_ref->getName());
  RC rc = RC::SUCCESS;
  if (nullptr == table) {
    LOG_ERROR("Can't find table: %s", table_ref->getName());
    return RC::INVALID_ARGUMENT;
  }

  Planner planner(db);
  std::shared_ptr<PlanNode> sp;
  rc = planner.make_plan_upd(stmt_, sp);
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
    return rc;
  }
  sp->prepare();
  sp->initialize();

  const TableMeta &table_meta = table->table_meta();
  const std::vector<FieldMeta> *field_metas = table_meta.field_metas();
  size_t curr_index = table_meta.sys_field_num();

  // 由于比赛只要求 set 单个字段，所以其实这里的 for 循环只会执行一次
  for (auto updateClause: *stmt_->updates) {

    // find appropriate filed
    FieldMeta field_meta = field_metas->at(curr_index);
    while (field_meta.name() != updateClause->column) {
      curr_index++;
      if (curr_index >= field_metas->size()) {
        LOG_WARN("update stmt offset has no related field");
        return RC::INTERNAL;
      }
      field_meta = field_metas->at(curr_index);
    }

    // check schema
    rc = check_schema(field_meta, updateClause);
    if (rc != RC::SUCCESS) {
      LOG_WARN("update with invalid value!: %s", strrc(rc));
      return rc;
    }

    rc = sp->next();
    while (RC::SUCCESS == rc) {
      TupleRef tuple;
      rc = sp->current_tuple(tuple);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to get current record: %s", strrc(rc));
        return rc;
      }

      Record old_record = tuple->get_record();
      int record_size = table_meta.record_size();
      char *data = new char[record_size];
      memcpy(data, old_record.data(), record_size);

      const hsql::Expr *expr = updateClause->value;
      Value new_value;
      rc = data_2_value(expr, new_value, field_meta);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to convert new record to byte code due to type constraint: %s", strrc(rc));
        return rc;
      }

      new_value.serialize_to(data + field_meta.offset());
      Record new_record;
      new_record.set_rid(old_record.rid());
      new_record.set_data(data);

      rc = table->update_record(nullptr, &old_record, &new_record);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to update record: %s", strrc(rc));
        return rc;
      }

      rc = sp->next();
    }

    if (rc != RC::RECORD_EOF) {
      LOG_WARN("failed to update record: %s", strrc(rc));
      return rc;
    }
  }
  return RC::SUCCESS;
}

/**
 * expr->val to Value for further serialization
 * @param expr
 * @param value
 * @param field_meta
 * @return
 */
RC UpdateCommand::data_2_value(const hsql::Expr *expr, Value &value, const FieldMeta &field_meta) {
  RC rc = RC::SUCCESS;

  switch (expr->type) {
    case hsql::kExprLiteralInt: {
      value = Value(INT, static_cast<int32_t>(expr->ival));
      break;
    }
    case hsql::kExprLiteralFloat: {
      value = Value(FLOAT, static_cast<float>(expr->fval));
      break;
    }
    case hsql::kExprLiteralString: {
      // char and date
      void *dst = calloc(1, sizeof(int32_t[3]));
      if (Date::parse_date(dst, expr->name) != RC::SUCCESS) {
        free(dst);
        value = Value(CHAR, expr->name, field_meta.len());
      } else {
        value = Value(DATE, static_cast<const int32_t *>(dst));
      }
      break;
    }
    default: return RC::UNIMPLENMENT;
  }
  return rc;
}

RC UpdateCommand::check_schema(const FieldMeta& field_meta, const hsql::UpdateClause *updateClause)
{
  RC rc = RC::SUCCESS;
  hsql::Expr* expr = updateClause->value;
  switch (field_meta.type()) {
    case INT: {
      if (expr->type == hsql::kExprLiteralInt) return rc;
      break;
    }
    case FLOAT: {
      if (expr->type == hsql::kExprLiteralFloat) return rc;
      break;
    }
    case CHAR: {
      if (expr->type == hsql::kExprLiteralString) return rc;
      break;
    }
    case DATE: {
      if (expr->type == hsql::kExprLiteralString) return rc;
      break;
    }
    default: return RC::UNIMPLENMENT;
  }
  rc = RC::SCHEMA_FIELD_TYPE_MISMATCH;
  return rc;
}

