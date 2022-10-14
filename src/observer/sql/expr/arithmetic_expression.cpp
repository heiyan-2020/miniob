#include "arithmetic_expression.h"

RC ArithmeticExpression::evaluate(EnvRef env, Value &out_value)
{
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
  out_value = perform_arithmetic(lhs, rhs);
  //  if (out_value.get_type() == TypeId::UNDEFINED) {
  //    rc = RC::EVALUATE;
  //  }
  return rc;
}

auto ArithmeticExpression::perform_arithmetic(const Value &lhs, const Value &rhs) const -> Value
{
  if (lhs.is_null() || rhs.is_null()) {
    return Value{};
  }
  switch (ope_type_) {
    case OperatorType::PLUS:
      return lhs.add(rhs);
    case OperatorType::SUB:
      return lhs.subtract(rhs);
    case OperatorType::MUL:
      return lhs.multiply(rhs);
    case OperatorType::SLASH:
      return lhs.divide(rhs);
    default: {
      LOG_PANIC("Unsupported arithmetic operator: %d", ope_type_);
      return Value{};
    }
  }
}

auto ArithmeticExpression::get_result_type(TypeId lhs, TypeId rhs, OperatorType op_type) -> TypeId
{
  TypeId type_order[] = {
      TypeId::FLOAT, TypeId::INT
  };

  if (op_type == OperatorType::SLASH || op_type == OperatorType::MUL) {
    return TypeId::FLOAT;
  }

  for (auto type : type_order) {
    if (type == lhs || type == rhs) {
      return type;
    }
  }

  // Just guess INTEGER.  Works for C...
  return TypeId::INT;
}