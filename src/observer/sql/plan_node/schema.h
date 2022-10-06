//
// Created by 37034 on 10/4/2022.
//

#ifndef MINIDB_SCHEMA_H
#define MINIDB_SCHEMA_H

#include "storage/common/field.h"
#include "column.h"
#include <cstring>
#include "sql/expr/tuple.h"

class Schema {
public:
  Schema() = default;
  Schema(std::vector<Column> cols);
  Schema(Schema lhs, Schema rhs);
  explicit Schema(RowTuple *table_tuple)
  {
    for (auto spec : table_tuple->speces_) {
      cols_.emplace_back(spec);
    }
  }

  void append(Schema s);
  int add_column(Column column);

  std::vector<Column> find_columns(const char *table_name, const char *column_name);

private:
  std::vector<Column> cols_;
};

#endif  // MINIDB_SCHEMA_H
