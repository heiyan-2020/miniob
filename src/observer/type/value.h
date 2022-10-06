#pragma once

#include "type_id.h"
#include "type.h"

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
  Value(TypeId type, int32_t d[3]) : type_id_{type}
  {
    memcpy(value_.date_, d, sizeof(int32_t[3]));
  }
  Value(TypeId type, char *c) : type_id_{type}
  {
    value_.char_ = c;
  }

  auto compare_equals(const Value &o) const -> Value
  {
    return Type::get_instance(type_id_)->compare_equals(*this, o);
  }
  auto compare_not_equals(const Value &o) const -> Value
  {
    return Type::get_instance(type_id_)->compare_not_equals(*this, o);
  }
  auto compare_less_than(const Value &o) const -> Value
  {
    return Type::get_instance(type_id_)->compare_less_than(*this, o);
  }
  auto compare_less_than_equals(const Value &o) const -> Value
  {
    return Type::get_instance(type_id_)->compare_less_than_equals(*this, o);
  }
  auto compare_greater_than(const Value &o) const -> Value
  {
    return Type::get_instance(type_id_)->compare_greater_than(*this, o);
  }
  auto compare_greater_than_equals(const Value &o) const -> Value
  {
    return Type::get_instance(type_id_)->compare_greater_than_equals(*this, o);
  }

  auto add(const Value &o) const -> Value
  {
    return Type::get_instance(type_id_)->add(*this, o);
  }
  auto subtract(const Value &o) const -> Value
  {
    return Type::get_instance(type_id_)->subtract(*this, o);
  }
  auto multiply(const Value &o) const -> Value
  {
    return Type::get_instance(type_id_)->multiply(*this, o);
  }
  auto divide(const Value &o) const -> Value
  {
    return Type::get_instance(type_id_)->divide(*this, o);
  }

  auto min(const Value &o) const -> Value
  {
    return Type::get_instance(type_id_)->min(*this, o);
  }
  auto max(const Value &o) const -> Value
  {
    return Type::get_instance(type_id_)->max(*this, o);
  }

  auto conjunction(const Value &o) const -> Value
  {
    return Type::get_instance(type_id_)->conjunction(*this, o);
  }
  auto disjunction(const Value &o) const -> Value
  {
    return Type::get_instance(type_id_)->disjunction(*this, o);
  }
  auto negation() const -> Value
  {
    return Type::get_instance(type_id_)->negation(*this);
  }

protected:
  TypeId type_id_;

  union Val {
    bool bool_;
    int32_t int_;
    float float_;
    int32_t date_[3];
    char *char_;
  } value_{};

  // TODO
  bool is_null_{};
};