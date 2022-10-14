#pragma once

#include "abstract_expression.h"

class UnaryExpression : public virtual AbstractExpression {
public:
  UnaryExpression(AbstractExpressionRef child) : AbstractExpression({std::move(child)}) {}

  AbstractExpressionRef traverse(ProcessorRef processor)
  {
    std::shared_ptr<AbstractExpression> sp = shared_from_this();
    processor->enter(sp);
    children_[0] = children_[0]->traverse(processor);
    return processor->leave(sp);
  }
};