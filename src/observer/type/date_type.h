#pragma once

#include "type.h"
#include "util/date.h"

class DateType : public Type {
public:
  DateType() : Type{DATE}
  {}
  ~DateType() override = default;

  virtual auto compare_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, Date{(void *)left.value_.date_} == Date{(void *)right.value_.date_}};
  }
  virtual auto compare_not_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, Date{(void *)left.value_.date_} != Date{(void *)right.value_.date_}};
  }
  virtual auto compare_less_than(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, Date{(void *)left.value_.date_} < Date{(void *)right.value_.date_}};
  }
  virtual auto compare_less_than_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, Date{(void *)left.value_.date_} <= Date{(void *)right.value_.date_}};
  }
  virtual auto compare_greater_than(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, Date{(void *)left.value_.date_} > Date{(void *)right.value_.date_}};
  }
  virtual auto compare_greater_than_equals(const Value &left, const Value &right) const -> Value override
  {
    return Value{BOOL, Date{(void *)left.value_.date_} >= Date{(void *)right.value_.date_}};
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
    return Date{(void *)left.value_.date_} <= Date{(void *)right.value_.date_} <= 0 ? left : right;
  }
  virtual auto max(const Value &left, const Value &right) const -> Value override
  {
    return Date{(void *)left.value_.date_} >= Date{(void *)right.value_.date_} <= 0 ? left : right;
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
    return Value{};
  }
};