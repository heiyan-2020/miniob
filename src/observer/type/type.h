#pragma once

#include "type_id.h"

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
      case INT:
      case FLOAT:
        return 4;
      case DATE:
        return 12;
      case BOOL:
        return 1;
      default:  // including CHAR
        return 0;
    }
  }
  static auto to_string(TypeId type_id) -> std::string
  {
    switch (type_id) {
      case CHAR:
        return "char";
      case INT:
        return "int";
      case FLOAT:
        return "float";
      case DATE:
        return "date";
      case BOOL:
        return "bool";
      default:
        return "<unknown>";
    }
  }

  virtual auto compare_equals(const Value &left, const Value &right) const -> Value;
  virtual auto compare_not_equals(const Value &left, const Value &right) const -> Value;
  virtual auto compare_less_than(const Value &left, const Value &right) const -> Value;
  virtual auto compare_less_than_equals(const Value &left, const Value &right) const -> Value;
  virtual auto compare_greater_than(const Value &left, const Value &right) const -> Value;
  virtual auto compare_greater_than_equals(const Value &left, const Value &right) const -> Value;

  virtual auto compare(const Value &left, const Value &right) const -> int;

  virtual auto add(const Value &left, const Value &right) const -> Value;
  virtual auto subtract(const Value &left, const Value &right) const -> Value;
  virtual auto multiply(const Value &left, const Value &right) const -> Value;
  virtual auto divide(const Value &left, const Value &right) const -> Value;

  virtual auto min(const Value &left, const Value &right) const -> Value;
  virtual auto max(const Value &left, const Value &right) const -> Value;

  virtual auto conjunction(const Value &left, const Value &right) const -> Value;
  virtual auto disjunction(const Value &left, const Value &right) const -> Value;
  // including not and unary minus
  virtual auto negation(const Value &value) const -> Value;

  virtual auto serialize_to(const Value &val, char *storage) const -> void;
  virtual auto deserialize_from(const char *storage) const -> Value;

protected:
  TypeId type_id_;
  static Type *k_types[PLACEHOLDER];
};