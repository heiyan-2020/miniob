//
// Created by 37034 on 10/4/2022.
//
#include "planner.h"
#include "util/date.h"
#include "binder.h"

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

      }
      case hsql::TableRefType::kTableCrossProduct:
        // TODO(zyx): select multiple tables.
        break;
      default:
        break;
    }
  }
  return RC::SUCCESS;
}

RC Planner::handle_where_clause(hsql::Expr *predicate, std::shared_ptr<PlanNode> &plan)
{
  RC rc = RC::SUCCESS;
  // TODO(zyx): find aggregates in expr.

  // update's where clause only have AND case.
  if (nullptr != predicate) {
    rc = add_predicate_to_plan(plan, predicate);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Add predicate onto plan tree failed.\n");
      return RC::GENERIC_ERROR;
    }
  }
  return rc;
}

RC Planner::handle_select_clause(const hsql::SelectStatement *sel_stmt, std::shared_ptr<PlanNode> &plan)
{
  if (!plan) {
    LOG_ERROR("Not supported select values yet.\n");
    return RC::UNIMPLENMENT;
    // TODO(zyx): Support query without from tables.
  }
  std::vector<AbstractExpressionRef> projection_spec;
  // TODO(zyx): Bind select values before construct project node.
  plan = std::make_shared<ProjectNode>(plan, *sel_stmt->selectList);
  return RC::SUCCESS;
}

RC Planner::add_predicate_to_plan(std::shared_ptr<PlanNode> &plan, hsql::Expr *predicate)
{
  std::shared_ptr<TableScanNode> scan_node = std::dynamic_pointer_cast<TableScanNode>(plan);
  Binder binder(db_);
  if (scan_node) {
    if (scan_node->get_predicate() != nullptr) {
      LOG_ERROR("Scan node shouldn't have predicate now.");
      return RC::GENERIC_ERROR;
    }
    AbstractExpressionRef expr;
    if (binder.bind_expression(predicate, expr) != RC::SUCCESS) {
      return RC::INTERNAL;
    }
    scan_node->set_predicate(expr);
    return RC::SUCCESS;
  }
  return RC::UNIMPLENMENT;
  // TODO(zyx): Add filter node..
}

RC Planner::make_plan_sel(const hsql::SelectStatement *sel_stmt, std::shared_ptr<PlanNode> &plan)
{
  RC rc;

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
