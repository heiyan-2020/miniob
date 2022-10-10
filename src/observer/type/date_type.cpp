#include "date_type.h"
#include "value.h"

auto DateType::compare_equals(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res == CmpRes::EQ);
}
auto DateType::compare_not_equals(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res != CmpRes::EQ);
}
auto DateType::compare_less_than(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res == CmpRes::LT);
}
auto DateType::compare_less_than_equals(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res != CmpRes::GT);
}
auto DateType::compare_greater_than(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res == CmpRes::GT);
}
auto DateType::compare_greater_than_equals(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res != CmpRes::LT);
}

auto DateType::compare(const Value &left, const Value &right) const -> CmpRes
{
  switch (right.get_type()) {
    case TypeId::DATE: {
      Date lhs{(void *)(left.value_.date_)};
      Date rhs{(void *)(right.value_.date_)};
      if (!lhs.validate() || !rhs.validate()) {
        return CmpRes::UNDEFINED;
      }
      if (lhs < rhs) {
        return CmpRes::LT;
      } else if (lhs > rhs) {
        return CmpRes::GT;
      } else {
        return CmpRes::EQ;
      }
    }
    default:
      return CmpRes::UNDEFINED;
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
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  if (res != CmpRes::GT) {
    return left;
  } else {
    return right;
  }
}
auto DateType::max(const Value &left, const Value &right) const -> Value
{
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  if (res != CmpRes::LT) {
    return left;
  } else {
    return right;
  }
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
