#include "drop_command.h"
#include "storage/common/db.h"
#include "session/session.h"
#include "storage/common/table.h"

DropCommand::DropCommand(const hsql::DropStatement *stmt) : Command{hsql::kStmtDrop}, stmt_{stmt}
{}

RC DropCommand::execute(const SQLStageEvent *sql_event)
{
  switch (stmt_->type) {
    case hsql::kDropTable:
      return do_drop_table(sql_event);
    default:
      return RC::UNIMPLENMENT;
  }
}

RC DropCommand::do_drop_table(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  RC rc = db->drop_table(stmt_->name);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return RC::SUCCESS;
}