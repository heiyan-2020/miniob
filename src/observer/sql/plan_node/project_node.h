//
// Created by 37034 on 10/5/2022.
//

#ifndef MINIDB_PROJECT_NODE_H
#define MINIDB_PROJECT_NODE_H

#include <utility>

#include "plan_node.h"

class ProjectNode : public PlanNode {
public:
  ProjectNode(std::shared_ptr<PlanNode> left_child, std::vector<hsql::Expr *> projection_specs)
      : left_child_(std::move(left_child)), projection_spec_(std::move(projection_specs))
  {}
  explicit ProjectNode(std::vector<hsql::Expr *> selValues);
  ProjectNode() = default;
  ~ProjectNode() override = default;

  RC prepare() override;
  RC initialize() override
  {
    return RC::UNIMPLENMENT;
  }
  RC next() override;

  Tuple *current_tuple() override;

private:
  PlanNodeRef left_child_;
  std::vector<hsql::Expr *> projection_spec_;

  void prepareSchema(SchemaRef input_schema);
  Tuple project_tuple(const Tuple &original_tuple);
  Tuple current_;
};

#endif  // MINIDB_PROJECT_NODE_H
