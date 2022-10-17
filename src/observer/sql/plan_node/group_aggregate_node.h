#pragma once

#include "plan_node.h"
#include "sql/function/abstract_function.h"

#include <unordered_map>

struct HashAggregateKey {
  std::vector<Value> values{};
};

namespace std {
template <>
struct hash<HashAggregateKey> {
  size_t operator()(const HashAggregateKey &aggregate_key) const
  {
    size_t res{7};
    for (const auto& value : aggregate_key.values) {
      res = 31 * res + std::hash<Value>{}(value);
    }
    return res;
  }
};

template <>
struct equal_to<HashAggregateKey> {
  bool operator()(const HashAggregateKey &lhs, const HashAggregateKey &rhs) const
  {
    if (lhs.values.size() != rhs.values.size()) {
      return false;
    }
    for (size_t i = 0; i < lhs.values.size(); ++i) {
      auto cmp = lhs.values[i].compare_equals(rhs.values[i]);
      if (!cmp.value_.bool_) {
        return false;
      }
    }
    return true;
  }
};
}

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
  RC compute_aggregates();
  RC update_aggregates(std::map<std::string, AbstractExpressionRef> group_aggregates);
  RC evaluate_group_by_exprs(TupleRef original_tuple, HashAggregateKey &out_values);

private:
  std::vector<AbstractExpressionRef> group_by_exprs_;
  std::map<std::string, AbstractExpressionRef> aggregates_;
  SchemaRef input_schema_;
  std::unordered_map<HashAggregateKey, std::map<std::string, AbstractExpressionRef>> computed_aggregates_;
  bool initialized_{};
};