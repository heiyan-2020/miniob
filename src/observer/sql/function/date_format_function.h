#pragma once

#include <vector>
#include <cmath>

#include "scalar_function.h"
#include "type/value.h"
#include "simple_function.h"
#include "sql/expr/environment.h"
#include "util/date_utils.h"

class DateFormatFunction : public SimpleFunction {
public:
  DateFormatFunction() = default;
  ~DateFormatFunction() override = default;

  auto evaluate(EnvRef env, std::vector<AbstractExpressionRef> args, Value &out_value) -> RC override
  {
    if (args.size() != 2) {
      return RC::UNIMPLENMENT;
    }

    auto target = args[0];
    Value target_result;
    RC rc = target->evaluate(env, target_result);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    if (target_result.get_type() != DATE) {
      return RC::UNIMPLENMENT;
    }

    auto format = args[1];
    Value format_result;
    rc = format->evaluate(env, format_result);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    if (format_result.get_type() != CHAR) {
      return RC::UNIMPLENMENT;
    }

    Date date{target_result.value_.date_};
    std::string tmp = format_date(date, format_result.value_.char_);
    out_value = Value{CHAR, tmp.c_str(), tmp.size()};
    return RC::SUCCESS;
  }

  auto get_return_type(std::vector<AbstractExpressionRef> args, SchemaRef schema) -> Value override
  {
    // TODO(vgalaxy): max length set to 64
    size_t len = 64;
    char *tmp = (char *)calloc(len, sizeof(char));
    Value res = Value{CHAR, tmp, len};
    free(tmp);
    return res;
  }
};