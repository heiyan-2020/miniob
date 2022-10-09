#pragma once

#include "planner.h"

class Binder {
public:
  Binder(Db *db): db_(db) {}

  RC bind_select(const hsql::SelectStatement *sel_stmt);

  RC bind_from(hsql::TableRef *root_table, SchemaRef &out_schema);

  AbstractExpressionRef bind_expression(hsql::Expr *expr);

private:
  ComparisonType bind_operator(hsql::OperatorType opt)
  {
    const struct info {
      hsql::OperatorType opt;
      ComparisonType ct;
    } infos[] = {
        {hsql::OperatorType::kOpEquals, ComparisonType::Equal},
        {hsql::OperatorType::kOpGreater, ComparisonType::GreaterThan},
        {hsql::OperatorType::kOpGreaterEq, ComparisonType::GreaterThanOrEqual},
        {hsql::OperatorType::kOpNotEquals, ComparisonType::NotEqual},
        {hsql::OperatorType::kOpLess, ComparisonType::LessThan},
        {hsql::OperatorType::kOpLessEq, ComparisonType::LessThanOrEqual},
    };
    for (auto info : infos) {
      if (info.opt == opt) {
        return info.ct;
      }
    }
    LOG_ERROR("Bind operator type failed");
    assert(false);
    return {}; // dummy return value, because program will halt before.
  }

private:
  Db *db_;
};