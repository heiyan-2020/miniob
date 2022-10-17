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
  void enter(AbstractExpressionRef node) override
  {
    if (std::dynamic_pointer_cast<FunctionCall>(node)) {
      std::shared_ptr<FunctionCall> expr = std::dynamic_pointer_cast<FunctionCall>(node);
      std::string id = expr->to_string();
      if (aggregates_.find(id) == aggregates_.end()) {
        aggregates_.emplace(id, expr);
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