#include "select_command.h"
#include "sql/binder/planner.h"
#include "storage/common/db.h"
#include "session/session.h"
#include "storage/common/table.h"
#include "sql/operator/project_operator.h"

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
  while (RC::SUCCESS == sp->next()) {
    Tuple *tuple = sp->current_tuple();
    tuple_to_string(ss, *tuple);
    ss << std::endl;
  }
  session_event->set_response(ss.str());
  return RC::SUCCESS;
}

void SelectCommand::tuple_to_string(std::ostream &os, const Tuple &tuple)
{
  TupleCell cell;
  RC rc;
  bool first_field = true;
  for (int i = 0; i < tuple.cell_num(); i++) {
    rc = tuple.cell_at(i, cell);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to fetch field of cell, index = %d, rc = %s", i, strrc(rc));
      break;
    }

    if (!first_field) {
      os << " | ";
    } else {
      first_field = false;
    }
    cell.to_string(os);
  }
}