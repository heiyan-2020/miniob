//
// Created by 37034 on 10/4/2022.
//

#ifndef MINIDB_PLANNER_H
#define MINIDB_PLANNER_H

#include <utility>

#include "sql/plan_node/plan_node.h"
#include "sql/plan_node/filter_node.h"
#include "sql/plan_node/project_node.h"
#include "sql/plan_node/table_scan_node.h"
#include "sql/plan_node/nested_loop_join_node.h"
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
#include "binder.h"

class ExpressionPlanner;
class SelectCommand;

class Planner {
  friend class Binder;
  friend class ExpressionPlanner;
  friend class SelectCommand;
public:
  explicit Planner(Db *db, std::vector<SchemaRef> enclosing_schemas = {}) : db_(db), binder_(db, enclosing_schemas)
  {}

  RC make_plan_sel(const hsql::SelectStatement *sel_stmt, std::shared_ptr<PlanNode> &plan);
  RC make_plan_upd(const hsql::UpdateStatement *upd_stmt, std::shared_ptr<PlanNode> &plan);
  RC make_plan_del(const hsql::DeleteStatement *del_stmt, std::shared_ptr<PlanNode> &plan);

  RC handle_table_name_clause(const hsql::TableRef *table, std::shared_ptr<PlanNode> &plan);
  RC handle_where_clause(hsql::Expr *predicate, std::shared_ptr<PlanNode> &plan);
  RC handle_select_clause(const hsql::SelectStatement *sel_stmt, std::shared_ptr<PlanNode> &plan);
  RC handle_grouping_and_aggregation(const hsql::SelectStatement *sel_stmt, std::shared_ptr<PlanNode> &plan);
  RC handle_join(const hsql::TableRef *from, std::unordered_set<AbstractExpressionRef> &extra_conjuncts);

private:
  Db *db_;
  Binder binder_;

private:
  RC add_predicate_to_plan(std::shared_ptr<PlanNode> &plan, AbstractExpressionRef pred);

  // collect all leaf tables(base_table, subquery) and all predicates coming up in ON clause.
  RC collect_details(const hsql::TableRef *from, std::unordered_set<AbstractExpressionRef> &conjuncts, std::vector<const hsql::TableRef *> &leaf_clauses);

  RC generate_leaf_plans(std::vector<const hsql::TableRef *> &leaf_clauses, std::unordered_set<AbstractExpressionRef>);

  RC make_leaf_plan(const hsql::TableRef *from, std::unordered_set<AbstractExpressionRef> &conjuncts);

  RC push_conjunct_down(PlanNodeRef plan, std::unordered_set<AbstractExpressionRef> &conjuncts);
};

#endif  // MINIDB_PLANNER_H
