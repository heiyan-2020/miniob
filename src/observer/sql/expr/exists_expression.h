#pragma once
#include "leaf_node_expression.h"
#include "subquery_expression.h"

class ExistsExpression : public SubqueryExpression, public LeafNodeExpression {
public:
  explicit ExistsExpression(hsql::SelectStatement *sel_clause)
      : SubqueryExpression(sel_clause) {}

  RC evaluate(EnvRef env, Value &out_value)
  {
    // By this time, subquery must be planned and prepared.
    assert(subquery_plan_);
    RC rc;

    // repeatedly find an equal tuple until EOF.
    TupleRef subquery_tuple;
    subquery_plan_->initialize();
    while ((rc = subquery_plan_->next()) == RC::SUCCESS) {
      rc = subquery_plan_->current_tuple(subquery_tuple);
      if (rc != RC::SUCCESS) {
        LOG_PANIC("In operator: Getting tuple failed");
        return rc;
      }
      // Find a tuple, return true;
      out_value = {BOOL, true};
      return RC::SUCCESS;
    }

    if (rc != RC::RECORD_EOF) {
      // terminate abnormally.
      return rc;
    }

    // can't find a tuple, the result is false.
    out_value = {TypeId::BOOL, false};
    return RC::SUCCESS;
  }

  AbstractExpressionRef traverse(ProcessorRef processor) override
  {
    std::shared_ptr<AbstractExpression> sp = shared_from_this();
    processor->enter(sp);
    return processor->leave(sp);
  }

  auto convert_to_column(SchemaRef schema, Column &out_col) -> RC override
  {
    out_col = {ColumnName{to_string()}, val_.get_type(), val_.get_len()};
    return RC::SUCCESS;
  }

  std::string to_string() const override
  {
    if (val_.get_type() == TypeId::UNDEFINED) {
      return "NULL";
    } else {
      return val_.to_string();
    }
  }

private:
  Value val_;
};