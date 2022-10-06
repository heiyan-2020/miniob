//
// Created by 37034 on 10/4/2022.
//

#ifndef MINIDB_PLANNER_H
#define MINIDB_PLANNER_H

#include "../plannodes/plan_node.h"
#include "../plannodes/table_scan_node.h"
#include "../plannodes/project_node.h"
#include "../parser/hsql/sql/SelectStatement.h"
#include "rc.h"
#include "storage/common/db.h"
#include "common/log/log.h"

class Planner {
public:
  Planner(Db *db) : db_(db)
  {}

  RC make_plan(hsql::SelectStatement *selStmt, std::shared_ptr<PlanNode> &plan);
  RC handleFromClause(hsql::TableRef *table, std::shared_ptr<PlanNode> &plan);
  RC handleWhereClause(hsql::SelectStatement *selStmt, std::shared_ptr<PlanNode> &plan);
  RC handleSelectClause(hsql::SelectStatement *selStmt, std::shared_ptr<PlanNode> &plan);

private:
  Db *db_;

  RC addPredicateToPlan(std::shared_ptr<PlanNode> &plan, hsql::Expr *predicate);
};

#endif  // MINIDB_PLANNER_H
