#pragma once

#include <string>
#include <utility>
#include "schema.h"
#include "type/type_id.h"
#include "type/type.h"
#include "tuple.h"

class ColumnName {
  friend class TableMeta;
  friend class Schema;

public:
  ColumnName() = default;
  explicit ColumnName(std::string column_name) :
        table_name_{}, column_name_{std::move(column_name)}
  {}
  ColumnName(std::string table_name, std::string column_name) :
        table_name_{std::move(table_name)}, column_name_{std::move(column_name)}
  {}
  ColumnName(const ColumnName &other)
  {
    // TODO(zyx): shallow copy, may be wrong.
    this->table_name_ = other.table_name_;
    this->column_name_ = other.column_name_;
  }

  bool operator==(const ColumnName &other) const
  {
    return table_name_ == other.table_name_ && column_name_ == other.column_name_;
  }

private:
  std::string table_name_;
  std::string column_name_;
};

class Column {
  friend class Schema;
  friend class Table;
  friend class TableMeta;

public:
  Column(const ColumnName &column_name, TypeId type, size_t length)
      : name_(column_name), column_type_(type), fixed_length_(length)
  {}

  size_t get_offset() const
  {
    return column_offset_;
  }

  TypeId get_type()
  {
    return column_type_;
  }

  ColumnName &get_name()
  {
    return name_;
  }

private:
  ColumnName name_;
  TypeId column_type_;
  size_t fixed_length_;
  size_t column_offset_{0};
};