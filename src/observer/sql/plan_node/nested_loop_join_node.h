#pragma once
#include <utility>

#include "plan_node.h"

enum JoinType {INNER = 0, CROSS};

class NestedLoopJoinNode : public PlanNode {
public:
  NestedLoopJoinNode(PlanNodeRef left_child, PlanNodeRef right_child, JoinType type, AbstractExpressionRef cond)
      : PlanNode(), left_child_(std::move(left_child)), right_child_(std::move(right_child)), type_(std::move(type))
                  , cond_(std::move(cond))
  {}
  ~NestedLoopJoinNode() override = default;

  RC prepare() override;
  RC initialize() override
  {
    return RC::UNIMPLENMENT;
  }
  RC next() override;

  RC current_tuple(TupleRef &tuple) override;

private:
//  RC prepareSchema(SchemaRef input_schema);

  PlanNodeRef left_child_;
  PlanNodeRef right_child_;
  AbstractExpressionRef cond_;
  JoinType type_;
  TupleRef current_;

};