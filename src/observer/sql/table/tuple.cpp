#include "tuple.h"
#include <string>

Tuple::Tuple(std::vector<Value> values, const Schema *schema)
{
  assert(values.size() == schema->get_column_count());

  // 1. Calculate the size of the tuple.
  uint32_t tuple_size = schema->get_length();

  // 2. Allocate memory.
  size_ = tuple_size;
  data_ = new char[size_];
  memset(data_, 0, size_);

  // 3. Serialize each attribute based on the input value.
  uint32_t column_count = schema->get_column_count();

  for (uint32_t i = 0; i < column_count; i++) {
    const auto &col = schema->get_column(i);
    values[i].SerializeTo(data_ + col.get_offset());
  }
}

Value Tuple::get_value(const Schema *schema, uint32_t column_idx)
{
  assert(schema);
  assert(data_);
  const TypeId column_type = schema->get_column(column_idx).GetType();
  const char *data_ptr = GetDataPtr(schema, column_idx);
  return Value::DeserializeFrom(data_ptr, column_type);
}

const char *Tuple::get_data_ptr(const Schema *schema, const uint32_t column_idx) const
{
  assert(schema);
  assert(data_);
  const auto &col = schema->get_column(column_idx);
  return (data_ + col.GetOffset());
}