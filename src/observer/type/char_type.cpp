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
  std::string lhs{left.value_.char_};
  std::string rhs{right.value_.char_};
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
  return compare(left, right) <= 0 ? left : right;
}
auto CharType::max(const Value &left, const Value &right) const -> Value
{
  return compare(left, right) >= 0 ? left : right;
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
  for (size_t i = 0; i < val.len_; ++i) {
    storage[i] = val.value_.char_[i];
  }
}
auto CharType::deserialize_from(const char *storage, size_t length) const -> Value
{
  return {CHAR, storage, length};
}

auto CharType::to_string(const Value &val) const -> std::string
{
  return std::string{val.value_.char_};
}
