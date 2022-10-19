#pragma once

#include <memory>
#include <map>
#include <cassert>

#include "expression_processor.h"
#include "function_call.h"
#include "sql/function/aggregate_function.h"
#include "sql/function/count_aggregate.h"

class AggregationProcessor : public ExpressionProcessor {
  friend class AbstractExpression;
public:
  RC enter(AbstractExpressionRef node) override
  {
    std::shared_ptr<FunctionCall> fn_call = std::dynamic_pointer_cast<FunctionCall>(node);
    if (fn_call) {
      std::shared_ptr<AggregateFunction> agg_fn = std::dynamic_pointer_cast<AggregateFunction>(fn_call->get_fn());
      if (agg_fn) {
        std::string id = fn_call->to_string();
        if (aggregates_.find(id) == aggregates_.end()) {
          aggregates_.emplace(id, fn_call);
        }
      }
    }
  }

  AbstractExpressionRef leave(AbstractExpressionRef node) override
  {
    return node;
  }

  auto get_aggregates() -> std::map<std::string, AbstractExpressionRef>
  {
    return aggregates_;
  }

private:
  std::map<std::string, AbstractExpressionRef> aggregates_{};
};