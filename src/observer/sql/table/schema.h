#pragma once

#include "column.h"
#include "common/log/log.h"
#include <vector>
#include <optional>

class Schema {
public:
  Schema() = default;
  explicit Schema(const std::vector<Column> &columns);

  const std::vector<Column> &get_columns() const
  {
    return columns_;
  }

  Column get_column(size_t col_idx) const
  {
    return columns_[col_idx];
  }

  size_t get_column_idx(const ColumnName &name) const
  {
    for (size_t i = 0; i < columns_.size(); ++i) {
      if (columns_[i].name_ == name) {
        return i;
      }
    }
    LOG_ERROR("can't find column");
    return -1;
  }

  size_t get_column_count() const
  {
    return columns_.size();
  }

  size_t get_length() const
  {
    return length_;
  }

private:
  std::vector<Column> columns_{};
  size_t length_{};
};

using SchemaRef = std::shared_ptr<Schema>;