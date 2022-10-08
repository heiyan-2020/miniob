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
  return current_;
}

void ProjectNode::prepareSchema(SchemaRef input_schema)
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
      // TODO(vgalaxy): column not exist
      assert(tmp.size() == 1);
      if (expr->hasAlias()) {
        tmp[0].set_alias(expr->alias);
      }
      columns.insert(columns.end(), tmp.begin(), tmp.end());
    } else {
      LOG_WARN("select raw value not supported.");
    }
  }
  output_schema_ = std::make_shared<Schema>(columns);
}
