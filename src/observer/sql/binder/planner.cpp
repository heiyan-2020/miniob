//
// Created by 37034 on 10/4/2022.
//
#include "planner.h"

RC Planner::handleFromClause(hsql::TableRef *table, std::shared_ptr<PlanNode> &plan)
{
  if (table != nullptr) {
    switch (table->type) {
      case hsql::TableRefType::kTableName: {
        const char *table_name = table->getName();
        if (nullptr == table_name) {
          LOG_WARN("invalid argument. relation name is null.");
          return RC::INVALID_ARGUMENT;
        }
        Table *tp = db_->find_table(table_name);
        if (!tp) {
          LOG_WARN("no such table. db=%s, table_name=%s", db_->name(), table->getName());
          return RC::SCHEMA_TABLE_NOT_EXIST;
        }
        plan = std::make_shared<TableScanNode>(tp, nullptr);
        break;
      }
      case hsql::TableRefType::kTableSelect:
        break;
      case hsql::TableRefType::kTableJoin:
      case hsql::TableRefType::kTableCrossProduct:
        break;
      default:
        break;
    }
  }
  return RC::SUCCESS;
}

RC Planner::handleWhereClause(hsql::SelectStatement *selStmt, std::shared_ptr<PlanNode> &plan)
{
  hsql::Expr *predicate = selStmt->whereClause;
  RC rc = RC::SUCCESS;
  // TODO(zyx): find aggregates in expr.

  if (nullptr != predicate) {
    rc = addPredicateToPlan(plan, predicate);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Add predicate onto plan tree failed.\n");
      return RC::GENERIC_ERROR;
    }
  }

  return RC::SUCCESS;
}

RC Planner::handleSelectClause(hsql::SelectStatement *selStmt, std::shared_ptr<PlanNode> &plan)
{
  if (!plan) {
    LOG_ERROR("Not supported select values yet.\n");
    return RC::UNIMPLENMENT;
    // TODO(zyx): Support query without from tables.
  }
  plan = std::make_shared<ProjectNode>(plan, *selStmt->selectList);
  return RC::SUCCESS;
}

RC Planner::addPredicateToPlan(std::shared_ptr<PlanNode> &plan, hsql::Expr *predicate)
{
  std::shared_ptr<TableScanNode> scan_node = std::dynamic_pointer_cast<TableScanNode>(plan);
  if (scan_node) {
    if (scan_node->getPredicate() != nullptr) {
      LOG_ERROR("Scan node shouldn't have predicate now.");
      return RC::GENERIC_ERROR;
    }
    scan_node->setPredicate(predicate);
    return RC::SUCCESS;
  }
  return RC::UNIMPLENMENT;
  // TODO(zyx): Add filter node..
}

RC Planner::make_plan(hsql::SelectStatement *selStmt, std::shared_ptr<PlanNode> &plan)
{
  RC rc = RC::SUCCESS;

  rc = handleFromClause(selStmt->fromTable, plan);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to plan 'FROM' statement");
    return rc;
  }

  rc = handleWhereClause(selStmt, plan);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to plan 'WHERE' statement");
    return rc;
  }

  rc = handleSelectClause(selStmt, plan);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to plan 'SELECT' statement");
    return rc;
  }

  return rc;
}
