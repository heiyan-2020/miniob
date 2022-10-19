#pragma once

#include <vector>

#include "scalar_function.h"
#include "type/value.h"

class SimpleFunction : public ScalarFunction {
public:
  SimpleFunction() = default;
  ~SimpleFunction() override = default;

  virtual auto evaluate(EnvRef env, std::vector<AbstractExpressionRef> args, Value &out_value) -> RC = 0;
};