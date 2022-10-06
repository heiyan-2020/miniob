#pragma once

#include "type.h"

class IntType : public Type {
public:
  IntType() : Type{INT}
  {}
  ~IntType() override = default;

  virtual auto compare_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, left.value_.int_ == right.value_.int_};
  }
  virtual auto compare_not_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, left.value_.int_ != right.value_.int_};
  }
  virtual auto compare_less_than(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, left.value_.int_ < right.value_.int_};
  }
  virtual auto compare_less_than_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, left.value_.int_ <= right.value_.int_};
  }
  virtual auto compare_greater_than(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, left.value_.int_ > right.value_.int_};
  }
  virtual auto compare_greater_than_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, left.value_.int_ >= right.value_.int_};
  }

  virtual auto add(const Value &left, const Value &right) const -> Value override
  {
    return Value{INT, left.value_.int_ + right.value_.int_};
  }
  virtual auto subtract(const Value &left, const Value &right) const -> Value override
  {
    return Value{INT, left.value_.int_ - right.value_.int_};
  }
  virtual auto multiply(const Value &left, const Value &right) const -> Value override
  {
    return Value{INT, left.value_.int_ * right.value_.int_};
  }
  virtual auto divide(const Value &left, const Value &right) const -> Value override
  {
    if (right.value_.int_ == 0) {
      return Value{};
    }
    return Value{INT, left.value_.int_ / right.value_.int_};
  }

  virtual auto min(const Value &left, const Value &right) const -> Value override
  {
    return Value{INT, std::min(left.value_.int_, right.value_.int_)};
  }
  virtual auto max(const Value &left, const Value &right) const -> Value override
  {
    return Value{INT, std::max(left.value_.int_, right.value_.int_)};
  }

  virtual auto conjunction(const Value &left, const Value &right) const -> Value override
  {
    return Value{};
  }
  virtual auto disjunction(const Value &left, const Value &right) const -> Value override
  {
    return Value{};
  }
  virtual auto negation(const Value &value) const -> Value override
  {
    return Value{INT, -value.value_.int_};
  }
};