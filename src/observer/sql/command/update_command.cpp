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

    bool is_record_find = false;
    while (RC::SUCCESS == sp->next()) {
      if (!is_record_find) is_record_find = true;
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
      void *new_data = nullptr;
      rc = data_2_byte(expr, new_data);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to convert new record to byte code due to type constraint: %s", strrc(rc));
        return rc;
      }

      memcpy(data + field_meta.offset(), new_data, field_meta.len());
      Record new_record;
      new_record.set_rid(old_record.rid());
      new_record.set_data(data);

      rc = table->update_record(nullptr, &old_record, &new_record);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to update record: %s", strrc(rc));
        return rc;
      }
    }

    if (!is_record_find) return RC::RECORD_RECORD_NOT_EXIST;
  }
  return RC::SUCCESS;
}

/**
 * serialize expr->val to byte code
 * @param expr
 * @return
 */
RC UpdateCommand::data_2_byte(const hsql::Expr *expr, void* &new_data) {
  RC rc = RC::SUCCESS;
  // TODO(pjz): support text.
  switch (expr->type) {
    case hsql::kExprLiteralInt: {
      new_data = malloc(sizeof(expr->ival));
      memcpy(new_data, &expr->ival, sizeof(expr->ival));
      break;
    }
    case hsql::kExprLiteralFloat: {
      auto f = (float)expr->fval;
      new_data = malloc(sizeof(f));
      memcpy(new_data, &f, sizeof(f));
      break;
    }
    case hsql::kExprLiteralString: {
      // char and date
      void *dst = calloc(1, sizeof(int32_t[3]));
      if (Date::parse_date(dst, expr->name) != RC::SUCCESS) {
        free(dst);
        new_data = strdup(expr->name);
      } else {
        new_data = dst;
      }
      break;
    }
    default: return RC::UNIMPLENMENT;
  }
  return rc;
}