//
// Created by 37034 on 10/5/2022.
//

#ifndef MINIDB_PROJECT_NODE_H
#define MINIDB_PROJECT_NODE_H
#include "PlanNode.h"


class ProjectNode : public PlanNode {
public:
  ProjectNode(std::shared_ptr<PlanNode> leftChild, std::vector<hsql::Expr*> projectionSpecs): left_child_(leftChild), projection_spec_(projectionSpecs)
  {}
  ProjectNode(std::vector<hsql::Expr*> selValues);
  ProjectNode();
  virtual RC prepare() override;
  virtual RC initialize() override {
    return RC::UNIMPLENMENT;
  }
  virtual RC next() override;

  virtual Tuple *current_tuple() override;

private:
  std::shared_ptr<PlanNode> left_child_;
  std::vector<hsql::Expr*> projection_spec_;

  void prepareSchema(Schema inputSchema);
  ProjectTuple project_tuple(RowTuple ori_tuple);
  ProjectTuple current_;
};

#endif  // MINIDB_PROJECT_NODE_H
