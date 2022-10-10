//
// Created by 37034 on 10/4/2022.
//
#include "planner.h"
#include "util/date.h"
#include "binder.h"

RC Planner::handle_from_clause(const hsql::TableRef *table, std::shared_ptr<PlanNode> &plan)
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
      case hsql::TableRefType::kTableJoin:
      case hsql::TableRefType::kTableCrossProduct:
        break;
      default:
        break;
    }
  }
  return RC::SUCCESS;
}

RC Planner::handle_where_clause(const hsql::SelectStatement *sel_stmt, std::shared_ptr<PlanNode> &plan)
{
  hsql::Expr *predicate = sel_stmt->whereClause;
  RC rc = RC::SUCCESS;
  // TODO(zyx): find aggregates in expr.

  if (nullptr != predicate) {
    rc = add_predicate_to_plan(plan, predicate);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Add predicate onto plan tree failed.\n");
      return RC::GENERIC_ERROR;
    }
  }

  return RC::SUCCESS;
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
    scan_node->set_predicate(binder.bind_expression(predicate));
    return RC::SUCCESS;
  }
  return RC::UNIMPLENMENT;
  // TODO(zyx): Add filter node..
}

RC Planner::make_plan(const hsql::SelectStatement *sel_stmt, std::shared_ptr<PlanNode> &plan)
{
  RC rc;

  rc = handle_from_clause(sel_stmt->fromTable, plan);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to plan 'FROM' statement");
    return rc;
  }

  rc = handle_where_clause(sel_stmt, plan);
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
