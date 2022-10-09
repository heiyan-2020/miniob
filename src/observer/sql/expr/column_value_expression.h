#pragma once
#include "abstract_expression.h"

class SymbolFinder;

class ColumnValueExpression : public AbstractExpression {
  friend SymbolFinder;

public:
  ColumnValueExpression(ColumnName col_name)
      : col_name_(std::move(col_name)) {}

  RC evaluate(EnvRef env, Value &out_value) const override
  {
    RC rc = env->get_column_value(col_name_, out_value);
    return rc;
  }

  AbstractExpressionRef traverse(ProcessorRef processor) override
  {
    // leaf node
    // TODO(zyx): Avoid creating second manager object for this.
    std::shared_ptr<AbstractExpression> sp = shared_from_this();
    processor->enter(sp);
    return processor->leave(sp);
  }

private:
  ColumnName col_name_;
};