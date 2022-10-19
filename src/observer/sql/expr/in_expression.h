#pragma once

#include "subquery_expression.h"
#include "in_value_expression.h"

class InExpression : public SubqueryExpression, public UnaryExpression {
public:
  InExpression(hsql::SelectStatement *sel_clause, AbstractExpressionRef left_child) : SubqueryExpression(sel_clause), UnaryExpression(std::move(left_child))
  {}

  // [expr] in [subquery]
  RC evaluate(EnvRef env, Value &out_value) override
  {
    // By this time, subquery must be planned and prepared.
    assert(subquery_plan_);

    // only support expr which is a scalar value,
    // so return failure when schema.col_count() ≠ 1
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
    ThreeValueLogic cmp_res = ThreeValueLogic::FALSE;
    TupleRef subquery_tuple;
    subquery_plan_->initialize();
    while ((rc = subquery_plan_->next()) == RC::SUCCESS) {
      rc = subquery_plan_->current_tuple(subquery_tuple);
      if (rc != RC::SUCCESS) {
        LOG_PANIC("In operator: Getting tuple failed");
        return rc;
      }
      right_value = subquery_tuple->get_value(subquery_schema, 0);
      if (left_value.is_null() || right_value.is_null()) {
        cmp_res = ThreeValueLogic::UNKNOWN;
      } else if (left_value.compare_equals(right_value).get_as<bool>()) {
        cmp_res = ThreeValueLogic::TRUE;
        break;
      }
    }

    if (rc != RC::RECORD_EOF && rc != RC::SUCCESS) {
      // terminate abnormally.
      return rc;
    }


    if (cmp_res == ThreeValueLogic::FALSE) {
      out_value = {BOOL, false};
    } else if (cmp_res == ThreeValueLogic::UNKNOWN) {
      out_value = {BOOL, false};
      // Using is_null_ to indicate that this is UNKOWN
      out_value.is_null_ = true;
    } else {
      out_value = {BOOL, true};
    }
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