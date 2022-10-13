#pragma once
#include "abstract_expression.h"

class ConstantValueExpression : public AbstractExpression {
public:
  explicit ConstantValueExpression(Value &&val) :
        val_(val) {}

  RC evaluate(EnvRef env, Value &out_value) const
  {
    out_value = val_;
    return RC::SUCCESS;
  }

  AbstractExpressionRef traverse(ProcessorRef processor) override
  {
    // leaf node
    // TODO(zyx): Avoid creating second manager object for this.
    std::shared_ptr<AbstractExpression> sp = shared_from_this();
    processor->enter(sp);
    return processor->leave(sp);
  }

  auto convert_to_column(SchemaRef schema, Column &out_col) -> RC override
  {
    out_col = {ColumnName{to_string()}, val_.get_type(), val_.get_len()};
    return RC::SUCCESS;
  }

  std::string to_string() const override
  {
    if (val_.get_type() == TypeId::UNDEFINED) {
      return "NULL";
    } else {
      return val_.to_string();
    }
  }

private:
  Value val_;
};