#pragma once

#include "plan_node.h"
#include "sql/function/abstract_function.h"

class GroupAggregateNode : public PlanNode {
public:
  GroupAggregateNode(
      PlanNodeRef child,
      std::vector<AbstractExpressionRef> group_by_exprs,
      std::map<std::string, AbstractExpressionRef> aggregates);

  ~GroupAggregateNode() override = default;

  RC prepare() override;
  RC initialize() override
  {
    return RC::UNIMPLENMENT;
  }
  RC next() override;
  RC current_tuple(TupleRef &tuple) override;

private:
  RC prepare_schema(SchemaRef input_schema);

private:
  PlanNodeRef child_;
  std::vector<AbstractExpressionRef> group_by_exprs_;
  std::map<std::string, AbstractExpressionRef> aggregates_;
  SchemaRef input_schema_;
};