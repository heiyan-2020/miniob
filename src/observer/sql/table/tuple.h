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
  void SerializeTo(char *storage) const;

  // deserialize tuple data(deep copy)
  void DeserializeFrom(const char *storage);

  Value GetValue(const Schema *schema, uint32_t column_idx) const;

private:
  const char *GetDataPtr(const Schema *schema, uint32_t column_idx) const;
  RID rid_{};              // if pointing to the table heap, the rid is valid
  int size_{0};
  char *data_{nullptr};
};