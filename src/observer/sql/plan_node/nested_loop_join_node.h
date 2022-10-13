#pragma once
#include <utility>

#include "plan_node.h"

class NestedLoopJoinNode : public PlanNode {
public:
  NestedLoopJoinNode(PlanNodeRef left_child, PlanNodeRef right_child, AbstractExpressionRef cond)
      : PlanNode(std::move(left_child), std::move(right_child)), cond_(std::move(cond))
  {}
  ~NestedLoopJoinNode() override = default;

  RC prepare() override;
  RC initialize() override
  {
    current_.reset();
    marked_left_.reset();
    return RC::SUCCESS;
  }
  RC next() override;

  RC current_tuple(TupleRef &tuple) override;

private:
  RC get_tuples();

  RC can_join(Value &out_value);

  TupleRef join_tuples(TupleRef left, TupleRef right);

  AbstractExpressionRef cond_;
  TupleRef current_;
  TupleRef marked_left_;
  TupleRef marked_right_;
};