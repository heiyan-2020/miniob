#pragma once

#include "type.h"

class BoolType : public Type {
public:
  BoolType() : Type{BOOL}
  {}
  ~BoolType() override = default;

  virtual auto compare_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{};
  }
  virtual auto compare_not_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{};
  }
  virtual auto compare_less_than(const Value &left, const Value &right) const -> Value override
  {
    return Value{};
  }
  virtual auto compare_less_than_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{};
  }
  virtual auto compare_greater_than(const Value &left, const Value &right) const -> Value override
  {
    return Value{};
  }
  virtual auto compare_greater_than_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{};
  }

  virtual auto add(const Value &left, const Value &right) const -> Value override
  {
    return Value{};
  }
  virtual auto subtract(const Value &left, const Value &right) const -> Value override
  {
    return Value{};
  }
  virtual auto multiply(const Value &left, const Value &right) const -> Value override
  {
    return Value{};
  }
  virtual auto divide(const Value &left, const Value &right) const -> Value override
  {
    return Value{};

  }

  virtual auto min(const Value &left, const Value &right) const -> Value override
  {
    return Value{};
  }
  virtual auto max(const Value &left, const Value &right) const -> Value override
  {
    return Value{};
  }

  virtual auto conjunction(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, left.value_.bool_ and right.value_.bool_};
  }
  virtual auto disjunction(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, left.value_.bool_ or right.value_.bool_};
  }
  virtual auto negation(const Value &value) const -> Value override
  {
    return Value{BOOL, not value.value_.bool_};
  }
};