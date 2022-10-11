#ifndef MINIDB_SCHEMA_H
#define MINIDB_SCHEMA_H

#include <vector>

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
   * return true when all columns belong to same table i.e. we can ignore table_name.
   * @return
   */
  bool table_name_ignorable() const
  {
    std::string table_name = columns_[0].get_name().table_name_;
    for (const auto &column : columns_) {
      if (column.get_name().table_name_ != table_name) {
        return false;
      }
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