#pragma once

#include "environment.h"
#include "type/type.h"
#include "sql/parser/hsql/sql/Expr.h"
#include "expression_processor.h"
#include "util/macros.h"

enum class OperatorType { Equal, NotEqual, LessThan, LessThanOrEqual, GreaterThan, GreaterThanOrEqual, NOT, AND, OR, PLUS, SUB, MUL, SLASH, NEG, IsNull, IN, LIKE};

class AbstractExpression;
using AbstractExpressionRef = std::shared_ptr<AbstractExpression>;

class AbstractExpression : public std::enable_shared_from_this<AbstractExpression>{
public:
  AbstractExpression(std::vector<AbstractExpressionRef> &&children)
      : children_{std::move(children)} {}

  // dummy expression.
  AbstractExpression() = default;

  virtual ~AbstractExpression() = default;

  virtual RC evaluate(EnvRef env, Value &out_value) = 0;

  AbstractExpressionRef get_child_at(uint32_t child_idx) const { return children_[child_idx]; }

  virtual RC traverse(ProcessorRef processor, AbstractExpressionRef &out_value) = 0;

  std::vector<ColumnName> get_all_symbols();

  virtual auto convert_to_column(SchemaRef schema, Column &out_col) -> RC = 0;

  virtual std::string to_string() const = 0;

  static auto op_to_string(OperatorType op_type) -> std::string;

  // create expression according to the operator type.
  static RC expression_factory(AbstractExpressionRef lhs, AbstractExpressionRef rhs, OperatorType ope_type, AbstractExpressionRef &out);

protected:
  std::vector<AbstractExpressionRef> children_;
};