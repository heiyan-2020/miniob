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
  RC initialize() override;
  RC next() override;
  RC current_tuple(TupleRef &tuple) override;

private:
  RC prepare_output_schema(SchemaRef input_schema);
  RC prepare_group_values_schema(SchemaRef input_schema);
  RC compute_aggregates();
  RC evaluate_group_by_exprs(TupleRef original_tuple, TupleRef &out_tuple);

private:
  std::vector<AbstractExpressionRef> group_by_exprs_;
  std::map<std::string, AbstractExpressionRef> aggregates_;
  SchemaRef input_schema_;
  SchemaRef group_values_schema_;
  std::map<TupleRef, std::map<std::string, AbstractExpressionRef>> computed_aggregates_;
};