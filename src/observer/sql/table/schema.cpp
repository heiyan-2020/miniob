#include "schema.h"

Schema::Schema(const std::vector<Column> &columns) {
  uint32_t curr_offset = 0;
  for (uint32_t index = 0; index < columns.size(); index++) {
    Column column = columns[index];
    // set column offset
    column.column_offset_ = curr_offset;
    curr_offset += column.fixed_length_;

    // add column
    this->columns_.push_back(column);
  }

  length_ = curr_offset;
}