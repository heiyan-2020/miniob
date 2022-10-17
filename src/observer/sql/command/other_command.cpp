#include "other_command.h"
#include "storage/default/default_handler.h"

OtherCommand::OtherCommand(const hsql::OtherStatement *stmt) : Command{hsql::kStmtOther}, stmt_{stmt}
{}

RC OtherCommand::execute(const SQLStageEvent *sql_event)
{
  switch (stmt_->command) {
    case hsql::kHelp:
      return do_help(sql_event);
    case hsql::kSync:
      return do_sync(sql_event);
    default:
      return RC::UNIMPLENMENT;
  }
}

RC OtherCommand::do_help(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  const char *response = "show tables;\n"
                         "desc `table name`;\n"
                         "create table `table name` (`column name` `column type`, ...);\n"
                         "create index `index name` on `table` (`column`);\n"
                         "insert into `table` values(`value1`,`value2`);\n"
                         "update `table` set column=value [where `column`=`value`];\n"
                         "delete from `table` [where `column`=`value`];\n"
                         "select [ * | `columns` ] from `table`;\n";
  session_event->set_response(response);
  return RC::SUCCESS;
}

RC OtherCommand::do_sync(const SQLStageEvent *sql_event)
{
  auto session_event = sql_event->session_event();
  RC rc = DefaultHandler::get_default().sync();
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}
