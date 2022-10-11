#include "delete_command.h"
#include "storage/common/db.h"
#include "sql/binder/planner.h"
#include "session/session.h"
#include "type/value.h"
#include "storage/common/table.h"
#include "util/date.h"

DeleteCommand::DeleteCommand(const hsql::DeleteStatement *stmt) : Command{hsql::kStmtDelete}, stmt_{stmt}
{}

/**
 * delete操作
 * （写完删）：目前跑不通，待改写planner
 * （写完删）：没找到官方测试用例
 * 支持where（待改写planner）
 * @param sql_event
 * @return
 */
RC DeleteCommand::execute(const SQLStageEvent *sql_event)
{
  return RC::UNIMPLENMENT;
  SessionEvent *session_event = sql_event->session_event();
  RC rc = do_delete(sql_event);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS");
  } else {
    session_event->set_response("FAILURE");
  }
  return rc;
}

RC DeleteCommand::do_delete(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();

  Table *table = db->find_table(stmt_->tableName);
  RC rc = RC::SUCCESS;
  if (nullptr == table) {
    LOG_ERROR("Can't find table: %s", stmt_->tableName);
    return RC::INVALID_ARGUMENT;
  }

  Planner planner(db);
  std::shared_ptr<PlanNode> sp;
  // TODO(pjz): make update planner
  // rc = planner.make_plan(stmt_, sp);
  //  if (rc != RC::SUCCESS) {
  //    session_event->set_response("FAILURE");
  //    return rc;
  //  }
  sp->prepare();

  const TableMeta &table_meta = table->table_meta();
  const std::vector<FieldMeta> *field_metas = table_meta.field_metas();

  TupleRef tuple;
  while (RC::SUCCESS == sp->next()) {
    rc = sp->current_tuple(tuple);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get current record: %s", strrc(rc));
      return rc;
    }

    Record record = tuple->get_record();
    rc = table->delete_record(nullptr, &record);

    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to delete record: %s", strrc(rc));
      return rc;
    }
  }

  return RC::SUCCESS;
}
