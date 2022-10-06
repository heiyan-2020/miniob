//
// Created by 37034 on 10/5/2022.
//
#include "project_node.h"
#include "common/log/log.h"

RC ProjectNode::prepare()
{
  if (left_child_) {
    left_child_->prepare();
    prepareSchema(left_child_->getSchema());
  } else {
    LOG_WARN("Not implemented!\n");
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

Tuple* ProjectNode::current_tuple()
{
  current_.set_tuple(left_child_->current_tuple());
  return &current_;
}

ProjectTuple ProjectNode::project_tuple(RowTuple ori_tuple) {
  ProjectTuple ret_tuple;
  std::vector<Column> tmp;

  for (hsql::Expr *expr : projection_spec_) {
    if (expr->type == hsql::kExprStar) {
      if (expr->hasTable()) {
        tmp = input_schema_.findColumns(expr->table, nullptr);
        for (auto col : tmp) {
          ret_tuple.add_cell_spec(col.get_spec());
        }
      } else {
        tmp = input_schema_.findColumns(nullptr, nullptr);
        for (auto col : tmp) {
          ret_tuple.add_cell_spec(col.get_spec());
        }
      }
    } else if (expr->type == hsql::kExprColumnRef) {
      tmp = input_schema_.findColumns(expr->table, expr->getName());
      assert(tmp.size() == 1);
      for (auto col : tmp) {
        ret_tuple.add_cell_spec(col.get_spec());
      }
    } else {
      LOG_WARN("select value not supported.");
    }
  }

  return ret_tuple;
}

void ProjectNode::prepareSchema(Schema inputSchema)
{
  input_schema_ = inputSchema;
  std::vector<Column> fields;
  std::vector<Column> tmp;

  for (hsql::Expr *expr : projection_spec_) {
    if (expr->type == hsql::kExprStar) {
      if (expr->hasTable()) {
        tmp = input_schema_.findColumns(expr->table, nullptr);
        fields.insert(fields.end(), tmp.begin(), tmp.end());
        for (auto col : tmp) {
          current_.add_cell_spec(col.get_spec());
        }
      } else {
        tmp = input_schema_.findColumns(nullptr, nullptr);
        fields.insert(fields.end(), tmp.begin(), tmp.end());
        for (auto col : tmp) {
          current_.add_cell_spec(col.get_spec());
        }
      }
    } else if (expr->type == hsql::kExprColumnRef) {
        tmp = input_schema_.findColumns(expr->table, expr->getName());
        assert(tmp.size() == 1);
        if (expr->hasAlias()) {
          tmp[0].set_alias(expr->alias);
        }
        fields.insert(fields.end(), tmp.begin(), tmp.end());
        for (auto col : tmp) {
          current_.add_cell_spec(col.get_spec());
        }
    } else {
      LOG_WARN("select value not supported.");
    }
  }

  //TODO: set out_put schema.
}
