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
      cols_.push_back(std::make_shared<Column>(spec));
    }
    for (int i = 0; i < table_tuple->speces_.size(); i++) {
      cols_.push_back(std::make_shared<Column>(table_tuple->speces_[i]));
      cols_[i]->set_index(i);
    }
  }

  void append(Schema s);
  int add_column(Column column);

  std::vector<ColumnRef> findColumns(const char *table_name, const char *column_name);

private:
  std::vector<ColumnRef> cols_;
};

using SchemaRef = std::shared_ptr<Schema>;

#endif  // MINIDB_SCHEMA_H
