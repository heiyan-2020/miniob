#include "char_type.h"
#include "value.h"
#include "util/type_converter.h"

auto CharType::compare_equals(const Value &left, const Value &right) const -> Value
{
  CHECK_NULL_CMP();
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res == CmpRes::EQ);
}
auto CharType::compare_not_equals(const Value &left, const Value &right) const -> Value
{
  CHECK_NULL_CMP();
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res != CmpRes::EQ);
}
auto CharType::compare_less_than(const Value &left, const Value &right) const -> Value
{
  CHECK_NULL_CMP();
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res == CmpRes::LT);
}
auto CharType::compare_less_than_equals(const Value &left, const Value &right) const -> Value
{
  CHECK_NULL_CMP();
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res != CmpRes::GT);
}
auto CharType::compare_greater_than(const Value &left, const Value &right) const -> Value
{
  CHECK_NULL_CMP();
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res == CmpRes::GT);
}
auto CharType::compare_greater_than_equals(const Value &left, const Value &right) const -> Value
{
  CHECK_NULL_CMP();
  auto res = compare(left, right);
  if (res == CmpRes::UNDEFINED) {
    return Value{};
  }
  return bool_to_value(res != CmpRes::LT);
}

auto CharType::compare(const Value &left, const Value &right) const -> CmpRes
{
  switch (right.get_type()) {
    case TypeId::CHAR: {
      size_t min_len = std::min(left.len_, right.len_);
      auto res = strncmp(left.value_.char_, right.value_.char_, min_len);
      if (res < 0) {
        return CmpRes::LT;
      } else if (res > 0) {
        return CmpRes::GT;
      } else {
        if (left.len_ < right.len_ && right.value_.char_[left.len_] != 0) {
          return CmpRes::LT;
        } else if (left.len_ > right.len_ && left.value_.char_[right.len_] != 0) {
          return CmpRes::GT;
        } else {
          return CmpRes::EQ;
        }
      }
    }
    case TypeId::INT: {
      // 字符串和整数比较, 先将字符串转换为整数
      return TypeConverter::get_from_char(INT, left.value_.char_, left.len_).compare(right);
    }
    case TypeId::FLOAT: {
      return TypeConverter::get_from_char(FLOAT, left.value_.char_, left.len_).compare(right);
    }
    default:
      return CmpRes::UNDEFINED;
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
auto CharType::max(const Value &left, const Value &right) const -> Value
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
