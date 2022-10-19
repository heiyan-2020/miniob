#pragma once

#include "abstract_expression.h"
#include "util/macros.h"

class BinaryExpression : public AbstractExpression {
public:
  BinaryExpression(AbstractExpressionRef left, AbstractExpressionRef right) {
    children_.push_back(std::move(left));
    children_.push_back(std::move(right));
  }

  RC traverse(ProcessorRef processor, AbstractExpressionRef &out_value)
  {
    std::shared_ptr<AbstractExpression> sp = shared_from_this();
    RC rc;
    rc = processor->enter(sp);
    HANDLE_EXCEPTION(rc, "Traverse self error");
    AbstractExpressionRef lhs, rhs;
    rc = children_[0]->traverse(processor, lhs);
    HANDLE_EXCEPTION(rc, "Traverse lhs error");

    rc = children_[1]->traverse(processor, rhs);
    HANDLE_EXCEPTION(rc, "Traverse rhs error");

    out_value = processor->leave(sp);
    return RC::SUCCESS;
  }
};