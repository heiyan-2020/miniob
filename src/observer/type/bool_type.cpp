#include "bool_type.h"
#include "value.h"

auto BoolType::compare_equals(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto BoolType::compare_not_equals(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto BoolType::compare_less_than(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto BoolType::compare_less_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto BoolType::compare_greater_than(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto BoolType::compare_greater_than_equals(const Value &left, const Value &right) const -> Value
{
  return Value{};
}

auto BoolType::compare(const Value &left, const Value &right) const -> CmpRes
{
  return Type::compare(left, right);
}

auto BoolType::add(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto BoolType::subtract(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto BoolType::multiply(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto BoolType::divide(const Value &left, const Value &right) const -> Value
{
  return Value{};

}

auto BoolType::min(const Value &left, const Value &right) const -> Value
{
  return Value{};
}
auto BoolType::max(const Value &left, const Value &right) const -> Value
{
  return Value{};
}

auto BoolType::conjunction(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, left.value_.bool_ and right.value_.bool_};
}
auto BoolType::disjunction(const Value &left, const Value &right) const -> Value
{
  return Value{BOOL, left.value_.bool_ or right.value_.bool_};
}
auto BoolType::negation(const Value &value) const -> Value
{
  return Value{BOOL, not value.value_.bool_};
}

auto BoolType::serialize_to(const Value &val, char *storage) const -> void
{
  Type::serialize_to(val, storage);
}
auto BoolType::deserialize_from(const char *storage, size_t length) const -> Value
{
  return Type::deserialize_from(storage, length);
}

auto BoolType::to_string(const Value &val) const -> std::string
{
  return {};
}