#pragma once
#include "abstract_expression.h"
#include "unary_expression.h"

class SymbolFinder;

class NegateExpression :public UnaryExpression {
  friend SymbolFinder;

public:
  NegateExpression(AbstractExpressionRef &&left)
      : UnaryExpression(left) {}

  RC evaluate(EnvRef env, Value &out_value) override
  {
    Value lhs;
    RC rc = get_child_at(0)->evaluate(env, lhs);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Left hand expression evaluate failed");
      return rc;
    }
    out_value = lhs.negation();
    if (out_value.get_type() == TypeId::UNDEFINED) {
      rc = RC::EVALUATE;
    }
    return rc;
  }

  auto convert_to_column(SchemaRef schema, Column &out_col) -> RC override
  {
    Column col;
    RC rc = children_[0]->convert_to_column(schema, col);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    out_col = {ColumnName(to_string()), col.get_type(), col.get_len()};
    return RC::SUCCESS;
  }

  std::string to_string() const override
  {
    assert(children_.size() == 1);
    std::string child = children_[0]->to_string();
    std::ostringstream oss;
    oss << "-" << "(" << child << ")";
    return oss.str();
  }

private:
};