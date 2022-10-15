//
// Created by 37034 on 10/4/2022.
//
#include "planner.h"
#include "util/date.h"
#include "binder.h"
#include "sql/expr/aggregation_processor.h"
#include "sql/plan_node/group_aggregate_node.h"
#include "sql/plan_node/project_node.h"
#include "sql/expr/expression_planner.h"
#include "util/predicate_utils.h"
#include "util/macros.h"

RC Planner::handle_table_name_clause(const hsql::TableRef *table, std::shared_ptr<PlanNode> &plan)
{
  if (table != nullptr) {
    switch (table->type) {
      case hsql::TableRefType::kTableName: {
        const char *table_name = table->getName();
        if (nullptr == table_name) {
          return RC::INVALID_ARGUMENT;
        }
        Table *tp = db_->find_table(table_name);
        if (!tp) {
          return RC::SCHEMA_TABLE_NOT_EXIST;
        }
        plan = std::make_shared<TableScanNode>(tp, nullptr);
        break;
      }
      case hsql::TableRefType::kTableSelect:
        // TODO(zyx): subquery in from clause.
        break;
      case hsql::TableRefType::kTableJoin: {
        PlanNodeRef left_child, right_child;
        const hsql::JoinDefinition *join_def = table->join;
        RC rc = handle_table_name_clause(join_def->left, left_child);
        if (rc != RC::SUCCESS) {
          return rc;
        }
        rc = handle_table_name_clause(join_def->right, right_child);
        if (rc != RC::SUCCESS) {
          return rc;
        }
        AbstractExpressionRef join_cond;
        rc = binder_.bind_expression(join_def->condition, join_cond);
        if (rc != RC::SUCCESS) {
          return rc;
        }
        plan = std::make_shared<NestedLoopJoinNode>(left_child, right_child, join_cond);
        break;
      }
      case hsql::TableRefType::kTableCrossProduct: {
        PlanNodeRef left, right, result;
        RC rc = handle_table_name_clause((*table->list)[0], left);
        if (rc != RC::SUCCESS) {
          return rc;
        }
        rc = handle_table_name_clause((*table->list)[1], right);
        if (rc != RC::SUCCESS) {
          return rc;
        }
        result = std::make_shared<NestedLoopJoinNode>(left, right);
        for (size_t idx = 2; idx < table->list->size(); idx ++) {
          right.reset();
          rc = handle_table_name_clause((*table->list)[idx], right);
          if (rc != RC::SUCCESS) {
            return rc;
          }
          result = std::make_shared<NestedLoopJoinNode>(result, right);
        }
        plan = result;
        break;
      }
      default:
        break;
    }
  }
  return RC::SUCCESS;
}

RC Planner::handle_where_clause(hsql::Expr *predicate, std::shared_ptr<PlanNode> &plan)
{
  RC rc = RC::SUCCESS;

  // update's where clause only has AND case.
  binder_.enclosing_.push_back(binder_.from_schema_);
  std::shared_ptr<ExpressionPlanner> expression_planner = std::make_shared<ExpressionPlanner>(Planner(db_, binder_.enclosing_));
  if (nullptr != predicate) {
    // add predicate
    AbstractExpressionRef expr;
    if (binder_.bind_expression(predicate, expr) != RC::SUCCESS) {
      return RC::INTERNAL;
    }
    rc = add_predicate_to_plan(plan, expr);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Add predicate onto plan tree failed.");
      return RC::GENERIC_ERROR;
    }

    // find all sub queries.
    expr->traverse(expression_planner);
  }

  if (expression_planner->has_subquery()) {
    plan->set_env(expression_planner->get_env());
    rc = expression_planner->prepare_all();
  }

  return rc;
}

RC Planner::handle_select_clause(const hsql::SelectStatement *sel_stmt, std::shared_ptr<PlanNode> &plan)
{
  if (!plan) {
    LOG_ERROR("Not supported select values yet.");
    return RC::UNIMPLENMENT;
    // TODO(zyx): Support query without from tables.
  }
  plan = std::make_shared<ProjectNode>(plan, binder_.select_values_);
  return RC::SUCCESS;
}

RC Planner::handle_grouping_and_aggregation(const hsql::SelectStatement *sel_stmt, std::shared_ptr<PlanNode> &plan)
{
  std::shared_ptr<AggregationProcessor> aggregation_processor = std::make_shared<AggregationProcessor>();
  for (const auto &expr : binder_.select_values_) {
    expr->traverse(aggregation_processor);
  }
  auto aggregates = aggregation_processor->get_aggregates();
  if (aggregates.empty()) {
    if (sel_stmt->groupBy) {
      LOG_ERROR("Group by without aggregation.");
      return RC::GENERIC_ERROR;
    }
    return RC::SUCCESS;
  }
  plan = std::make_shared<GroupAggregateNode>(plan, binder_.group_by_exprs_, aggregates);
  return RC::SUCCESS;
}

RC Planner::add_predicate_to_plan(std::shared_ptr<PlanNode> &plan, AbstractExpressionRef expr)
{
  std::shared_ptr<TableScanNode> scan_node = std::dynamic_pointer_cast<TableScanNode>(plan);
  if (scan_node) {
    if (scan_node->get_predicate() != nullptr) {
      LOG_ERROR("Scan node shouldn't have predicate now.");
      return RC::GENERIC_ERROR;
    }
    scan_node->set_predicate(expr);
    return RC::SUCCESS;
  } else {
    plan = std::make_shared<FilterNode>(plan, expr);
    return RC::SUCCESS;
  }
}

RC Planner::handle_join(const hsql::TableRef *from, std::unordered_set<AbstractExpressionRef> &extra_conjuncts)
{
  RC rc;
  std::unordered_set<AbstractExpressionRef> conjuncts;
  std::vector<const hsql::TableRef *> leaf_forms;

  rc = collect_details(from, conjuncts, leaf_forms);
  HANDLE_EXCEPTION(rc, "Collect details error");

  if (!extra_conjuncts.empty())
    conjuncts.insert(extra_conjuncts.begin(), extra_conjuncts.end());




}

RC Planner::collect_details(const hsql::TableRef *from, std::unordered_set<AbstractExpressionRef> &conjuncts, std::vector<const hsql::TableRef *> &leaf_clauses)
{
  RC rc;
  switch (from->type) {
    case hsql::TableRefType::kTableName:
    case hsql::kTableSelect: {
      leaf_clauses.push_back(from);
      rc = RC::SUCCESS;
      break;
    }
    case hsql::kTableJoin: {
      if (from->join->type != hsql::JoinType::kJoinInner) {
        LOG_PANIC("Doesn't support outer join yet.");
        return RC::UNIMPLENMENT;
      }
      rc = collect_details(from->join->left, conjuncts, leaf_clauses);
      HANDLE_EXCEPTION(rc, "Collect details failed");

      rc = collect_details(from->join->right, conjuncts, leaf_clauses);
      HANDLE_EXCEPTION(rc, "Collect details failed");

      AbstractExpressionRef join_cond;
      rc = binder_.bind_expression(from->join->condition, join_cond);
      HANDLE_EXCEPTION(rc, "Collect details failed");

      PredicateUtils::collect_conjuncts(join_cond, conjuncts);
      break;
    }
    case hsql::kTableCrossProduct: {
      for (const auto &table : *from->list) {
        leaf_clauses.push_back(table);
      }
      break;
    }
    default: {
      LOG_PANIC("Unsupported from type");
      return RC::UNIMPLENMENT;
    }
  }
  return rc;
}

RC Planner::make_leaf_plan(const hsql::TableRef *from, std::unordered_set<AbstractExpressionRef> &conjuncts)
{

}

RC Planner::generate_leaf_plans(std::vector<const hsql::TableRef *> &leaf_clauses, std::unordered_set<AbstractExpressionRef>)
{

}

RC Planner::make_plan_sel(const hsql::SelectStatement *sel_stmt, std::shared_ptr<PlanNode> &plan)
{
  RC rc;

  rc = binder_.bind_select(sel_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("Bind failed");
    return rc;
  }

  // here represents 'handle_from_clause()'
  rc = handle_table_name_clause(sel_stmt->fromTable, plan);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to plan 'FROM' statement");
    return rc;
  }

  rc = handle_where_clause(sel_stmt->whereClause, plan);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to plan 'WHERE' statement");
    return rc;
  }

  rc = handle_grouping_and_aggregation(sel_stmt, plan);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to plan grouping and aggregation");
    return rc;
  }

  rc = handle_select_clause(sel_stmt, plan);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to plan 'SELECT' statement");
    return rc;
  }

  return rc;
}

RC Planner::make_plan_upd(const hsql::UpdateStatement *upd_stmt, std::shared_ptr<PlanNode> &plan)
{
  RC rc;

  // tableScanNode
  rc = handle_table_name_clause(upd_stmt->table, plan);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to plan 'FROM' statement");
    return rc;
  }

  // predNode
  rc = handle_where_clause(upd_stmt->where, plan);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to plan 'WHERE' statement");
    return rc;
  }

  return rc;
}

RC Planner::make_plan_del(const hsql::DeleteStatement *del_stmt, std::shared_ptr<PlanNode> &plan)
{
  RC rc;

  // tableScanNode
  const char *table_name = del_stmt->tableName;
  if (nullptr == table_name) {
    rc = RC::INVALID_ARGUMENT;
    LOG_WARN("failed to plan 'FROM' statement");
    return rc;
  }
  Table *tp = db_->find_table(table_name);
  if (!tp) {
    rc = RC::SCHEMA_TABLE_NOT_EXIST;
    LOG_WARN("failed to plan 'FROM' statement");
    return rc;
  }
  plan = std::make_shared<TableScanNode>(tp, nullptr);

  // predNode
  rc = handle_where_clause(del_stmt->expr, plan);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to plan 'WHERE' statement");
    return rc;
  }

  return rc;
}
