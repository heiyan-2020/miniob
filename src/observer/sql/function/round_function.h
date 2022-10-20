#pragma once

#include <vector>
#include <cmath>

#include "scalar_function.h"
#include "type/value.h"
#include "simple_function.h"
#include "util/float_utils.h"

class RoundFunction : public SimpleFunction {
public:
  RoundFunction() = default;
  ~RoundFunction() override = default;

  auto evaluate(EnvRef env, std::vector<AbstractExpressionRef> args, Value &out_value) -> RC override
  {
    // e.g. select round(235.415);
    if (args.size() == 1) {
      auto target = args[0];
      Value target_result;
      RC rc = target->evaluate(env, target_result);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      switch (target_result.get_type()) {
        case INT:
          out_value = Value{FLOAT, (float)std::round(target_result.value_.int_)};
          return RC::SUCCESS;
        case FLOAT:
          out_value = Value{FLOAT, (float)std::round(target_result.value_.float_)};
          return RC::SUCCESS;
        default:
          break;
      }
      return RC::UNIMPLENMENT;
    }

    // e.g. select round(num, 2) from table;
    if (args.size() == 2) {
      auto target = args[0];
      Value target_result;
      RC rc = target->evaluate(env, target_result);
      if (rc != RC::SUCCESS) {
        return rc;
      }

      auto digits = args[1];
      Value digits_result;
      rc = digits->evaluate(env, digits_result);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      if (digits_result.get_type() != INT) {
        return RC::UNIMPLENMENT;
      }

      switch (target_result.get_type()) {
        case INT: {
          auto val = round_float(std::to_string((float)target_result.value_.int_), digits_result.value_.int_);
          out_value = Value{FLOAT, (float)atof(val.c_str())};
          return RC::SUCCESS;
        }
        case FLOAT: {
          auto pre_val = round_float(std::to_string(target_result.value_.float_), digits_result.value_.int_ + 1);
          auto val = round_float(pre_val, digits_result.value_.int_);
          out_value = Value{FLOAT, (float)atof(val.c_str())};
          return RC::SUCCESS;
        }
        default:
          break;
      }
      return RC::UNIMPLENMENT;
    }

    return RC::UNIMPLENMENT;
  }

  auto get_return_type(std::vector<AbstractExpressionRef> args, SchemaRef schema) -> Value override
  {
    return Value{FLOAT};
  }
};