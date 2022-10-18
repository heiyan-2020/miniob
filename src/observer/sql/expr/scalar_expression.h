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
      has_scalar_ = true;
    }

    if (rc != RC::SUCCESS && !has_scalar_) {
      // terminate abnormally.
      // if rc == RC::EOF, still return false because empty tuple isn't scalar value.
      LOG_PANIC("Scalar evaluation failed");
      return RC::EVALUATE;
    }

    rc = subquery_plan_->next();

    if (rc != RC::RECORD_EOF) {
      // terminate abnormally.
      return RC::SCALAR;
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
  bool has_scalar_{false};
};