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
  std::vector<Column> cols{};
  for (auto col : *this->stmt_->columns) {
    ColumnName column_name{};
    TypeId type{};
    size_t length{};
    bool nullable{};
    const auto &col_type = col->type;
    switch (col_type.data_type) {
      case hsql::DataType::CHAR:
        type = TypeId::CHAR;
        length = col_type.length;
        column_name = ColumnName{col->name};
        nullable = col->nullable;
        break;
      case hsql::DataType::DATE:
        type = TypeId::DATE;
        length = Type::get_type_size(type);
        column_name = ColumnName{col->name};
        nullable = col->nullable;
        break;
      case hsql::DataType::FLOAT:
        type = TypeId::FLOAT;
        length = Type::get_type_size(type);
        column_name = ColumnName{col->name};
        nullable = col->nullable;
        break;
      case hsql::DataType::INT:
        type = TypeId::INT;
        length = Type::get_type_size(type);
        column_name = ColumnName{col->name};
        nullable = col->nullable;
        break;
      case hsql::DataType::TEXT:
        type = TypeId::CHAR;
        length = 4096;
        column_name = ColumnName{col->name};
        nullable = col->nullable;
        break;
      default:
        return RC::UNIMPLENMENT;
    }
    cols.emplace_back(column_name, type, length, false, nullable);
  }
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  RC rc = db->create_table(this->stmt_->tableName, Schema{cols});
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}

RC CreateCommand::do_create_index(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  Table *table = db->find_table(this->stmt_->tableName);
  if (nullptr == table) {
    session_event->set_response("FAILURE\n");
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  std::vector<std::string> attribute_names{};
  for (auto col : *this->stmt_->indexColumns) {
    attribute_names.emplace_back(col);
  }
  if (attribute_names.size() > MAX_ATTR_NUM) {
    return RC::GENERIC_ERROR;  // TODO(vgalaxy): currently support up to 4 multi index
  }

  RC rc = table->create_index(nullptr, this->stmt_->indexName, attribute_names, this->stmt_->isUnique);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}
