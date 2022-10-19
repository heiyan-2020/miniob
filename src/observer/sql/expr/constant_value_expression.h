#pragma once
#include "abstract_expression.h"
#include "leaf_node_expression.h"

class ConstantValueExpression : public LeafNodeExpression {
public:
  explicit ConstantValueExpression(Value &&val) :
        val_(val) {}

  RC evaluate(EnvRef env, Value &out_value)
  {
    out_value = val_;
    return RC::SUCCESS;
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