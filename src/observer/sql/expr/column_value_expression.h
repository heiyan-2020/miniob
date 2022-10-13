#pragma once
#include "abstract_expression.h"

class SymbolFinder;

class ColumnValueExpression : public AbstractExpression {
  friend SymbolFinder;

public:
  ColumnValueExpression(ColumnName col_name)
      : col_name_(std::move(col_name)) {}

  RC evaluate(EnvRef env, Value &out_value) const override
  {
    RC rc = env->get_column_value(col_name_, out_value);
    return rc;
  }

  AbstractExpressionRef traverse(ProcessorRef processor) override
  {
    // leaf node
    // TODO(zyx): Avoid creating second manager object for this.
    std::shared_ptr<AbstractExpression> sp = shared_from_this();
    processor->enter(sp);
    return processor->leave(sp);
  }

  ColumnName get_col_name() const
  {
    return col_name_;
  }

  auto convert_to_column(SchemaRef schema, Column &out_col) -> RC const override
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