#pragma once
#include "abstract_expression.h"
#include "unary_expression.h"

class SymbolFinder;

class IsNullExpression : public UnaryExpression {
  friend SymbolFinder;

public:
  IsNullExpression(AbstractExpressionRef &&left)
      : UnaryExpression(left) {}

  RC evaluate(EnvRef env, Value &out_value) const override
  {
    Value lhs;
    RC rc = get_child_at(0)->evaluate(env, lhs);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Left hand expression evaluate failed");
      return rc;
    }
    if (out_value.get_type() == TypeId::UNDEFINED) {
      rc = RC::EVALUATE;
    }
    if (lhs.is_null()) {
      out_value = Value{BOOL, true};
    } else {
      out_value = Value{BOOL, false};
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