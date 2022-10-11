//
// Created by 37034 on 10/5/2022.
//
#include "project_node.h"

#include <utility>
#include "common/log/log.h"

RC ProjectNode::prepare()
{
  RC rc = RC::SUCCESS;
  if (left_child_) {
    left_child_->prepare();
    rc = prepareSchema(left_child_->get_schema());
  } else {
    LOG_WARN("Not implemented!");
  }
  return rc;
}

RC ProjectNode::next()
{
  if (left_child_) {
    return left_child_->next();
  }
  LOG_WARN("Project node should have a child.");
  return RC::GENERIC_ERROR;
}

RC ProjectNode::current_tuple(TupleRef &tuple)
{
  RC rc;
  rc = left_child_->current_tuple(current_);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  rc = project_tuple(current_, tuple);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  return RC::SUCCESS;
}

RC ProjectNode::prepareSchema(SchemaRef input_schema)
{
  std::vector<Column> columns;
  std::vector<Column> tmp;

  for (hsql::Expr *expr : projection_spec_) {
    if (expr->type == hsql::kExprStar) {
      if (expr->hasTable()) {
        tmp = input_schema->find_columns(expr->table, {});
        columns.insert(columns.end(), tmp.begin(), tmp.end());
      } else {
        tmp = input_schema->find_columns({}, {});
        columns.insert(columns.end(), tmp.begin(), tmp.end());
      }
    } else if (expr->type == hsql::kExprColumnRef) {
      std::string table_name;
      if (expr->table != nullptr)
        table_name = expr->table;
      tmp = input_schema->find_columns(table_name, expr->getName());
      if (tmp.size() != 1) {
        return RC::INTERNAL;
      }
      if (expr->hasAlias()) {
        tmp[0].set_alias(expr->alias);
      }
      columns.insert(columns.end(), tmp.begin(), tmp.end());
    } else {
      return RC::INTERNAL;
      LOG_WARN("select raw value not supported.");
    }
  }
  output_schema_ = std::make_shared<Schema>(columns);
  return RC::SUCCESS;
}

RC ProjectNode::project_tuple(TupleRef original_tuple, TupleRef &out_tuple)
{
  SchemaRef input_schema = left_child_->get_schema();
  std::vector<Value> project_values;
  for (size_t i = 0; i < output_schema_->get_column_count(); i++) {
    const auto &out_col = output_schema_->get_column(i);
    size_t idx = 0;
    if (input_schema->get_column_idx(out_col.get_name(), idx) != RC::SUCCESS) {
      return RC::INTERNAL;
    }
    project_values.push_back(original_tuple->get_value(input_schema, idx));
  }
  out_tuple = std::make_shared<Tuple>(project_values, output_schema_);
  return RC::SUCCESS;
}
