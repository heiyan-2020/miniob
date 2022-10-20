#ifndef MINIDB_COLUMN_H
#define MINIDB_COLUMN_H

#include <string>
#include <utility>
#include <memory>

#include "type/type_id.h"
#include "type/type.h"

class Column;
class Environment;

class ColumnName {
  friend class TableMeta;
  friend class Environment;
  friend class Schema;
  friend class Column;

public:
  ColumnName() = default;
  explicit ColumnName(std::string column_name) :
        table_name_{}, column_name_{std::move(column_name)}
  {}
  ColumnName(const char *table_name, const char *column_name)
  {
    if (table_name == nullptr) {
      table_name_ = {};
    } else {
      table_name_ = table_name;
    }
    column_name_ = column_name;
  }

  ColumnName(std::string table_name, std::string column_name):
        table_name_(std::move(table_name)), column_name_(std::move(column_name))
  {}

  ColumnName(const ColumnName &other)
  {
    this->table_name_ = other.table_name_;
    this->column_name_ = other.column_name_;
    this->alias_ = other.alias_;
  }

  bool operator==(const ColumnName &other) const
  {
    return table_name_ == other.table_name_ && column_name_ == other.column_name_;
  }

  std::string to_string(bool table_name_ignorable = false) const
  {
    std::string column_name = column_name_;
    if (has_alias()) {
      column_name = alias_;
    }
    if (table_name_.empty() && column_name_.empty()) {
      return "*";
    }
    if (table_name_ignorable || table_name_.empty()) {
      return column_name;
    }
    return table_name_ + "." + column_name;
  }

  bool is_wild_card() const
  {
    return column_name_.empty();
  }

  std::string table_name() const
  {
    return table_name_;
  }

  void set_table_name(std::string table_name)
  {
    table_name_ = std::move(table_name);
  }

  std::string column_name() const
  {
    return column_name_;
  }

  std::string alias()
  {
    return alias_;
  }

  bool has_alias() const
  {
    return !alias_.empty();
  }

  void set_alias(std::string alias)
  {
    alias_ = std::move(alias);
  }

private:
  std::string table_name_;
  std::string column_name_;
  std::string alias_;
};

class Column {
  friend class Schema;
  friend class Table;
  friend class TableMeta;

public:
  Column() = default;

  Column(const ColumnName &column_name, TypeId type, size_t length, bool visible = true, bool nullable = false)
      : name_(column_name), column_type_(type), fixed_length_(length), visible_(visible), nullable_(nullable)
  {}

  size_t get_len() const
  {
    return fixed_length_;
  }

  size_t get_offset() const
  {
    return column_offset_;
  }

  TypeId get_type() const
  {
    return column_type_;
  }

  ColumnName get_name() const
  {
    return name_;
  }

  void set_name(ColumnName name)
  {
    name_ = std::move(name);
  }

  bool is_visible() const
  {
    return visible_;
  }

  bool is_nullable() const
  {
    return nullable_;
  }

private:
  ColumnName name_;
  TypeId column_type_;
  size_t fixed_length_;
  size_t column_offset_{};
  bool visible_{};
  bool nullable_{};
};

using ColumnRef = std::shared_ptr<Column>;

#endif