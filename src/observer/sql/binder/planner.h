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

private:
  RC add_predicate_to_plan(std::shared_ptr<PlanNode> &plan, hsql::Expr *predicate);

  AbstractExpressionRef bind_expression(hsql::Expr *expr);

  ComparisonType bind_operator(hsql::OperatorType opt)
  {
    const struct info {
      hsql::OperatorType opt;
      ComparisonType ct;
    } infos[] = {
        {hsql::OperatorType::kOpEquals, ComparisonType::Equal},
        {hsql::OperatorType::kOpGreater, ComparisonType::GreaterThan},
        {hsql::OperatorType::kOpGreaterEq, ComparisonType::GreaterThanOrEqual},
        {hsql::OperatorType::kOpNotEquals, ComparisonType::NotEqual},
        {hsql::OperatorType::kOpLess, ComparisonType::LessThan},
        {hsql::OperatorType::kOpLessEq, ComparisonType::LessThanOrEqual},
    };
    for (size_t idx = 0; idx < sizeof infos / sizeof infos[0]; idx++) {
      if (infos[idx].opt == opt) {
        return infos[idx].ct;
      }
    }
    LOG_ERROR("Bind operator type failed");
    assert(false);
    return ComparisonType::LessThanOrEqual; // dummy return value, because program will halt before.
  }
};

#endif  // MINIDB_PLANNER_H
