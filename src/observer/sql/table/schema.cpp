#include "schema.h"
#include "storage/common/table.h"

Schema::Schema(const std::vector<Column> &columns)
{
  uint32_t curr_offset = 0;
  for (auto column : columns) {
    // set column offset
    column.column_offset_ = curr_offset;
    curr_offset += column.fixed_length_;

    // add column
    this->columns_.push_back(column);
  }

  length_ = curr_offset;
}

Schema::Schema(const Table *table, const std::vector<FieldMeta> *table_schema)
{
  std::vector<Column> columns;
  for (const auto &field : *table_schema) {
    ColName col_name(table->name(), field.name());
    // TODO(zyx): Initialize column type.
//    columns.emplace_back(col_name, , field.len());
  }
}