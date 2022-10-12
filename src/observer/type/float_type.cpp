#include "float_type.h"
#include "value.h"

#include <sstream>

const double epsilon = 1E-6;

auto FloatType::compare_equals(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res == CmpRes::EQ);
}
auto FloatType::compare_not_equals(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res != CmpRes::EQ);
}
auto FloatType::compare_less_than(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res == CmpRes::LT);
}
auto FloatType::compare_less_than_equals(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res != CmpRes::GT);
}
auto FloatType::compare_greater_than(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res == CmpRes::GT);
}
auto FloatType::compare_greater_than_equals(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res != CmpRes::LT);
}

auto FloatType::compare(const Value &left, const Value &right) const -> CmpRes
{
  switch (right.get_type()) {
    case TypeId::FLOAT:
      return cmp_float_helper(left.value_.float_, right.value_.float_);
    case TypeId::INT:
      return cmp_float_helper(left.value_.float_, (float) right.value_.int_);
    default:
      return CmpRes::UNDEFINED;
  }
}

auto FloatType::add(const Value &left, const Value &right) const -> Value
{
  switch (right.get_type()) {
    case TypeId::FLOAT:
      return Value{TypeId::FLOAT, left.value_.float_ + right.value_.float_};
    case TypeId::INT:
      return Value{TypeId::FLOAT, left.value_.float_ + right.value_.int_};
    default:
      return Value{};
  }
}
auto FloatType::subtract(const Value &left, const Value &right) const -> Value
{
  switch (right.get_type()) {
    case TypeId::FLOAT:
      return Value{TypeId::FLOAT, left.value_.float_ - right.value_.float_};
    case TypeId::INT:
      return Value{TypeId::FLOAT, left.value_.float_ - right.value_.int_};
    default:
      return Value{};
  }
}
auto FloatType::multiply(const Value &left, const Value &right) const -> Value
{
  switch (right.get_type()) {
    case TypeId::FLOAT:
      return Value{TypeId::FLOAT, left.value_.float_ * right.value_.float_};
    case TypeId::INT:
      return Value{TypeId::FLOAT, left.value_.float_ * right.value_.int_};
    default:
      return Value{};
  }
}
auto FloatType::divide(const Value &left, const Value &right) const -> Value
{
  switch (right.get_type()) {
    case TypeId::FLOAT:
      return FloatType::div_float_helper(left.value_.float_, right.value_.float_);
    case TypeId::INT:
      return FloatType::div_float_helper(left.value_.float_, right.value_.int_);
    default:
      return Value{};
  }
}

auto FloatType::min(const Value &left, const Value &right) const -> Value
{
  return Value{FLOAT, std::min(left.value_.float_, right.value_.float_)};
}
auto FloatType::max(const Value &left, const Value &right) const -> Value
{
  return Value{FLOAT, std::max(left.value_.float_, right.value_.float_)};
}

auto FloatType::conjunction(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto FloatType::disjunction(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto FloatType::negation(const Value &value) const -> Value
{
  return Value{FLOAT, -value.value_.float_};
}

auto FloatType::serialize_to(const Value &val, char *storage) const -> void
{
  *reinterpret_cast<float *>(storage) = val.value_.float_;
}
auto FloatType::deserialize_from(const char *storage, size_t length) const -> Value
{
  float val = *reinterpret_cast<const float *>(storage);
  return {FLOAT, val};
}

auto FloatType::to_string(const Value &val) const -> std::string
{
  std::ostringstream oss;
  oss << val.value_.float_;
  return std::string{oss.str()};
}

auto FloatType::cmp_float_helper(const float lhs, const float rhs) -> CmpRes
{
  float cmp = lhs - rhs;
  if (cmp > epsilon) {
    return CmpRes::GT;
  }
  if (cmp < -epsilon) {
    return CmpRes::LT;
  }
  return CmpRes::EQ;
}

auto FloatType::div_float_helper(const float lhs, const float rhs) -> Value
{
  if (rhs < epsilon && rhs > -epsilon) {
    return Value{}; // divide zero -> undefined
  }
  return Value{FLOAT, lhs / rhs};
}