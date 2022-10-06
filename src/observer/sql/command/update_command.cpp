#include "update_command.h"

UpdateCommand::UpdateCommand(const hsql::UpdateStatement *stmt) : Command{hsql::kStmtUpdate}, stmt_{stmt}
{}

RC UpdateCommand::execute(const SQLStageEvent *sql_event)
{
  return RC::UNIMPLENMENT;
}
