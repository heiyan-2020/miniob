#pragma once

#include "plan_node.h"

class RenameNode : public PlanNode {
public:
  RenameNode(std::shared_ptr<PlanNode> left_child, std::string alias)
      : PlanNode(left_child), alias_(alias)
  {}
  ~RenameNode() override = default;

  RC prepare() override;
  RC initialize() override
  {
    current_.reset();
    left_child_->initialize();
    return RC::SUCCESS;
  }
  RC next() override;

  RC current_tuple(TupleRef &tuple) override;
private:
  TupleRef current_;
  std::string alias_;
};