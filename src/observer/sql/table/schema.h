#ifndef MINIDB_SCHEMA_H
#define MINIDB_SCHEMA_H

#include <vector>
#include <algorithm>

#include "column.h"
#include "common/log/log.h"
#include "unordered_set"
#include "rc.h"

class Table;
class FieldMeta;

class Schema;
using SchemaRef = std::shared_ptr<Schema>;

class Schema {
public:
  Schema() = default;
  explicit Schema(const std::vector<Column> &columns);

  Schema(const Table *table, const std::vector<FieldMeta> *table_schema);

  // designed for preparing join schema.
  Schema(SchemaRef left, SchemaRef rhs);

  Schema(std::vector<SchemaRef> schemas);

  const std::vector<Column> &get_columns() const
  {
    return columns_;
  }

  Column get_column(size_t col_idx) const
  {
    return columns_[col_idx];
  }

  RC get_column_idx(const ColumnName &name, size_t &idx) const
  {
    for (size_t i = 0; i < columns_.size(); ++i) {
      if (columns_[i].name_ == name) {
        idx = i;
        return RC::SUCCESS;
      }
    }
    return RC::SUCCESS;
  }

  size_t get_column_count() const
  {
    return columns_.size();
  }

  size_t get_length() const
  {
    return length_;
  }

  /**
   * return true when:
   * 1. all columns belong to same table
   * 2. all columns have table name (column value expression)
   */
  bool ignore_table_name() const
  {
    if (std::any_of(columns_.begin(), columns_.end(), [](const auto &column) {
          return column.get_name().table_name_.empty();
        })) {
      return false;
    }
    std::string table_name = columns_[0].get_name().table_name_;
    if (std::any_of(columns_.begin(), columns_.end(), [table_name](const auto &column) {
          return column.get_name().table_name_ != table_name;
        })) {
      return false;
    }
    return true;
  }

  std::unordered_set<std::string> get_involved_tables() const;

  std::vector<Column> find_columns(std::string table_name, std::string column_name);

private:
  void set_columns(const std::vector<Column> &columns);

  std::vector<Column> columns_{};
  size_t length_{};
};

using SchemaRef = std::shared_ptr<Schema>;

#endif