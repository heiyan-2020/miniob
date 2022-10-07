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

class PlanNode;
using PlanNodeRef = std::shared_ptr<PlanNode>;

class PlanNode {
public:
  PlanNode() = default;
  explicit PlanNode(std::shared_ptr<PlanNode> left_child)
  {}
  PlanNode(std::shared_ptr<PlanNode> left_child, std::shared_ptr<PlanNode> right_child)
  {}

  virtual ~PlanNode() = default;

  virtual RC prepare() = 0;
  virtual RC initialize() = 0;
  virtual RC next() = 0;
  virtual Tuple *current_tuple() = 0;

  SchemaRef getSchema()
  {
    return output_schema_;
  }

protected:
  PlanNodeRef left_child_;
  PlanNodeRef right_child_;
  SchemaRef output_schema_;
  EnvRef env_;
};

#endif  // MINIDB_PLANNODE_H
