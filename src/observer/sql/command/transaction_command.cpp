#include "transaction_command.h"
#include "storage/trx/trx.h"
#include "session/session.h"
#include "storage/clog/clog.h"
#include "storage/common/db.h"

TransactionCommand::TransactionCommand(const hsql::TransactionStatement *stmt) : Command{hsql::kStmtTransaction}, stmt_{stmt}
{}

RC TransactionCommand::execute(const SQLStageEvent *sql_event)
{
  switch (stmt_->command) {
    case hsql::kBeginTransaction:
      return do_begin(sql_event);
    case hsql::kCommitTransaction:
      return do_commit(sql_event);
    case hsql::kRollbackTransaction:
      return do_rollback(sql_event);
    default:
      return RC::UNIMPLENMENT;
  }
}

RC TransactionCommand::do_begin(const SQLStageEvent *sql_event)
{
  RC rc;
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  session->set_trx_multi_operation_mode(true);

  CLogRecord *clog_record = nullptr;
  rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_BEGIN, trx->get_current_id(), clog_record);
  if (rc != RC::SUCCESS || clog_record == nullptr) {
    session_event->set_response("FAILURE\n");
    return rc;
  }

  rc = clog_manager->clog_append_record(clog_record);
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
  }

  return rc;
}

RC TransactionCommand::do_commit(const SQLStageEvent *sql_event)
{
  RC rc;
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  session->set_trx_multi_operation_mode(false);

  CLogRecord *clog_record = nullptr;
  rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
  if (rc != RC::SUCCESS || clog_record == nullptr) {
    session_event->set_response("FAILURE\n");
    return rc;
  }

  rc = clog_manager->clog_append_record(clog_record);
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
  }

  trx->next_current_id();

  return rc;
}

RC TransactionCommand::do_rollback(const SQLStageEvent *sql_event)
{
  auto session_event = sql_event->session_event();
  auto session = session_event->session();
  Trx *trx = session_event->get_client()->session->current_trx();
  RC rc = trx->rollback();
  session->set_trx_multi_operation_mode(false);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}

void end_trx_if_need(Session *session, Trx *trx, bool all_right)
{
  if (!session->is_trx_multi_operation_mode()) {
    if (all_right) {
      trx->commit();
    } else {
      trx->rollback();
    }
  }
}