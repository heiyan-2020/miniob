#pragma once

class AbstractExpression;
using AbstractExpressionRef = std::shared_ptr<AbstractExpression>;

class ExpressionProcessor;
using ProcessorRef = std::shared_ptr<ExpressionProcessor>;

class ExpressionProcessor {
public:
  virtual void enter(AbstractExpressionRef node) = 0;

  virtual AbstractExpressionRef leave(AbstractExpressionRef node) = 0;
};