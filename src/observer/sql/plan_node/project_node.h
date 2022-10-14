//
// Created by 37034 on 10/5/2022.
//

#ifndef MINIDB_PROJECT_NODE_H
#define MINIDB_PROJECT_NODE_H

#include <utility>

#include "plan_node.h"

class ProjectNode : public PlanNode {
public:
  ProjectNode(std::shared_ptr<PlanNode> left_child, std::vector<AbstractExpressionRef> projection_specs)
      : PlanNode(left_child), projection_spec_(std::move(projection_specs))
  {}
  ~ProjectNode() override = default;

  RC prepare() override;
  RC initialize() override
  {
    current_.reset();
    return RC::SUCCESS;
  }
  RC next() override;

  RC current_tuple(TupleRef &tuple) override;

private:
  RC prepare_schema(SchemaRef input_schema);
  RC project_tuple(TupleRef original_tuple, TupleRef &out_tuple);

  std::vector<AbstractExpressionRef> projection_spec_;
  SchemaRef input_schema_;
  TupleRef current_;

};

#endif  // MINIDB_PROJECT_NODE_H
