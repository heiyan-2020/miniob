#include "delete_command.h"
#include "storage/common/db.h"
#include "sql/binder/planner.h"
#include "session/session.h"
#include "type/value.h"
#include "storage/common/table.h"
#include "util/date.h"
#include "storage/clog/clog.h"
#include "storage/trx/trx.h"

DeleteCommand::DeleteCommand(const hsql::DeleteStatement *stmt) : Command{hsql::kStmtDelete}, stmt_{stmt}
{}

RC DeleteCommand::execute(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  RC rc = do_delete(sql_event);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}

RC DeleteCommand::do_delete(const SQLStageEvent *sql_event)
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

  Planner planner(db);
  std::shared_ptr<PlanNode> sp;
  rc = planner.make_plan_del(stmt_, sp);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  sp->prepare();
  sp->initialize();

  rc = sp->next();
  while (RC::SUCCESS == rc) {
    TupleRef tuple;
    rc = sp->current_tuple(tuple);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get current record: %s", strrc(rc));
      return rc;
    }

    Record record = tuple->get_record();
    rc = table->delete_record(trx, &record);

    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to delete record: %s", strrc(rc));
      return rc;
    }

    rc = sp->next();
  }

  if (rc != RC::RECORD_EOF) {
    LOG_WARN("failed to delete record: %s", strrc(rc));
    return rc;
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

  return RC::SUCCESS;
}
