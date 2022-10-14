#pragma once

#include "abstract_expression.h"

class BinaryExpression : public AbstractExpression {
public:
  BinaryExpression(AbstractExpressionRef left, AbstractExpressionRef right) : AbstractExpression({std::move(left), std::move(right)}) {}

  AbstractExpressionRef traverse(ProcessorRef processor)
  {
    std::shared_ptr<AbstractExpression> sp = shared_from_this();
    processor->enter(sp);
    children_[0] = children_[0]->traverse(processor);
    children_[1] = children_[1]->traverse(processor);
    return processor->leave(sp);
  }
};