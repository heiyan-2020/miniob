#pragma once

#include <vector>

#include "aggregate_function.h"
#include "type/value.h"

class MaxAggregate : public AggregateFunction {
public:
  MaxAggregate() = default;
  ~MaxAggregate() override = default;

  auto add_value(Value value) -> void override
  {
    if (value.is_null()) {
      return;
    }
    if (value_.is_null()) {
      value_ = value;
    } else {
      auto res = value.compare(value_);
      if (res == CmpRes::GT) {
        value_ = value;
      }
    }
  }
  auto get_result() -> Value override
  {
    return value_;
  }
  auto clear_result() -> void override
  {
    value_ = {};
  }

  auto get_return_type(std::vector<AbstractExpressionRef> args, SchemaRef schema) -> Value override
  {
    auto arg = args[0];
    Column column;
    RC rc = arg->convert_to_column(schema, column);
    Value res{};
    if (rc != RC::SUCCESS) {
      return res;
    }
    switch (column.get_type()) {
      case CHAR: {
        char *tmp = (char *)calloc(column.get_len(), sizeof(char));
        res = Value{column.get_type(), tmp, column.get_len()};
        free(tmp);
        break;
      }
      default:
        res = Value{column.get_type()};
        break;
    }
    return res;
  }

private:
  Value value_{};
};