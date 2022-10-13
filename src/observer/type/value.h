#pragma once

#include "type_id.h"
#include "type.h"

#include <cstddef>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>

class TableScanNode;
class NestedLoopJoinNode;
class BoolExpression;

class Value {
  friend class Type;
  friend class CharType;
  friend class IntType;
  friend class FloatType;
  friend class DateType;
  friend class BoolType;
  friend class TableScanNode;
  friend class NestedLoopJoinNode;
  friend class BoolExpression;

public:
  Value() : Value{TypeId::UNDEFINED}
  {}
  explicit Value(const TypeId type) : type_id_{type}, is_null_{true}
  {}
  ~Value()
  {
    if (type_id_ == CHAR) {
      if (value_.char_ != nullptr) {
        free(value_.char_);
      }
      value_.char_ = nullptr;
    }
  }
  Value(const Value &o)
  {
    this->type_id_ = o.type_id_;
    this->is_null_ = o.is_null_;
    if (o.type_id_ == CHAR) {
      this->len_ = o.len_;
      this->value_.char_ = (char *)calloc(o.len_, sizeof(char));
      memcpy(this->value_.char_, o.value_.char_, this->len_);
    } else {
      this->value_ = o.value_;
    }
  }
  Value &operator=(const Value &o)
  {
    this->~Value();
    new (this) Value{o};
    return *this;
  }

  Value(TypeId type, bool b) : type_id_{type}
  {
    value_.bool_ = b;
  }
  Value(TypeId type, int32_t i) : type_id_{type}
  {
    value_.int_ = i;
  }
  Value(TypeId type, float f) : type_id_{type}
  {
    value_.float_ = f;
  }
  Value(TypeId type, const int32_t *d) : type_id_{type}
  {
    memcpy(value_.date_, d, sizeof(int32_t[3]));
  }
  Value(TypeId type, const char *c, size_t len) : type_id_{type}
  {
    this->len_ = len;
    this->value_.char_ = (char *)calloc(len + 1, sizeof(char));  // one more to occupy '\0'
    size_t min_len = std::min(len, strnlen(c, len));
    memcpy(this->value_.char_, c, min_len);
  }

  auto get_type() const -> TypeId
  {
    return type_id_;
  }
  auto get_len() const -> size_t
  {
    if (type_id_ == CHAR) {
      return len_;
    }
    return Type::get_type_size(type_id_);
  }
  auto is_null() const -> bool
  {
    return is_null_;
  }

  auto compare_equals(const Value &o) const -> Value;
  auto compare_not_equals(const Value &o) const -> Value;
  auto compare_less_than(const Value &o) const -> Value;
  auto compare_less_than_equals(const Value &o) const -> Value;
  auto compare_greater_than(const Value &o) const -> Value;
  auto compare_greater_than_equals(const Value &o) const -> Value;

  auto compare(const Value &o) const -> CmpRes;

  auto add(const Value &o) const -> Value;
  auto subtract(const Value &o) const -> Value;
  auto multiply(const Value &o) const -> Value;
  auto divide(const Value &o) const -> Value;

  auto min(const Value &o) const -> Value;
  auto max(const Value &o) const -> Value;

  auto conjunction(const Value &o) const -> Value;
  auto disjunction(const Value &o) const -> Value;
  auto negation() const -> Value;

  auto serialize_to(char *storage) const -> void;
  auto deserialize_from(const char *storage, size_t length) -> Value;

  auto to_string() const -> std::string;

protected:
  TypeId type_id_;

  union {
    bool bool_;
    int32_t int_;
    float float_;
    int32_t date_[3];
    char *char_;
  } value_{};

  // for CHAR type
  size_t len_{};

  bool is_null_{};
};

inline auto bool_to_value(bool boolean) -> Value
{
  return boolean ? Value{TypeId::BOOL, true} : Value{TypeId::BOOL, false};
}

inline auto cmp_res_to_int(CmpRes res) -> int
{
  if (res == CmpRes::LT) {
    return -1;
  } else if (res == CmpRes::GT) {
    return 1;
  } else {
    // TODO(vgalaxy): undefined
    return 0;
  }
}