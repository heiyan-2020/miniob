#include "create_command.h"
#include "command.h"
#include "storage/common/db.h"
#include "session/session.h"
#include "storage/index/bplus_tree.h"
#include "storage/common/table.h"

CreateCommand::CreateCommand(const hsql::CreateStatement *stmt) : Command{hsql::kStmtCreate}, stmt_{stmt}
{}

RC CreateCommand::execute(const SQLStageEvent *sql_event)
{
  switch (stmt_->type) {
    case hsql::kCreateTable:
      return do_create_table(sql_event);
    case hsql::kCreateIndex:
      return do_create_index(sql_event);
    default:
      return RC::UNIMPLENMENT;
  }
}

RC CreateCommand::do_create_table(const SQLStageEvent *sql_event)
{
  std::vector<AttrInfo> attr_infos{};
  for (auto col : *this->stmt_->columns) {
    AttrInfo attr_info{};
    const auto &col_type = col->type;
    switch (col_type.data_type) {
      case hsql::DataType::CHAR:
        attr_info.type = CHARS;
        attr_info.length = col_type.length;
        attr_info.name = col->name;
        break;
      case hsql::DataType::DATE:
        attr_info.type = DATES;
        attr_info.length = 12;
        attr_info.name = col->name;
        break;
      case hsql::DataType::FLOAT:
        attr_info.type = FLOATS;
        attr_info.length = 4;
        attr_info.name = col->name;
        break;
      case hsql::DataType::INT:
        attr_info.type = INTS;
        attr_info.length = 4;
        attr_info.name = col->name;
        break;
      case hsql::DataType::TEXT:
        attr_info.type = CHARS;
        attr_info.length = 4096;
        attr_info.name = col->name;
        break;
      default:
        return RC::UNIMPLENMENT;
    }
    attr_infos.emplace_back(attr_info);
  }
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  RC rc = db->create_table(this->stmt_->tableName, std::move(attr_infos));
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS");
  } else {
    session_event->set_response("FAILURE");
  }
  return rc;
}

RC CreateCommand::do_create_index(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  Table *table = db->find_table(this->stmt_->indexName);
  if (nullptr == table) {
    session_event->set_response("FAILURE");
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  std::vector<std::string> attribute_names{};
  for (auto col : *this->stmt_->indexColumns) {
    attribute_names.emplace_back(col);
  }
  if (attribute_names.size() > MAX_ATTR_NUM) {
    return RC::GENERIC_ERROR;  // TODO: support up to 4 multi index
  }

  RC rc = table->create_index(nullptr, this->stmt_->indexName, attribute_names, this->stmt_->isUnique);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS");
  } else {
    session_event->set_response("FAILURE");
  }
  return rc;
}
