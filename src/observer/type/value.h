#pragma once

#include "type_id.h"

#include <cstddef>
#include <string>
#include <cstring>

class Value {
  friend class Type;
  friend class CharType;
  friend class IntType;
  friend class FloatType;
  friend class DateType;
  friend class BoolType;

public:
  Value() : Value{TypeId::UNDEFINED}
  {}
  explicit Value(const TypeId type) : type_id_{type}
  {}

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
  Value(TypeId type, const int32_t d[3]) : type_id_{type}
  {
    memcpy(value_.date_, d, sizeof(int32_t[3]));
  }
  Value(TypeId type, const char *c, size_t len = 4) : type_id_{type}, len_{len}
  {
    value_.char_ = std::string{c};
  }

  auto compare_equals(const Value &o) const -> Value;
  auto compare_not_equals(const Value &o) const -> Value;
  auto compare_less_than(const Value &o) const -> Value;
  auto compare_less_than_equals(const Value &o) const -> Value;
  auto compare_greater_than(const Value &o) const -> Value;
  auto compare_greater_than_equals(const Value &o) const -> Value;

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

protected:
  TypeId type_id_;

  // TODO(vgalaxy): use union
  struct Val {
    bool bool_{};
    int32_t int_{};
    float float_{};
    int32_t date_[3]{};
    std::string char_{};
  } value_{};

  size_t len_{};

  // TODO
  bool is_null_{};
};