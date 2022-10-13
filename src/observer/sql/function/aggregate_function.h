#pragma once

#include <vector>

#include "scalar_function.h"
#include "../../type/value.h"

class AggregateFunction : public ScalarFunction {
public:
  AggregateFunction() = default;
  ~AggregateFunction() = default;

  virtual auto add_value(Value value) -> void = 0;
  virtual auto get_result() -> Value = 0;
  virtual auto clear_result() -> void = 0;
};