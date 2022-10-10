#pragma once
#include "abstract_expression.h"

class SymbolFinder;

class BoolExpression : public AbstractExpression {
  friend SymbolFinder;

public:
  public:
    BoolExpression(AbstractExpressionRef &&left, AbstractExpressionRef &&right, OperatorType type)
        : AbstractExpression({std::move(left), std::move(right)}, TypeId::BOOL), ope_type_(type) {}

    RC evaluate(EnvRef env, Value &out_value) const override;

    AbstractExpressionRef traverse(ProcessorRef processor) override;
private:
  OperatorType ope_type_;
};