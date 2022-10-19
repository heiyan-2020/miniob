#pragma once
#include "abstract_expression.h"
#include "leaf_node_expression.h"

class SymbolFinder;

class ColumnValueExpression : public LeafNodeExpression {
  friend SymbolFinder;

public:
  ColumnValueExpression(ColumnName col_name)
      : col_name_(std::move(col_name)) {}

  RC evaluate(EnvRef env, Value &out_value) override
  {
    RC rc = env->get_column_value(col_name_, out_value);
    return rc;
  }

  ColumnName get_col_name() const
  {
    return col_name_;
  }

  auto convert_to_column(SchemaRef schema, Column &out_col) -> RC override
  {
    std::vector<Column> found = schema->find_columns(col_name_.table_name(), col_name_.column_name());
    if (found.size() != 1) {
      LOG_PANIC("Convert to column failed");
      return RC::EVALUATE;
    }
    out_col = found[0];
    return RC::SUCCESS;
  }

  std::string to_string() const override
  {
    return col_name_.to_string();
  }

private:
  ColumnName col_name_;
};