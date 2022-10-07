#pragma once
#include "column.h"
#include "common/log/log.h"
#include "storage/common/table.h"
#include <vector>
#include <optional>

class Schema;
using SchemaRef = std::shared_ptr<Schema>;

class Schema {
public:
  explicit Schema(const std::vector<Column> &columns);

  Schema(Table *table, const std::vector<FieldMeta> *table_schema);

  const std::vector<Column> &get_columns() const
  {
    return columns_;
  }

  Column get_column(int col_idx) const
  {
    return columns_[col_idx];
  }

  uint32_t get_column_idx(const ColName &name) const
  {
    for (uint32_t i = 0; i < columns_.size(); ++i) {
      if (columns_[i].name_ == name) {
        return i;
      }
    }
    LOG_ERROR("can't find column\n");
    return -1;
  }

  int get_column_count() const
  {
    return columns_.size();
  }

  int get_length() const
  {
    return length_;
  }

private:
  std::vector<Column> columns_;
  int length_;
};