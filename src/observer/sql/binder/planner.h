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
#include "sql/expr/abstract_expression.h"
#include "sql/expr/column_value_expression.h"
#include "sql/expr/comparison_expression.h"
#include "sql/expr/constant_value_expression.h"
#include "sql/parser/hsql/sql/UpdateStatement.h"
#include "sql/parser/hsql/sql/DeleteStatement.h"

class Planner {
public:
  explicit Planner(Db *db) : db_(db)
  {}

  RC make_plan_sel(const hsql::SelectStatement *sel_stmt, std::shared_ptr<PlanNode> &plan);
  RC make_plan_upd(const hsql::UpdateStatement *upd_stmt, std::shared_ptr<PlanNode> &plan);
  RC make_plan_del(const hsql::DeleteStatement *del_stmt, std::shared_ptr<PlanNode> &plan);
  RC handle_table_name_clause(const hsql::TableRef *table, std::shared_ptr<PlanNode> &plan);
  RC handle_where_clause(hsql::Expr *predicate, std::shared_ptr<PlanNode> &plan);
  RC handle_select_clause(const hsql::SelectStatement *sel_stmt, std::shared_ptr<PlanNode> &plan);

private:
  Db *db_;

private:
  RC add_predicate_to_plan(std::shared_ptr<PlanNode> &plan, hsql::Expr *predicate);

};

#endif  // MINIDB_PLANNER_H
