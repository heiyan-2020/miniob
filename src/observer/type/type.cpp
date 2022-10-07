#include "type.h"
#include "value.h"

auto Type::compare_equals(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto Type::compare_not_equals(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto Type::compare_less_than(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto Type::compare_less_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto Type::compare_greater_than(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto Type::compare_greater_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{};
}

auto Type::add(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto Type::subtract(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto Type::multiply(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto Type::divide(const Value &left, const Value &right) const -> Value
{
  return Value{};
}

auto Type::min(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto Type::max(const Value &left, const Value &right) const -> Value
{
  return Value{};
}

auto Type::conjunction(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto Type::disjunction(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto Type::negation(const Value &value) const -> Value
{
  return Value{};
}