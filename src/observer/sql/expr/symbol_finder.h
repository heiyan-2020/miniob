#pragma once

#include "expression_processor.h"
#include "column_value_expression.h"

class SymbolFinder : public ExpressionProcessor {
  friend class AbstractExpression;
public:
  void enter(AbstractExpressionRef node) override
  {
    if (std::dynamic_pointer_cast<ColumnValueExpression>(node)) {
      std::shared_ptr<ColumnValueExpression> expr = std::dynamic_pointer_cast<ColumnValueExpression>(node);
      ColumnName col_name = expr->col_name_;
      if (!col_name.is_wild_card()) {
        symbols_.push_back(col_name);
      }
    }
  }

  AbstractExpressionRef leave(AbstractExpressionRef node) override
  {
    return node;
  }


private:
  std::vector<ColumnName> symbols_;
};