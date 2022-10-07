#include "int_type.h"
#include "value.h"

auto IntType::compare_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) == 0};
}
auto IntType::compare_not_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) != 0};
}
auto IntType::compare_less_than(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) < 0};
}
auto IntType::compare_less_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) <= 0};
}
auto IntType::compare_greater_than(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) > 0};
}
auto IntType::compare_greater_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) >= 0};
}

auto IntType::compare(const Value &left, const Value &right) const -> int
{
  if (left.value_.int_ < right.value_.int_) {
    return -1;
  } else if (left.value_.int_ > right.value_.int_) {
    return 1;
  } else {
    return 0;
  }
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

auto IntType::serialize_to(const Value &val, char *storage) const -> void
{
  *reinterpret_cast<int32_t *>(storage) = val.value_.int_;
}
auto IntType::deserialize_from(const char *storage) const -> Value
{
  int32_t val = *reinterpret_cast<const int32_t *>(storage);
  return {INT, val};
}
