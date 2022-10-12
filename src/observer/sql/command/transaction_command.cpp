#include "transaction_command.h"
#include "storage/trx/trx.h"
#include "session/session.h"

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
  sql_event->session_event()->set_response("SUCCESS\n");
  return RC::SUCCESS;
}

RC TransactionCommand::do_commit(const SQLStageEvent *sql_event)
{
  auto session_event = sql_event->session_event();
  auto session = session_event->session();
  Trx *trx = session->current_trx();
  RC rc = trx->commit();
  session->set_trx_multi_operation_mode(false);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
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