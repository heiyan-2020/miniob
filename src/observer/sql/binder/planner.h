//
// Created by 37034 on 10/4/2022.
//

#ifndef MINIDB_PLANNER_H
#define MINIDB_PLANNER_H

#include "sql/plan_node/plan_node.h"
#include "sql/plan_node/table_scan_node.h"
#include "sql/plan_node/project_node.h"
#include "sql/parser/hsql/sql/SelectStatement.h"
#include "rc.h"
#include "storage/common/db.h"
#include "common/log/log.h"

class Planner {
public:
  explicit Planner(Db *db) : db_(db)
  {}

  RC make_plan(const hsql::SelectStatement *sel_stmt, std::shared_ptr<PlanNode> &plan);
  RC handle_from_clause(const hsql::TableRef *table, std::shared_ptr<PlanNode> &plan);
  RC handle_where_clause(const hsql::SelectStatement *sel_stmt, std::shared_ptr<PlanNode> &plan);
  RC handle_select_clause(const hsql::SelectStatement *sel_stmt, std::shared_ptr<PlanNode> &plan);

private:
  Db *db_;

  RC add_predicate_to_plan(std::shared_ptr<PlanNode> &plan, hsql::Expr *predicate);
};

#endif  // MINIDB_PLANNER_H
