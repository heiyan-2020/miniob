#include "date_type.h"
#include "value.h"

#define DATE_COMPARE_FUNC(OP)             \
  Date lhs{(void *)(left.value_.date_)};  \
  Date rhs{(void *)(right.value_.date_)}; \
  if (lhs.validate() && rhs.validate()) { \
    switch (right.get_type()) {           \
      case TypeId::DATE:                  \
        return bool_to_value(lhs OP rhs); \
      default :                           \
        break;                            \
    }                                     \
}


auto DateType::compare_equals(const Value &left, const Value &right) const -> Value
{
  DATE_COMPARE_FUNC(==)
  return {};
}
auto DateType::compare_not_equals(const Value &left, const Value &right) const -> Value
{
  DATE_COMPARE_FUNC(!=)
  return {};
}
auto DateType::compare_less_than(const Value &left, const Value &right) const -> Value
{
  DATE_COMPARE_FUNC(<)
  return {};
}
auto DateType::compare_less_than_equals(const Value &left, const Value &right) const -> Value
{
  DATE_COMPARE_FUNC(<=)
  return {};
}
auto DateType::compare_greater_than(const Value &left, const Value &right) const -> Value
{
  DATE_COMPARE_FUNC(>)
  return {};
}
auto DateType::compare_greater_than_equals(const Value &left, const Value &right) const -> Value
{
  DATE_COMPARE_FUNC(>=)
  return {};
}

auto DateType::compare(const Value &left, const Value &right) const -> int
{
  Date lhs{(void *)(left.value_.date_)};
  Date rhs{(void *)(right.value_.date_)};
  // TODO(vgalaxy): validate
  if (lhs < rhs) {
    return -1;
  } else if (lhs > rhs) {
    return 1;
  } else {
    return 0;
  }
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
  return compare(left, right) <= 0 ? left : right;
}
auto DateType::max(const Value &left, const Value &right) const -> Value
{
  return compare(left, right) >= 0 ? left : right;
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

auto DateType::serialize_to(const Value &val, char *storage) const -> void
{
  auto *trans = reinterpret_cast<int32_t *>(storage);
  trans[0] = val.value_.date_[0];
  trans[1] = val.value_.date_[1];
  trans[2] = val.value_.date_[2];
}
auto DateType::deserialize_from(const char *storage, size_t length) const -> Value
{
  return {DATE, reinterpret_cast<const int32_t *>(storage)};
}

auto DateType::to_string(const Value &val) const -> std::string
{
  return Date{(void *)val.value_.date_}.to_string();
}
