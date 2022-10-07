#pragma once
#include <stdint.h>
#include "schema.h"
#include "type/type_id.h"
#include "type/value.h"
#include "storage/record/record.h"

class Tuple {
public:
  // Default constructor (to create a dummy tuple)
  Tuple() = default;

  // constructor for creating a new tuple based on input value
  Tuple(std::vector<Value> values, const Schema *schema);

  Value get_value(const Schema *schema, uint32_t column_idx) const;

private:
  const char *get_data_ptr(const Schema *schema, uint32_t column_idx) const;
  RID rid_{};  // if pointing to the table heap, the rid is valid
  int size_{0};
  char *data_{nullptr};
};