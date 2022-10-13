#pragma once

#include <memory>
#include <map>

#include "expression_processor.h"
#include "sql/function/abstract_function.h"
#include "function_call.h"

class AggregationProcessor : public ExpressionProcessor {
  friend class AbstractExpression;
public:
  void enter(AbstractExpressionRef node) override
  {
    if (std::dynamic_pointer_cast<FunctionCall>(node)) {
      std::shared_ptr<FunctionCall> expr = std::dynamic_pointer_cast<FunctionCall>(node);
      std::string id = expr->to_string();
      if (aggregates.find(id) == aggregates.end()) {
        aggregates.emplace(id, expr->get_fn_name())
      }
    }
  }

  AbstractExpressionRef leave(AbstractExpressionRef node) override
  {
    return node;
  }

  auto get_aggregates() -> std::map<std::string, AbstractFunctionRef>
  {
    return std::move(aggregates);
  }

private:
  std::map<std::string, AbstractFunctionRef> aggregates{};
};