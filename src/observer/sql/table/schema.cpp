#include "schema.h"
#include "storage/common/table.h"

Schema::Schema(const std::vector<Column> &columns)
{
  set_columns(columns);
}

Schema::Schema(const Table *table, const std::vector<FieldMeta> *table_schema)
{
  std::vector<Column> columns;
  for (const auto &field : *table_schema) {
    ColumnName col_name(table->name(), field.name());
    columns.emplace_back(col_name, field.type(), field.len());
  }

  set_columns(columns);
}

void Schema::set_columns(const std::vector<Column> columns)
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

//std::vector<Column> Schema::find_columns(std::string &table_name, std::string &column_name)
//{
//}