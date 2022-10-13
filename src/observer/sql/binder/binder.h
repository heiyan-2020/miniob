#pragma once
#include "rc.h"
#include "storage/common/db.h"
#include "sql/parser/hsql/sql/SelectStatement.h"
#include "sql/table/schema.h"
#include "sql/expr/abstract_expression.h"

class Binder {
  friend class Planner;
public:
  Binder() = default;

  Binder(Db *db): db_(db) {}

  RC bind_select(const hsql::SelectStatement *sel_stmt);

  RC bind_from(hsql::TableRef *root_table, SchemaRef &out_schema);

  RC bind_expression(hsql::Expr *expr, AbstractExpressionRef &out_expr);

private:
  RC bind_operator(hsql::OperatorType opt, OperatorType &out);

private:
  Db *db_;
  std::vector<AbstractExpressionRef> select_values_;
  AbstractExpressionRef where_predicate_;
};