#pragma once

#include "abstract_expression.h"
#include "util/macros.h"

class LeafNodeExpression : public virtual AbstractExpression {
public:
  RC traverse(ProcessorRef processor, AbstractExpressionRef &out_value)
  {
    std::shared_ptr<AbstractExpression> sp = shared_from_this();
    RC rc = processor->enter(sp);
    HANDLE_EXCEPTION(rc, "Traverse self error");

    out_value = processor->leave(sp);
    return RC::SUCCESS;
  }
};