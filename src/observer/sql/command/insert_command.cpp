#include "insert_command.h"

InsertCommand::InsertCommand(const hsql::InsertStatement *stmt) : Command{hsql::kStmtInsert}, stmt_{stmt}
{}

RC InsertCommand::execute(const SQLStageEvent *sql_event)
{
  return RC::UNIMPLENMENT;
}
