#pragma once

#include <vector>

#include "abstract_function.h"
#include "sql/expr/expression_processor.h"
#include "sql/table/schema.h"
#include "type/type_id.h"

class ScalarFunction : public AbstractFunction {
public:
  ScalarFunction() = default;
  ~ScalarFunction() override = default;

  virtual auto get_return_type(std::vector<AbstractExpressionRef> args, SchemaRef schema) -> Value = 0;
};