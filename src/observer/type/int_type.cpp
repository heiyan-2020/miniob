#include "int_type.h"

auto IntType::compare_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, left.value_.int_ == right.value_.int_};
}
auto IntType::compare_not_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, left.value_.int_ != right.value_.int_};
}
auto IntType::compare_less_than(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, left.value_.int_ < right.value_.int_};
}
auto IntType::compare_less_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, left.value_.int_ <= right.value_.int_};
}
auto IntType::compare_greater_than(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, left.value_.int_ > right.value_.int_};
}
auto IntType::compare_greater_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, left.value_.int_ >= right.value_.int_};
}

auto IntType::add(const Value &left, const Value &right) const -> Value
{
  return Value{INT, left.value_.int_ + right.value_.int_};
}
auto IntType::subtract(const Value &left, const Value &right) const -> Value
{
  return Value{INT, left.value_.int_ - right.value_.int_};
}
auto IntType::multiply(const Value &left, const Value &right) const -> Value
{
  return Value{INT, left.value_.int_ * right.value_.int_};
}
auto IntType::divide(const Value &left, const Value &right) const -> Value
{
  if (right.value_.int_ == 0) {
    return Value{};
  }
  return Value{INT, left.value_.int_ / right.value_.int_};
}

auto IntType::min(const Value &left, const Value &right) const -> Value
{
  return Value{INT, std::min(left.value_.int_, right.value_.int_)};
}
auto IntType::max(const Value &left, const Value &right) const -> Value
{
  return Value{INT, std::max(left.value_.int_, right.value_.int_)};
}

auto IntType::conjunction(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto IntType::disjunction(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto IntType::negation(const Value &value) const -> Value
{
  return Value{INT, -value.value_.int_};
}