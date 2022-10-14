#pragma once

#include <utility>

#include "plan_node.h"

class FilterNode : public PlanNode {
public:
  FilterNode(std::shared_ptr<PlanNode> left_child, AbstractExpressionRef predicate)
      : PlanNode(left_child), predicate_(std::move(predicate))
  {}
  ~FilterNode() override = default;

  RC prepare() override;
  RC initialize() override
  {
    current_.reset();
    return RC::SUCCESS;
  }
  RC next() override;

  RC current_tuple(TupleRef &tuple) override;

private:
  RC is_selected(TupleRef tuple, bool &result);

  AbstractExpressionRef predicate_;
  TupleRef current_;

};

