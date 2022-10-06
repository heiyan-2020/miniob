//
// Created by 37034 on 10/4/2022.
//

#ifndef MINIDB_SCHEMA_H
#define MINIDB_SCHEMA_H

#include "storage/common/field.h"
#include "column.h"
#include "string.h"
#include "sql/expr/tuple.h"

class Schema {
public:
  Schema()
  {}
  Schema(std::vector<Column> cols);
  Schema(Schema lhs, Schema rhs);
  Schema(RowTuple *table_tuple)
  {
    for (auto spec : table_tuple->speces_) {
      cols_.push_back(Column(spec));
    }
  }

  void append(Schema s);
  int addColumn(Column column);

  std::vector<Column> findColumns(const char *table_name, const char *column_name);

private:
  std::vector<Column> cols_;
};

#endif  // MINIDB_SCHEMA_H
