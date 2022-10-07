#pragma once

#include "type.h"

class CharType : public Type {
public:
  CharType() : Type{CHAR}
  {}
  ~CharType() override = default;

  virtual auto compare_equals(const Value &left, const Value &right) const -> Value override;
  virtual auto compare_not_equals(const Value &left, const Value &right) const -> Value override;
  virtual auto compare_less_than(const Value &left, const Value &right) const -> Value override;
  virtual auto compare_less_than_equals(const Value &left, const Value &right) const -> Value override;
  virtual auto compare_greater_than(const Value &left, const Value &right) const -> Value override;
  virtual auto compare_greater_than_equals(const Value &left, const Value &right) const -> Value override;

  virtual auto add(const Value &left, const Value &right) const -> Value override;
  virtual auto subtract(const Value &left, const Value &right) const -> Value override;
  virtual auto multiply(const Value &left, const Value &right) const -> Value override;
  virtual auto divide(const Value &left, const Value &right) const -> Value override;

  virtual auto min(const Value &left, const Value &right) const -> Value override;
  virtual auto max(const Value &left, const Value &right) const -> Value override;

  virtual auto conjunction(const Value &left, const Value &right) const -> Value override;
  virtual auto disjunction(const Value &left, const Value &right) const -> Value override;
  virtual auto negation(const Value &value) const -> Value override;
};