#include "select_command.h"
#include "sql/binder/planner.h"
#include "storage/common/db.h"
#include "session/session.h"
#include "storage/common/table.h"
#include "sql/table/column.h"

SelectCommand::SelectCommand(const hsql::SelectStatement *stmt) : Command{hsql::kStmtSelect}, stmt_{stmt}
{}

RC SelectCommand::execute(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();

  Planner planner(db);
  std::shared_ptr<PlanNode> sp;
  planner.make_plan(stmt_, sp);
  sp->prepare();

  std::stringstream ss;

  std::string header;
  for (const auto &column : sp->get_schema()->get_columns()) {
    header += column.get_name().to_string();
    header += "\t";
  }
  ss << header << std::endl;

  while (RC::SUCCESS == sp->next()) {
    TupleRef tuple = sp->current_tuple();
    tuple_to_string(ss, *tuple, sp->get_schema());
    ss << std::endl;
  }
  session_event->set_response(ss.str());
  return RC::SUCCESS;
}

void SelectCommand::tuple_to_string(std::ostream &os, const Tuple &tuple, SchemaRef schema)
{
  // Transforming result set into strings.
    std::string row;
    for (auto i = 0; i < schema->get_column_count(); i++) {
      row += tuple.get_value(schema, i).to_string();
      row += "\t";
    }
    os << row;
}