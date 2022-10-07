#pragma once

#include "type.h"

class IntType : public Type {
public:
  IntType() : Type{INT}
  {}
  ~IntType() override = default;

  auto compare_equals(const Value &left, const Value &right) const -> Value override;
  auto compare_not_equals(const Value &left, const Value &right) const -> Value override;
  auto compare_less_than(const Value &left, const Value &right) const -> Value override;
  auto compare_less_than_equals(const Value &left, const Value &right) const -> Value override;
  auto compare_greater_than(const Value &left, const Value &right) const -> Value override;
  auto compare_greater_than_equals(const Value &left, const Value &right) const -> Value override;

  auto add(const Value &left, const Value &right) const -> Value override;
  auto subtract(const Value &left, const Value &right) const -> Value override;
  auto multiply(const Value &left, const Value &right) const -> Value override;
  auto divide(const Value &left, const Value &right) const -> Value override;

  auto min(const Value &left, const Value &right) const -> Value override;
  auto max(const Value &left, const Value &right) const -> Value override;

  auto conjunction(const Value &left, const Value &right) const -> Value override;
  auto disjunction(const Value &left, const Value &right) const -> Value override;
  auto negation(const Value &value) const -> Value override;

  auto serialize_to(const Value &val, char *storage) const -> void override;
  auto deserialize_from(const char *storage) const -> Value override;
};