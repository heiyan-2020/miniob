#include "delete_command.h"
#include "storage/common/db.h"
#include "session/session.h"
#include "type/value.h"
#include "storage/common/table.h"
#include "util/date.h"

DeleteCommand::DeleteCommand(const hsql::DeleteStatement *stmt) : Command{hsql::kStmtDelete}, stmt_{stmt}
{}

RC DeleteCommand::execute(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();

  Table *table = db->find_table(stmt_->tableName);
  return RC::UNIMPLENMENT;
}
