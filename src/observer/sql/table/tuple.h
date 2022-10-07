#pragma once

#include <cstdint>
#include "schema.h"
#include "type/type_id.h"
#include "type/value.h"
#include "storage/record/record.h"

class Schema;

class Tuple {
public:
  // Default constructor (to create a dummy tuple)
  Tuple() = default;

  // constructor for creating a new tuple based on input value
  Tuple(std::vector<Value> values, const Schema *schema);

  // constructor for table heap tuple
  explicit Tuple(Record *record);

  Value get_value(const Schema *schema, size_t column_idx) const;

private:
  const char *get_data_ptr(const Schema *schema, size_t column_idx) const;
  RID rid_{};  // if pointing to the table heap, the rid is valid
  size_t size_{};
  char *data_{nullptr};
};