#include "show_command.h"
#include "storage/common/db.h"
#include "session/session.h"
#include "storage/common/table.h"

#include <sstream>

ShowCommand::ShowCommand(const hsql::ShowStatement *stmt) : Command{hsql::kStmtShow}, stmt_{stmt}
{}

RC ShowCommand::execute(const SQLStageEvent *sql_event)
{
  switch (stmt_->type) {
    case hsql::kShowTables:
      return do_show_tables(sql_event);
    case hsql::kShowColumns:
      return do_desc_table(sql_event);
    default:
      return RC::UNIMPLENMENT;
  }
}

RC ShowCommand::do_show_tables(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  std::vector<std::string> all_tables;
  db->all_tables(all_tables);
  if (all_tables.empty()) {
    session_event->set_response("No table");
  } else {
    std::stringstream ss;
    for (const auto &table : all_tables) {
      ss << table << std::endl;
    }
    session_event->set_response(ss.str());
  }
  return RC::SUCCESS;
}

RC ShowCommand::do_desc_table(const SQLStageEvent *sql_event)
{
  Db *db = sql_event->session_event()->session()->get_current_db();
  const char *table_name = stmt_->name;
  Table *table = db->find_table(table_name);
  std::stringstream ss;
  if (table != nullptr) {
    table->table_meta().desc(ss);
  } else {
    ss << "No such table: " << table_name << std::endl;
  }
  sql_event->session_event()->set_response(ss.str());
  return RC::SUCCESS;
}