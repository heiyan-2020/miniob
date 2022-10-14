#pragma once

#include "abstract_expression.h"

class LeafNodeExpression : public virtual AbstractExpression {
public:
  LeafNodeExpression() = default;

  AbstractExpressionRef traverse(ProcessorRef processor)
  {
    std::shared_ptr<AbstractExpression> sp = shared_from_this();
    processor->enter(sp);
    return processor->leave(sp);
  }
};