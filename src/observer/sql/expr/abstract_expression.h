#pragma once

#include "environment.h"
#include "type/type.h"
#include "sql/parser/hsql/sql/Expr.h"
#include "expression_processor.h"

class AbstractExpression;
using AbstractExpressionRef = std::shared_ptr<AbstractExpression>;

class AbstractExpression : public std::enable_shared_from_this<AbstractExpression>{
public:
  AbstractExpression(std::vector<AbstractExpressionRef> &&children, TypeId ret_type)
      : children_{std::move(children)}, ret_type_{ret_type} {}

  // dummy expression.
  AbstractExpression() = default;

  virtual ~AbstractExpression() = default;

  virtual RC evaluate(EnvRef env, Value &out_value) const = 0;

  AbstractExpressionRef get_child_at(uint32_t child_idx) const { return children_[child_idx]; }

  virtual TypeId get_return_type() const { return ret_type_; }

  virtual AbstractExpressionRef traverse(ProcessorRef processor) = 0;

  std::vector<ColumnName> getAllSymbols();

protected:
  std::vector<AbstractExpressionRef> children_;
  TypeId ret_type_;
};