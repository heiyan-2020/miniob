#pragma once

#include "planner.h"

class Binder {
public:
  Binder(Db *db): db_(db) {}

  RC bind_select(const hsql::SelectStatement *sel_stmt);

  RC bind_from(hsql::TableRef *root_table, SchemaRef &out_schema);

  RC bind_expression(hsql::Expr *expr, AbstractExpressionRef &out_expr);

private:
  RC bind_operator(hsql::OperatorType opt, OperatorType &out);

private:
  Db *db_;
};