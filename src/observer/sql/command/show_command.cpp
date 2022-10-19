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
    case hsql::kShowIndex:
      return do_show_index(sql_event);
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
    session_event->set_response("No table\n");
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

RC ShowCommand::do_show_index(const SQLStageEvent *sql_event)
{
  Db *db = sql_event->session_event()->session()->get_current_db();
  const char *table_name = stmt_->name;
  Table *table = db->find_table(table_name);
  std::stringstream ss;

  if (table != nullptr) {
    std::vector<Index *> indexes = table->get_indexes();
    for (auto* index: indexes) {
      index_2_string(table_name, ss, index);
    }
    ss << "TABLE | NON_UNIQUE | KEY_NAME | SEQ_IN_INDEX | COLUMN_NAME" << std::endl;
  } else {
    ss << "FAILURE\n";
  }

  sql_event->session_event()->set_response(ss.str());
  return RC::SUCCESS;
}

void ShowCommand::index_2_string(const char* table_name, std::ostream &os, const Index *index)
{
  int count = 1;
  for (const auto& filed_name: index->index_meta().fields()) {
    index_info_prefix(table_name, os, index->index_meta());
    os << count << " | " << filed_name << std::endl;
    count++;
  }
}

void ShowCommand::index_info_prefix(const char *table_name, std::ostream &os, const IndexMeta &index_meta)
{
  os << table_name << " | ";
  // 唯一索引输出0？非唯一输出1？
  if (index_meta.is_unique()) {
    os << "0 | ";
  }
  else {
    os << "1 | ";
  }
  os << index_meta.name() << " | ";
}

