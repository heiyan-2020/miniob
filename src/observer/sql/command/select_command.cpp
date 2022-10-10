#include "select_command.h"
#include "sql/binder/planner.h"
#include "storage/common/db.h"
#include "session/session.h"
#include "storage/common/table.h"
#include "sql/table/column.h"
#include "sql/binder/binder.h"

SelectCommand::SelectCommand(const hsql::SelectStatement *stmt) : Command{hsql::kStmtSelect}, stmt_{stmt}
{}

RC SelectCommand::execute(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();

  Binder binder(db);
  RC rc = binder.bind_select(stmt_);
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE");
    return rc;
  }
  Planner planner(db);
  std::shared_ptr<PlanNode> sp;
  rc = planner.make_plan(stmt_, sp);
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE");
    return rc;
  }
  rc = sp->prepare();
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE");
    return rc;
  }

  std::stringstream ss;
  print_header(ss, sp->get_schema());
  while ((rc = sp->next()) == RC::SUCCESS) {
    TupleRef tuple = sp->current_tuple();
    tuple_to_string(ss, *tuple, sp->get_schema());
    ss << std::endl;
  }
  if (rc != RC::RECORD_EOF) {
    session_event->set_response("FAILURE");
    return rc;
  }
  session_event->set_response(ss.str());
  return RC::SUCCESS;
}

void SelectCommand::print_header(std::ostream &os, SchemaRef schema)
{
  std::string header;
  bool first = true;
  bool table_name_visible = schema->table_name_visible();
  for (const auto &column : schema->get_columns()) {
    if (column.is_visible()) {
      if (!first) {
        header += " | ";
      }
      header += column.get_name().to_string(table_name_visible);
      first = false;
    }
  }
  if (schema->get_column_count() > 0)
    header += "\n";
  os << header;
}

void SelectCommand::tuple_to_string(std::ostream &os, const Tuple &tuple, SchemaRef schema)
{
  // Transforming result set into strings.
    std::string row;
    bool first = true;
    for (auto i = 0; i < schema->get_column_count(); i++) {
      const auto &column = schema->get_column(i);
      if (column.is_visible()) {
        if (!first) {
          row += " | ";
        }
        row += tuple.get_value(schema, i).to_string();
        first = false;
      }
    }
    os << row;
}