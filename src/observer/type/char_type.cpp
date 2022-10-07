#include "char_type.h"
#include "value.h"

auto CharType::compare_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, strcmp(left.value_.char_, right.value_.char_) == 0};
}
auto CharType::compare_not_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, strcmp(left.value_.char_, right.value_.char_) != 0};
}
auto CharType::compare_less_than(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, strcmp(left.value_.char_, right.value_.char_) < 0};
}
auto CharType::compare_less_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, strcmp(left.value_.char_, right.value_.char_) <= 0};
}
auto CharType::compare_greater_than(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, strcmp(left.value_.char_, right.value_.char_) > 0};
}
auto CharType::compare_greater_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, strcmp(left.value_.char_, right.value_.char_) >= 0};
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
  return strcmp(left.value_.char_, right.value_.char_) <= 0 ? left : right;
}
auto CharType::max(const Value &left, const Value &right) const -> Value
{
  return strcmp(left.value_.char_, right.value_.char_) >= 0 ? left : right;
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
  memcpy(storage, val.value_.char_, val.len_);
}
auto CharType::deserialize_from(const char *storage) const -> Value
{
  return Value{CHAR, storage, strlen(storage)};
}
