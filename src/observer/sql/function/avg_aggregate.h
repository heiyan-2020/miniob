#pragma once

#include <vector>

#include "aggregate_function.h"
#include "type/value.h"

class AvgAggregate : public AggregateFunction {
public:
  AvgAggregate() = default;
  ~AvgAggregate() override = default;

  auto add_value(Value value) -> void override
  {
    sum_value_ = sum_value_.add(value);
    count_value_ = count_value_.add(Value{INT, 1});
  }
  auto get_result() -> Value override
  {
    return sum_value_.divide(count_value_);
  }
  auto clear_result() -> void override
  {
    sum_value_ = {FLOAT, static_cast<float>(0)};
    count_value_ = {INT, 0};
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
      case FLOAT:
        return Value{FLOAT};
      default:
        break;
    }
    return res;
  }

private:
  Value sum_value_{FLOAT, static_cast<float>(0)};
  Value count_value_{INT, 0};
};