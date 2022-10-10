#include "float_type.h"
#include "value.h"

#include <sstream>

const double epsilon = 1E-6;

auto FloatType::compare_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) == 0};
}
auto FloatType::compare_not_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) != 0};
}
auto FloatType::compare_less_than(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) < 0};
}
auto FloatType::compare_less_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) <= 0};
}
auto FloatType::compare_greater_than(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) > 0};
}
auto FloatType::compare_greater_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) >= 0};
}

auto FloatType::compare(const Value &left, const Value &right) const -> int
{
  float cmp = left.value_.float_ - right.value_.float_;
  if (cmp > epsilon) {
    return 1;
  }
  if (cmp < -epsilon) {
    return -1;
  }
  return 0;
}

auto FloatType::add(const Value &left, const Value &right) const -> Value
{
  return Value{FLOAT, left.value_.float_ + right.value_.float_};
}
auto FloatType::subtract(const Value &left, const Value &right) const -> Value
{
  return Value{FLOAT, left.value_.float_ - right.value_.float_};
}
auto FloatType::multiply(const Value &left, const Value &right) const -> Value
{
  return Value{FLOAT, left.value_.float_ * right.value_.float_};
}
auto FloatType::divide(const Value &left, const Value &right) const -> Value
{
  if (right.value_.float_ == 0) {
    return Value{};
  }
  return Value{FLOAT, left.value_.float_ / right.value_.float_};
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
auto FloatType::deserialize_from(const char *storage) const -> Value
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