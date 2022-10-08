#include "insert_command.h"
#include "storage/common/db.h"
#include "session/session.h"
#include "type/value.h"
#include "storage/common/table.h"


InsertCommand::InsertCommand(const hsql::InsertStatement *stmt) : Command{hsql::kStmtInsert}, stmt_{stmt}
{}

RC InsertCommand::execute(const SQLStageEvent *sql_event)
{
  switch (stmt_->type) {
    case hsql::kInsertValues:
      return do_insert_values(sql_event);
    default:
      return RC::UNIMPLENMENT;
  }
}

RC InsertCommand::do_insert_values(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  Table *table = db->find_table(stmt_->tableName);
  RC rc = RC::SUCCESS;
  if (nullptr == table) {
    LOG_ERROR("Can't find table: %s\n", stmt_->tableName);
    return RC::INVALID_ARGUMENT;
  }
  std::vector<Value> insert_values;
  // TODO(zyx): support insert multiple values.
  for (auto val_list :*stmt_->values) {
    insert_values.clear();
    for (auto expr : *val_list) {
      switch (expr->type) {
        case hsql::ExprType::kExprLiteralInt: {
          insert_values.push_back(Value(TypeId::INT, (int32_t) expr->ival));
          break ;
        }
          //TODO(zyx): support more data types.
        default: {
          LOG_ERROR("Unsupported data type: %d\n", expr->type);
          return RC::UNIMPLENMENT;
        }
      }
    }
    rc = table->insert_record(nullptr, insert_values);
    if (rc != RC::SUCCESS) {
      session_event->set_response("FAILURE");
      return rc;
    }
  }
  session_event->set_response("SUCCESS");
  return rc;
}
