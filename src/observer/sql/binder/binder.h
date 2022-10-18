#pragma once
#include "rc.h"
#include "storage/common/db.h"
#include "sql/parser/hsql/sql/SelectStatement.h"
#include "sql/table/schema.h"
#include "sql/expr/abstract_expression.h"



class Planner;

class SelectCommand;


class Binder {
  friend class Planner;
  friend class SelectCommand;
public:
  Binder(Db *db, std::vector<SchemaRef> enclosing) : db_(db), enclosing_(std::move(enclosing)), from_schema_(new Schema())
  {}

  RC bind_select(const hsql::SelectStatement *sel_stmt);
  RC bind_from(hsql::TableRef *root_table, SchemaRef &out_schema);
  RC bind_expression(hsql::Expr *expr, AbstractExpressionRef &out_expr);

  void clear()
  {
    select_values_.clear();
    where_predicate_.reset();
    group_by_exprs_.clear();
    from_schema_.reset();
  }

private:
  RC bind_operator(hsql::OperatorType opt, OperatorType &out);

private:
  Db *db_;
  std::vector<AbstractExpressionRef> select_values_;
  AbstractExpressionRef where_predicate_;
  std::vector<AbstractExpressionRef> group_by_exprs_;
  std::vector<SchemaRef> enclosing_;
  SchemaRef from_schema_;

private:
  RC find_columns(const std::string& table_name, std::string column_name);
  bool has_multi_table_{};
};