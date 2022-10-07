#include "delete_command.h"

DeleteCommand::DeleteCommand(const hsql::DeleteStatement *stmt) : Command{hsql::kStmtDelete}, stmt_{stmt}
{}

RC DeleteCommand::execute(const SQLStageEvent *sql_event)
{
  return RC::UNIMPLENMENT;
}
