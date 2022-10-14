#pragma once

#include "subquery_expression.h"

class InExpression : public SubqueryExpression, public UnaryExpression {
public:
  InExpression(hsql::SelectStatement *sel_clause, AbstractExpressionRef left_child) : SubqueryExpression(sel_clause), UnaryExpression(std::move(left_child))
  {}

  // [expr] in [subquery]
  RC evaluate(EnvRef env, Value &out_value) const override
  {
    // By this time, subquery must be planned and prepared.
    assert(subquery_plan_);

    //only support expr which is a scalar value,
    //  so return failure when schema.col_count() ≠ 1
    SchemaRef subquery_schema = subquery_plan_->get_schema();
    if (subquery_schema->get_column_count() != 1) {
      LOG_PANIC("Subquery schema doesn't match");
      return RC::MISMATCH;
    }

    Value left_value, right_value;
    RC rc = children_[0]->evaluate(env, left_value);
    if (rc != RC::SUCCESS) {
      LOG_PANIC("Left side expression of IN operator evaluating failed");
      return rc;
    }

    // repeatedly find an equal tuple until EOF.
    TupleRef subquery_tuple;
    subquery_plan_->initialize();
    while ((rc = subquery_plan_->next()) == RC::SUCCESS) {
      rc = subquery_plan_->current_tuple(subquery_tuple);
      if (rc != RC::SUCCESS) {
        LOG_PANIC("In operator: Getting tuple failed");
        return rc;
      }
      right_value = subquery_tuple->get_value(subquery_schema, 0);
      Value res = left_value.compare_equals(right_value);
      if (left_value.compare_equals(right_value).get_as<bool>()) {
        out_value = {TypeId::BOOL, true};
        return RC::SUCCESS;
      }
    }

    if (rc != RC::RECORD_EOF) {
      // terminate abnormally.
      return rc;
    }

    // can't find equivalent row, the result is false.
    out_value = {TypeId::BOOL, false};
    return RC::SUCCESS;
  }

  auto convert_to_column(SchemaRef schema, Column &out_col) -> RC override
  {
    return RC::UNIMPLENMENT;
  }

  std::string to_string() const override
  {
    return {};
  }

private:

};