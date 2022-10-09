//
// Created by 37034 on 10/5/2022.
//
#include "project_node.h"

#include <utility>
#include "common/log/log.h"

RC ProjectNode::prepare()
{
  if (left_child_) {
    left_child_->prepare();
    prepareSchema(left_child_->get_schema());
  } else {
    LOG_WARN("Not implemented!");
  }
  return RC::SUCCESS;
}

RC ProjectNode::next()
{
  if (left_child_) {
    return left_child_->next();
  }
  LOG_WARN("Project node should have a child.");
  return RC::GENERIC_ERROR;
}

TupleRef ProjectNode::current_tuple()
{
  current_ = left_child_->current_tuple();
  return project_tuple(current_);
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

TupleRef ProjectNode::project_tuple(TupleRef tuple)
{
  SchemaRef input_schema = left_child_->get_schema();
  std::vector<Value> project_values;
  for (size_t i = 0; i < output_schema_->get_column_count(); i++) {
    const auto &out_col = output_schema_->get_column(i);
    size_t idx = input_schema->get_column_idx(out_col.get_name());
    project_values.push_back(tuple->get_value(input_schema, idx));
  }
  return std::make_shared<Tuple>(project_values, output_schema_);
}
