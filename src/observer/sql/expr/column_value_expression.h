#pragma once
#include "abstract_expression.h"

class ColumnValueExpression : public AbstractExpression {
public:
  ColumnValueExpression(ColumnName col_name)
      : col_name_(std::move(col_name)) {}

  RC evaluate(EnvRef env, Value &out_value) const override
  {
    RC rc = env->get_column_value(col_name_, out_value);
    return rc;
  }

private:
  ColumnName col_name_;
};