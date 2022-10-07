#pragma once
#include <string>
#include "schema.h"
#include "tuple.h"

class ColName {
public:
  ColName(const char *table_name, const char *column_name) : table_name_(table_name), column_name_(column_name)
  {}
  ColName(const ColName &other)
  {
    // TODO(zyx): shallow copy, may be wrong.
    this->table_name_ = other.table_name_;
    this->column_name_ = other.column_name_;
  }
  bool operator==(const ColName &other) const
  {
    return table_name_ == other.table_name_ && column_name_ == other.column_name_;
  }

private:
  std::string table_name_;
  std::string column_name_;
};

class Column {
  friend class Schema;

public:
  Column(ColName column_name, TypeId type)
      : name_(std::move(column_name)), column_type_(type), fixed_length_(TypeSize(type))
  {}

  int get_offset() const
  {
    return column_offset_;
  }

  TypeId get_type()
  {
    return column_type_;
  }

private:
  ColName name_;
  TypeId column_type_;
  int fixed_length_;
  int column_offset_{0};
};