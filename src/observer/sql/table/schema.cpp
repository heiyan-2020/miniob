#include "schema.h"

Schema::Schema(const std::vector<Column> &columns)
{
  size_t curr_offset = 0;
  for (auto column : columns) {
    // set column offset
    column.column_offset_ = curr_offset;
    curr_offset += column.fixed_length_;

    // add column
    this->columns_.push_back(column);
  }

  length_ = curr_offset;
}