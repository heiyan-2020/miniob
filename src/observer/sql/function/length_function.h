#pragma once

#include <vector>
#include <cmath>

#include "scalar_function.h"
#include "type/value.h"
#include "simple_function.h"
#include "util/float_utils.h"

class LengthFunction : public SimpleFunction {
public:
  LengthFunction() = default;
  ~LengthFunction() override = default;

  auto evaluate(EnvRef env, std::vector<AbstractExpressionRef> args, Value &out_value) -> RC override
  {
    if (args.size() != 1) {
      return RC::UNIMPLENMENT;
    }

    auto target = args[0];
    Value target_result;
    RC rc = target->evaluate(env, target_result);
    if (rc != RC::SUCCESS) {
      return rc;
    }

    if (target_result.get_type() != CHAR) {
      return RC::UNIMPLENMENT;
    }

    out_value = Value{INT, (int32_t)strlen(target_result.value_.char_)};
  }

  auto get_return_type(std::vector<AbstractExpressionRef> args, SchemaRef schema) -> Value override
  {
    return Value{INT};
  }
};