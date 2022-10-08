#pragma once
#include "abstract_expression.h"

enum class ComparisonType { Equal, NotEqual, LessThan, LessThanOrEqual, GreaterThan, GreaterThanOrEqual };

class ComparisonExpression : public AbstractExpression {
public:
  ComparisonExpression(AbstractExpressionRef left, AbstractExpressionRef right, ComparisonType comp_type)
      : AbstractExpression({std::move(left), std::move(right)}, TypeId::BOOL), comp_type_{comp_type} {}

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
    return rc;
  }

private:
  ComparisonType comp_type_;

private:
  auto perform_comparison(const Value &lhs, const Value &rhs) const -> Value {
    switch (comp_type_) {
      case ComparisonType::Equal:
        return lhs.compare_equals(rhs);
      case ComparisonType::NotEqual:
        return lhs.compare_not_equals(rhs);
      case ComparisonType::LessThan:
        return lhs.compare_less_than(rhs);
      case ComparisonType::LessThanOrEqual:
        return lhs.compare_less_than_equals(rhs);
      case ComparisonType::GreaterThan:
        return lhs.compare_greater_than(rhs);
      case ComparisonType::GreaterThanOrEqual:
        return lhs.compare_greater_than_equals(rhs);
      default:
        LOG_ERROR("Evaluate compare failed");
    }
  }
};
