#include "int_type.h"
#include "value.h"

auto IntType::compare_equals(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res == CmpRes::EQ);
}
auto IntType::compare_not_equals(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res != CmpRes::EQ);
}
auto IntType::compare_less_than(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res == CmpRes::LT);
}
auto IntType::compare_less_than_equals(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res != CmpRes::GT);
}
auto IntType::compare_greater_than(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res == CmpRes::GT);
}
auto IntType::compare_greater_than_equals(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res != CmpRes::LT);
}

auto IntType::compare(const Value &left, const Value &right) const -> CmpRes
{
  switch (right.get_type()) {
    case TypeId::INT:
      if (left.value_.int_ < right.value_.int_) {
        return CmpRes::LT;
      } else if (left.value_.int_ > right.value_.int_) {
        return CmpRes::GT;
      } else {
        return CmpRes::EQ;
      }
    default:
      return CmpRes::UNDEFINED;
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
  // Return a floating number according to test case.
  return Value{FLOAT, (float) left.value_.int_ / (float) right.value_.int_};
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
auto IntType::deserialize_from(const char *storage, size_t length) const -> Value
{
  int32_t val = *reinterpret_cast<const int32_t *>(storage);
  return {INT, val};
}

auto IntType::to_string(const Value &val) const -> std::string
{
  // TODO(zyx): check null.
  return std::to_string(val.value_.int_);
}
