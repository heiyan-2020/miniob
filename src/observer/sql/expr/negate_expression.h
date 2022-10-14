#pragma once
#include "abstract_expression.h"
#include "unary_expression.h"

class SymbolFinder;

class NegateExpression :public UnaryExpression {
  friend SymbolFinder;

public:
  NegateExpression(AbstractExpressionRef &&left)
      : UnaryExpression(left) {}

  RC evaluate(EnvRef env, Value &out_value) const override
  {
    Value lhs;
    RC rc = get_child_at(0)->evaluate(env, lhs);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Left hand expression evaluate failed");
      return rc;
    }
    out_value = lhs.negation();
    if (out_value.get_type() == TypeId::UNDEFINED) {
      rc = RC::EVALUATE;
    }
    return rc;
  }

  auto convert_to_column(SchemaRef schema, Column &out_col) -> RC override
  {
    return RC::UNIMPLENMENT;
  }

  std::string to_string() const override
  {
    return {};
  }

private:
};