#pragma once
#include "abstract_expression.h"

class ConstantValueExpression : public AbstractExpression {
public:
  explicit ConstantValueExpression(Value &&val) :
        AbstractExpression({}, val.get_type()), val_(val) {}

  RC evaluate(EnvRef env, Value &out_value) const
  {
    out_value = val_;
    return RC::SUCCESS;
  }

private:
  Value val_;
};