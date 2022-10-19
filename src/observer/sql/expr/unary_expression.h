#pragma once

#include "abstract_expression.h"
#include "util/macros.h"

class UnaryExpression : public virtual AbstractExpression {
public:
  UnaryExpression(AbstractExpressionRef child) {
    children_.push_back(std::move(child));
  }

  RC traverse(ProcessorRef processor, AbstractExpressionRef &out_value)
  {
    std::shared_ptr<AbstractExpression> sp = shared_from_this();
    RC rc = processor->enter(sp);
    HANDLE_EXCEPTION(rc, "Traverse self error");
    AbstractExpressionRef lhs;
    rc = children_[0]->traverse(processor, lhs);
    HANDLE_EXCEPTION(rc, "Traverse child error");
    out_value = processor->leave(sp);
    return rc;
  }
};