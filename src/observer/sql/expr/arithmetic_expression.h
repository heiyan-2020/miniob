#pragma once
#include "abstract_expression.h"

class SymbolFinder;

class ArithmeticExpression : public AbstractExpression {
  friend SymbolFinder;

public:
public:
  ArithmeticExpression(AbstractExpressionRef &&left, AbstractExpressionRef &&right, OperatorType type)
      : AbstractExpression({std::move(left), std::move(right)}), ope_type_(type) {}

  RC evaluate(EnvRef env, Value &out_value) const override;

  AbstractExpressionRef traverse(ProcessorRef processor) override;

  auto convert_to_column(SchemaRef schema, Column &out_col) -> RC const override
  {
    RC rc;
    Column left, right;
    rc = children_[0]->convert_to_column(schema, left);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    rc = children_[1]->convert_to_column(schema, right);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    TypeId result_type = get_result_type(left.get_type(), right.get_type(), ope_type_);
    out_col = {ColumnName(to_string()), result_type, Type::get_type_size(result_type)};
    return RC::SUCCESS;
  }

  std::string to_string() const override
  {
    assert(children_.size() == 2);
    // always 2 children in testcases.
    std::string left = children_[0]->to_string();
    std::string right = children_[1]->to_string();

    if (ope_type_ == OperatorType::MUL || ope_type_ == OperatorType::SLASH) {
      std::shared_ptr<ArithmeticExpression> left_expr = std::dynamic_pointer_cast<ArithmeticExpression>(children_[0]);
      if (left_expr) {
        OperatorType left_ope_type = left_expr->ope_type_;
        if (left_ope_type == OperatorType::SUB || left_ope_type == OperatorType::PLUS) {
          left = "(" + left + ")";
        }
      }
      std::shared_ptr<ArithmeticExpression> right_expr = std::dynamic_pointer_cast<ArithmeticExpression>(children_[1]);
      if (right_expr) {
        OperatorType right_ope_type = right_expr->ope_type_;
        if (right_ope_type == OperatorType::SUB || right_ope_type == OperatorType::PLUS) {
          right = "(" + right + ")";
        }
      }
    }

    return left + AbstractExpression::op_to_string(ope_type_) + right;
  }

private:
  auto perform_arithmetic(const Value &lhs, const Value &rhs) const -> Value;
  auto get_result_type(TypeId lhs, TypeId rhs, OperatorType op_type) -> TypeId;

private:
  OperatorType ope_type_;
};