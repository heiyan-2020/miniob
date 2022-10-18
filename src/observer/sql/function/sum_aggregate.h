#pragma once

#include <vector>

#include "aggregate_function.h"
#include "type/value.h"

class SumAggregate : public AggregateFunction {
public:
  SumAggregate() = default;
  ~SumAggregate() override = default;

  auto add_value(Value value) -> void override
  {
    if (value.is_null()) {
      return;
    }
    if (sum_value_.is_null()) {
      sum_value_ = value;
    } else {
      sum_value_ = sum_value_.add(value);
    }
  }
  auto get_result() -> Value override
  {
    return sum_value_;
  }
  auto clear_result() -> void override
  {
    sum_value_ = {};
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
      case INT:
        return Value{INT};
      case FLOAT:
        return Value{FLOAT};
      default:
        break;
    }
    return res;
  }

private:
  Value sum_value_{};
};