#pragma once
#include <stdint.h>
#include "schema.h"

class Tuple {
public:
  // Default constructor (to create a dummy tuple)
  Tuple() = default;

  // constructor for creating a new tuple based on input value
  Tuple(std::vector<Value> values, const Schema *schema);

  // serialize tuple data
  void serialize_to(char *storage) const;

  // deserialize tuple data(deep copy)
  void deserialize_from(const char *storage);

  Value get_value(const Schema *schema, uint32_t column_idx) const;

private:
  const char *get_data_ptr(const Schema *schema, uint32_t column_idx) const;
  RID rid_{};  // if pointing to the table heap, the rid is valid
  int size_{0};
  char *data_{nullptr};
};