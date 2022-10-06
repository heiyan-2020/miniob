//
// Created by 37034 on 10/4/2022.
//

#ifndef MINIDB_PLANNODE_H
#define MINIDB_PLANNODE_H

#include <memory>
#include "Schema.h"
#include "../expr/Environment.h"
#include "sql/parser/hsql/sql/Expr.h"
#include "common/log/log.h"
#include "sql/expr/tuple.h"

class PlanNode {
public:
  PlanNode() {

  }
  PlanNode(std::shared_ptr<PlanNode> left_child) {

  }
  PlanNode(std::shared_ptr<PlanNode> left_child, std::shared_ptr<PlanNode> right_child) {

  }

  virtual RC prepare() = 0;
  virtual RC initialize() = 0;
  virtual RC next() = 0;
  virtual Tuple *current_tuple() = 0;

  Schema getSchema() { return output_schema_; }


protected:
  std::shared_ptr<PlanNode> left_child_;
  std::shared_ptr<PlanNode> right_child_;
  Schema output_schema_;
  Schema input_schema_;
  std::shared_ptr<Environment> env_;
};



#endif  // MINIDB_PLANNODE_H
