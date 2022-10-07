#include "char_type.h"
#include "value.h"

auto CharType::compare_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) == 0};
}
auto CharType::compare_not_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) != 0};
}
auto CharType::compare_less_than(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) < 0};
}
auto CharType::compare_less_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) <= 0};
}
auto CharType::compare_greater_than(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) > 0};
}
auto CharType::compare_greater_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, compare(left, right) >= 0};
}

auto CharType::compare(const Value &left, const Value &right) const -> int
{
  std::string lhs = left.value_.char_.substr(0, left.get_len());
  std::string rhs = right.value_.char_.substr(0, right.get_len());
  if (lhs < rhs) {
    return -1;
  } else if (lhs > rhs) {
    return 1;
  } else {
    return 0;
  }
}

auto CharType::add(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto CharType::subtract(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto CharType::multiply(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto CharType::divide(const Value &left, const Value &right) const -> Value
{
  return Value{};
}

auto CharType::min(const Value &left, const Value &right) const -> Value
{
  return left.value_.char_ <= right.value_.char_ ? left : right;
}
auto CharType::max(const Value &left, const Value &right) const -> Value
{
  return left.value_.char_ >= right.value_.char_ ? left : right;
}

auto CharType::conjunction(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto CharType::disjunction(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto CharType::negation(const Value &value) const -> Value
{
  return Value{};
}

auto CharType::serialize_to(const Value &val, char *storage) const -> void
{
  memcpy(storage, val.value_.char_.c_str(), val.len_);
}
auto CharType::deserialize_from(const char *storage) const -> Value
{
  return {CHAR, storage, strlen(storage)};
}

auto CharType::to_string(const Value &val) const -> std::string
{
  return {};
}
