#pragma once

#include <vector>

#include "aggregate_function.h"
#include "type/value.h"

class CountAggregate : public AggregateFunction {
public:
  auto add_value(Value value) -> void override
  {
    count_++;
  }
  auto get_result() -> Value override
  {
    return Value{INT, this->count_};
  }
  auto clear_result() -> void override
  {
    count_ = 0;
  }
private:
  int32_t count_{};
};