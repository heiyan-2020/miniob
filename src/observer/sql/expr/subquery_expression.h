#pragma once

#include "abstract_expression.h"
#include "sql/plan_node/plan_node.h"

class ExpressionPlanner;

class SubqueryExpression : public AbstractExpression {
  friend class ExpressionPlanner;

public:
  SubqueryExpression(hsql::SelectStatement *sel_clause) : subquery_(sel_clause) {}

  RC evaluate(EnvRef env, Value &out_value) const = 0;

  AbstractExpressionRef traverse(ProcessorRef processor) override
  {
    std::shared_ptr<AbstractExpression> sp = shared_from_this();
    processor->enter(sp);
    children_[0] = children_[0]->traverse(processor);
    return processor->leave(sp);
  }

  auto convert_to_column(SchemaRef schema, Column &out_col) -> RC override
  {
    return RC::UNIMPLENMENT;
  }

  std::string to_string() const override
  {
    return {};
  }
protected:
  hsql::SelectStatement *subquery_;
  PlanNodeRef subquery_plan_;
};