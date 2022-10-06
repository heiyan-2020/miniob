#pragma once

#include "type_id.h"
#include "value.h"

#include "char_type.h"
#include "int_type.h"
#include "float_type.h"
#include "date_type.h"
#include "bool_type.h"

#include <cstddef>
#include <string>

class Value;

class Type {
public:
  Type() : Type{UNDEFINED}
  {}
  explicit Type(TypeId type_id) : type_id_(type_id)
  {}
  virtual ~Type() = default;

  static auto get_instance(TypeId type_id) -> Type *
  {
    return k_types[type_id];
  }
  static auto get_type_size(TypeId type_id) -> size_t
  {
    switch (type_id) {
      case CHAR:  // default size is 4
      case INT:
      case FLOAT:
        return 4;
      case DATE:
        return 12;
      case BOOL:
        return 1;
      default:
        return 0;
    }
  }
  static auto to_string(TypeId type_id) -> std::string
  {
    switch (type_id) {
      // TODO
    }
  }
  static auto get_min_value(TypeId type_id) -> Value
  {
    switch (type_id) {
      // TODO
    }
  }
  static auto get_max_value(TypeId type_id) -> Value
  {
    switch (type_id) {
      // TODO
    }
  }
  static auto get_true() -> Value
  {
    return Value{BOOL, true};
  }
  static auto get_false() -> Value
  {
    return Value{BOOL, false};
  }

  virtual auto compare_equals(const Value &left, const Value &right) const -> Value
  {
    return Value{};
  }
  virtual auto compare_not_equals(const Value &left, const Value &right) const -> Value
  {
    return Value{};
  }
  virtual auto compare_less_than(const Value &left, const Value &right) const -> Value
  {
    return Value{};
  }
  virtual auto compare_less_than_equals(const Value &left, const Value &right) const -> Value
  {
    return Value{};
  }
  virtual auto compare_greater_than(const Value &left, const Value &right) const -> Value
  {
    return Value{};
  }
  virtual auto compare_greater_than_equals(const Value &left, const Value &right) const -> Value
  {
    return Value{};
  }

  virtual auto add(const Value &left, const Value &right) const -> Value
  {
    return Value{};
  }
  virtual auto subtract(const Value &left, const Value &right) const -> Value
  {
    return Value{};
  }
  virtual auto multiply(const Value &left, const Value &right) const -> Value
  {
    return Value{};
  }
  virtual auto divide(const Value &left, const Value &right) const -> Value
  {
    return Value{};
  }

  virtual auto min(const Value &left, const Value &right) const -> Value
  {
    return Value{};
  }
  virtual auto max(const Value &left, const Value &right) const -> Value
  {
    return Value{};
  }

  virtual auto conjunction(const Value &left, const Value &right) const -> Value
  {
    return Value{};
  }
  virtual auto disjunction(const Value &left, const Value &right) const -> Value
  {
    return Value{};
  }
  // including not and unary minus
  virtual auto negation(const Value &value) const -> Value
  {
    return Value{};
  }

protected:
  TypeId type_id_;
  static Type *k_types[PLACEHOLDER];
};

Type *Type::k_types[] = {
    new Type{}, new CharType{}, new IntType{}, new FloatType{}, new DateType{}, new BoolType{},
};