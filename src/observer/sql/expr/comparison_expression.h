#pragma once
#include "abstract_expression.h"

class ComparisonExpression : public AbstractExpression {
public:
  ComparisonExpression(AbstractExpressionRef &&left, AbstractExpressionRef &&right, OperatorType comp_type)
      : AbstractExpression({std::move(left), std::move(right)}), comp_type_{comp_type} {}

  RC evaluate(EnvRef env, Value &out_value) const  override {
    Value lhs, rhs;
    RC rc = get_child_at(0)->evaluate(env, lhs);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Left hand expression evaluate failed");
      return rc;
    }
    rc = get_child_at(1)->evaluate(env, rhs);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Right hand expression evaluate failed");
      return rc;
    }
    out_value = perform_comparison(lhs, rhs);
    if (out_value.get_type() == TypeId::UNDEFINED) {
      rc = RC::EVALUATE;
    }
    return rc;
  }

  AbstractExpressionRef traverse(ProcessorRef processor) override
  {
    std::shared_ptr<AbstractExpression> sp = shared_from_this();
    processor->enter(sp);
    children_[0] = children_[0]->traverse(processor);
    children_[1] = children_[1]->traverse(processor);
    return processor->leave(sp);
  }

  auto convert_to_column(SchemaRef schema, Column &out_col) -> RC const override
  {
    out_col = {ColumnName(to_string()), TypeId::BOOL, Type::get_type_size( TypeId::BOOL)};
    return RC::SUCCESS;
  }

  std::string to_string() const override
  {
    std::string left = children_[0]->to_string();
    std::string right = children_[1]->to_string();
    return left + " " + AbstractExpression::op_to_string(comp_type_) + " " + right;
  }

private:
  OperatorType comp_type_;

private:
  auto perform_comparison(const Value &lhs, const Value &rhs) const -> Value {
    switch (comp_type_) {
      case OperatorType::Equal:
        return lhs.compare_equals(rhs);
      case OperatorType::NotEqual:
        return lhs.compare_not_equals(rhs);
      case OperatorType::LessThan:
        return lhs.compare_less_than(rhs);
      case OperatorType::LessThanOrEqual:
        return lhs.compare_less_than_equals(rhs);
      case OperatorType::GreaterThan:
        return lhs.compare_greater_than(rhs);
      case OperatorType::GreaterThanOrEqual:
        return lhs.compare_greater_than_equals(rhs);
      default:
        LOG_ERROR("Evaluate compare failed");
        assert(false);
    }
  }
};
