#pragma once

#include "subquery_expression.h"
#include "leaf_node_expression.h"

class ScalarExpression : public SubqueryExpression, public LeafNodeExpression {
public:
  ScalarExpression(hsql::SelectStatement *sel_clause) : SubqueryExpression(sel_clause)
  {}

  // scalar sub-query must be one row & one col.
  RC evaluate(EnvRef env, Value &out_value) override
  {
    // By this time, subquery must be planned and prepared.
    assert(subquery_plan_);
    if (!computed_) {
      SchemaRef subquery_schema = subquery_plan_->get_schema();
      if (subquery_schema->get_column_count() != 1) {
        LOG_PANIC("Subquery schema doesn't match");
        return RC::MISMATCH;
      }
      RC rc;
      TupleRef subquery_tuple;
      subquery_plan_->initialize();
      if ((rc = subquery_plan_->next()) == RC::SUCCESS) {
        rc = subquery_plan_->current_tuple(subquery_tuple);
        if (rc != RC::SUCCESS) {
          LOG_PANIC("In operator: Getting tuple failed");
          return rc;
        }
        out_value = subquery_tuple->get_value(subquery_schema, 0);
      }

      if (rc != RC::RECORD_EOF && rc != RC::SUCCESS) {
        // terminate abnormally.
        return rc;
      }

      rc = subquery_plan_->next();

      if (rc != RC::RECORD_EOF) {
        // terminate abnormally.
        return RC::SCALAR;
      }
      scalar_value_ = out_value;
      computed_ = true;
      return RC::SUCCESS;
    } else {
      out_value = scalar_value_;
      return RC::SUCCESS;
    }
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
  bool computed_{false};
  Value scalar_value_;
};