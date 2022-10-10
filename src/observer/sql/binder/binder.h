#pragma once

#include "planner.h"

class Binder {
public:
  Binder(Db *db): db_(db) {}

  RC bind_select(const hsql::SelectStatement *sel_stmt);

  RC bind_from(hsql::TableRef *root_table, SchemaRef &out_schema);

  AbstractExpressionRef bind_expression(hsql::Expr *expr);

private:
  OperatorType bind_operator(hsql::OperatorType opt);

private:
  Db *db_;
};