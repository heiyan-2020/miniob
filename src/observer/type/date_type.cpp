#include "date_type.h"

auto DateType::compare_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, Date{(void *)left.value_.date_} == Date{(void *)right.value_.date_}};
}
auto DateType::compare_not_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, Date{(void *)left.value_.date_} != Date{(void *)right.value_.date_}};
}
auto DateType::compare_less_than(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, Date{(void *)left.value_.date_} < Date{(void *)right.value_.date_}};
}
auto DateType::compare_less_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, Date{(void *)left.value_.date_} <= Date{(void *)right.value_.date_}};
}
auto DateType::compare_greater_than(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, Date{(void *)left.value_.date_} > Date{(void *)right.value_.date_}};
}
auto DateType::compare_greater_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, Date{(void *)left.value_.date_} >= Date{(void *)right.value_.date_}};
}

auto DateType::add(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto DateType::subtract(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto DateType::multiply(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto DateType::divide(const Value &left, const Value &right) const -> Value
{
  return Value{};
}

auto DateType::min(const Value &left, const Value &right) const -> Value
{
  return Date{(void *)left.value_.date_} <= Date{(void *)right.value_.date_} <= 0 ? left : right;
}
auto DateType::max(const Value &left, const Value &right) const -> Value
{
  return Date{(void *)left.value_.date_} >= Date{(void *)right.value_.date_} <= 0 ? left : right;
}

auto DateType::conjunction(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto DateType::disjunction(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto DateType::negation(const Value &value) const -> Value
{
  return Value{};
}