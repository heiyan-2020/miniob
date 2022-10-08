#ifndef MINIDB_SCHEMA_H
#define MINIDB_SCHEMA_H

#include <vector>

#include "column.h"
#include "common/log/log.h"
//#include "storage/common/table.h"

class Table;
class FieldMeta;

class Schema;
using SchemaRef = std::shared_ptr<Schema>;

class Schema {
public:
  Schema() = default;
  explicit Schema(const std::vector<Column> &columns);

  Schema(const Table *table, const std::vector<FieldMeta> *table_schema);

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
    assert(false);
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

  std::vector<Column> find_columns(std::string table_name, std::string column_name);

private:
  void set_columns(const std::vector<Column> &columns);

  std::vector<Column> columns_{};
  size_t length_{};
};

using SchemaRef = std::shared_ptr<Schema>;

#endif