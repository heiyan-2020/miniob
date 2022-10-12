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

private:
  Value val_;
};