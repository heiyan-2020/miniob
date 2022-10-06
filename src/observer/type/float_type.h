#pragma once

#include "type.h"

class FloatType : public Type {
public:
  FloatType() : Type{FLOAT}
  {}
  ~FloatType() override = default;

  virtual auto compare_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, left.value_.float_ == right.value_.float_};
  }
  virtual auto compare_not_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, left.value_.float_ != right.value_.float_};
  }
  virtual auto compare_less_than(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, left.value_.float_ < right.value_.float_};
  }
  virtual auto compare_less_than_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, left.value_.float_ <= right.value_.float_};
  }
  virtual auto compare_greater_than(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, left.value_.float_ > right.value_.float_};
  }
  virtual auto compare_greater_than_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, left.value_.float_ >= right.value_.float_};
  }

  virtual auto add(const Value &left, const Value &right) const -> Value override
  {
    return Value{FLOAT, left.value_.float_ + right.value_.float_};
  }
  virtual auto subtract(const Value &left, const Value &right) const -> Value override
  {
    return Value{FLOAT, left.value_.float_ - right.value_.float_};
  }
  virtual auto multiply(const Value &left, const Value &right) const -> Value override
  {
    return Value{FLOAT, left.value_.float_ * right.value_.float_};
  }
  virtual auto divide(const Value &left, const Value &right) const -> Value override
  {
    if (right.value_.float_ == 0) {
      return Value{};
    }
    return Value{FLOAT, left.value_.float_ / right.value_.float_};
  }

  virtual auto min(const Value &left, const Value &right) const -> Value override
  {
    return Value{FLOAT, std::min(left.value_.float_, right.value_.float_)};
  }
  virtual auto max(const Value &left, const Value &right) const -> Value override
  {
    return Value{FLOAT, std::max(left.value_.float_, right.value_.float_)};
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
    return Value{FLOAT, -value.value_.float_};
  }
};