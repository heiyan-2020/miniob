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

/**
 * update操作
 * （写完删）：目前只支持int
 * 只支持单字段set
 * @param sql_event
 * @return
 */
RC UpdateCommand::execute(const SQLStageEvent *sql_event)
{
//  return RC::UNIMPLENMENT;
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
    session_event->set_response("FAILURE");
    return rc;
  }
  sp->prepare();

  const TableMeta &table_meta = table->table_meta();
  const std::vector<FieldMeta> *field_metas = table_meta.field_metas();
  size_t curr_index = table_meta.sys_field_num();

  // 由于比赛只要求set单个字段，所以其实这里的for循环只会执行一次。
  for (auto updateClause: *stmt_->updates) {

    // find appropriate filed
    FieldMeta field_meta = field_metas->at(curr_index);
    while (field_meta.name() != updateClause->column) {
      curr_index++;
      field_meta = field_metas->at(curr_index);
      if (curr_index >= field_metas->size()) {
        LOG_WARN("update stmt offset has no related field");
        return RC::INTERNAL;
      }
    }

    while (RC::SUCCESS == sp->next()) {
      TupleRef tuple = sp->current_tuple();
      if (nullptr == tuple) {
        LOG_WARN("failed to get current record: %s", strrc(rc));
        return rc;
      }
      Record old_record = tuple->get_record();

      int record_size = table_meta.record_size();
      char *data = new char[record_size];
      memcpy(data, old_record.data(), record_size);
      const hsql::Expr *expr = updateClause->value;
      // TODO(pjz): 支持除INT外的其他类型
      auto* new_data = malloc(sizeof(expr->ival));
      memcpy(new_data, &expr->ival, sizeof(expr->ival));
      memcpy(data + field_meta.offset(), new_data, field_meta.len());
      Record new_record;
      new_record.set_rid(old_record.rid());
      new_record.set_data(data);

      // update record
      rc = table->update_record(nullptr, &old_record, &new_record);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to update record: %s", strrc(rc));
        return rc;
      }
    }
  }
  return RC::SUCCESS;
}
