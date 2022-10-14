#pragma once

#include "unary_expression.h"
#include "sql/plan_node/plan_node.h"

class ExpressionPlanner;

class SubqueryExpression : public virtual AbstractExpression {
  friend class ExpressionPlanner;

public:
  SubqueryExpression(hsql::SelectStatement *sel_clause) : subquery_(sel_clause) {}

  RC evaluate(EnvRef env, Value &out_value) = 0;

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