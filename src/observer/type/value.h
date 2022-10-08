#pragma once

#include "type_id.h"
#include "type.h"
#include "util/macros.h"

#include <cstddef>
#include <string>
#include <cstring>
#include <cstdlib>

class TableScanNode;

class Value {
  friend class Type;
  friend class CharType;
  friend class IntType;
  friend class FloatType;
  friend class DateType;
  friend class BoolType;
  friend class TableScanNode;

public:
  Value() : Value{TypeId::UNDEFINED}
  {}
  explicit Value(const TypeId type) : type_id_{type}, len_{Type::get_type_size(type)}
  {}
  ~Value()
  {
    if (type_id_ == CHAR) {
      // double free
      if (value_.char_ != nullptr) {
        free(value_.char_);
      }
      value_.char_ = nullptr;
    }
  }

  Value(TypeId type, bool b) : type_id_{type}, len_{Type::get_type_size(type)}
  {
    value_.bool_ = b;
  }
  Value(TypeId type, int32_t i) : type_id_{type}, len_{Type::get_type_size(type)}
  {
    value_.int_ = i;
  }
  Value(TypeId type, float f) : type_id_{type}, len_{Type::get_type_size(type)}
  {
    value_.float_ = f;
  }
  Value(TypeId type, const int32_t *d) : type_id_{type}, len_{Type::get_type_size(type)}
  {
    memcpy(value_.date_, d, sizeof(int32_t[3]));
  }
  Value(TypeId type, const char *c, size_t len) : type_id_{type}, len_{len}
  {
    value_.char_ = (char *)calloc(len + 1, sizeof(char));
    memcpy(value_.char_, c, std::min(len, strlen(c)));
  }

  auto get_type() const -> TypeId
  {
    return type_id_;
  }
  auto get_len() const -> size_t
  {
    return len_;
  }

  auto compare_equals(const Value &o) const -> Value;
  auto compare_not_equals(const Value &o) const -> Value;
  auto compare_less_than(const Value &o) const -> Value;
  auto compare_less_than_equals(const Value &o) const -> Value;
  auto compare_greater_than(const Value &o) const -> Value;
  auto compare_greater_than_equals(const Value &o) const -> Value;

  auto compare(const Value &o) const -> int;

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
  auto deserialize_from(const char *storage) -> Value;

  auto to_string() const -> std::string;

//  DISALLOW_COPY(Value);

protected:
  TypeId type_id_;

  union Val {
    bool bool_;
    int32_t int_;
    float float_;
    int32_t date_[3];
    char *char_;
  } value_{};

  size_t len_{};

  // TODO
  bool is_null_{};
};