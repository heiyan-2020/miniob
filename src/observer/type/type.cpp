#include "type.h"
#include "value.h"

#include "char_type.h"
#include "int_type.h"
#include "float_type.h"
#include "date_type.h"
#include "bool_type.h"

Type *Type::k_types[] = {
    new Type{},
    new CharType{},
    new IntType{},
    new FloatType{},
    new DateType{},
    new BoolType{},
};

auto Type::compare_equals(const Value &left, const Value &right) const -> Value
{
  CHECK_NULL_CMP();
  return Value{};
}
auto Type::compare_not_equals(const Value &left, const Value &right) const -> Value
{
  CHECK_NULL_CMP();
  return Value{};
}
auto Type::compare_less_than(const Value &left, const Value &right) const -> Value
{
  CHECK_NULL_CMP();
  return Value{};
}
auto Type::compare_less_than_equals(const Value &left, const Value &right) const -> Value
{
  CHECK_NULL_CMP();
  return Value{};
}
auto Type::compare_greater_than(const Value &left, const Value &right) const -> Value
{
  CHECK_NULL_CMP();
  return Value{};
}
auto Type::compare_greater_than_equals(const Value &left, const Value &right) const -> Value
{
  CHECK_NULL_CMP();
  return Value{};
}

auto Type::compare(const Value &left, const Value &right) const -> CmpRes
{
  return CmpRes::UNDEFINED;
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

auto Type::serialize_to(const Value &val, char *storage) const -> void
{
  // do nothing
}
auto Type::deserialize_from(const char *storage, size_t length) const -> Value
{
  return Value{};
}

auto Type::to_string(const Value &val) const -> std::string
{
  return {};
}