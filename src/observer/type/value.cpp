#include "value.h"
#include "type.h"

auto Value::compare_equals(const Value &o) const -> Value
{
  return Type::get_instance(type_id_)->compare_equals(*this, o);
}
auto Value::compare_not_equals(const Value &o) const -> Value
{
  return Type::get_instance(type_id_)->compare_not_equals(*this, o);
}
auto Value::compare_less_than(const Value &o) const -> Value
{
  return Type::get_instance(type_id_)->compare_less_than(*this, o);
}
auto Value::compare_less_than_equals(const Value &o) const -> Value
{
  return Type::get_instance(type_id_)->compare_less_than_equals(*this, o);
}
auto Value::compare_greater_than(const Value &o) const -> Value
{
  return Type::get_instance(type_id_)->compare_greater_than(*this, o);
}
auto Value::compare_greater_than_equals(const Value &o) const -> Value
{
  return Type::get_instance(type_id_)->compare_greater_than_equals(*this, o);
}

auto Value::add(const Value &o) const -> Value
{
  return Type::get_instance(type_id_)->add(*this, o);
}
auto Value::subtract(const Value &o) const -> Value
{
  return Type::get_instance(type_id_)->subtract(*this, o);
}
auto Value::multiply(const Value &o) const -> Value
{
  return Type::get_instance(type_id_)->multiply(*this, o);
}
auto Value::divide(const Value &o) const -> Value
{
  return Type::get_instance(type_id_)->divide(*this, o);
}

auto Value::min(const Value &o) const -> Value
{
  return Type::get_instance(type_id_)->min(*this, o);
}
auto Value::max(const Value &o) const -> Value
{
  return Type::get_instance(type_id_)->max(*this, o);
}

auto Value::conjunction(const Value &o) const -> Value
{
  return Type::get_instance(type_id_)->conjunction(*this, o);
}
auto Value::disjunction(const Value &o) const -> Value
{
  return Type::get_instance(type_id_)->disjunction(*this, o);
}
auto Value::negation() const -> Value
{
  return Type::get_instance(type_id_)->negation(*this);
}

auto Value::serialize_to(char *storage) const -> void
{
  Type::get_instance(type_id_)->serialize_to(*this, storage);
}
auto Value::deserialize_from(const char *storage) -> Value
{
  return Type::get_instance(type_id_)->deserialize_from(storage);
}
