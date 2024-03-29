//
// Created by 37034 on 10/4/2022.
//

#ifndef MINIDB_PLANNODE_H
#define MINIDB_PLANNODE_H

#include <memory>

#include "sql/table/schema.h"
#include "../expr/environment.h"
#include "sql/parser/hsql/sql/Expr.h"
#include "common/log/log.h"
#include "sql/table/tuple.h"
#include "sql/expr/abstract_expression.h"

class PlanNode;
using PlanNodeRef = std::shared_ptr<PlanNode>;

class PlanNode {
public:
  PlanNode()
  {
    env_ = std::make_shared<Environment>();
  }
  explicit PlanNode(std::shared_ptr<PlanNode> left_child) : left_child_(left_child)
  {
    env_ = std::make_shared<Environment>();
  }
  PlanNode(std::shared_ptr<PlanNode> left_child, std::shared_ptr<PlanNode> right_child) : left_child_(left_child), right_child_(right_child)
  {
    env_ = std::make_shared<Environment>();
  }

  virtual ~PlanNode() = default;

  virtual RC prepare() = 0;
  virtual RC initialize() = 0;
  virtual RC next() = 0;
  virtual RC current_tuple(TupleRef &tuple) = 0;

  SchemaRef get_schema()
  {
    return output_schema_;
  }

  void set_env(EnvRef env)
  {
    env_ = std::move(env);
  }

  void add_parent_env(EnvRef parent)
  {
    env_->add_parent_env(parent);

    // update children's parent environments
    if (left_child_)
      left_child_->add_parent_env(parent);

    if (right_child_)
      right_child_->add_parent_env(parent);
  }

protected:
  PlanNodeRef left_child_;
  PlanNodeRef right_child_;
  SchemaRef output_schema_;
  EnvRef env_;
};

#endif  // MINIDB_PLANNODE_H
