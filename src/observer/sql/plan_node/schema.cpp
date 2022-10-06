//
// Created by 37034 on 10/5/2022.
//

#include "schema.h"

// Schema::Schema(RowTuple table_tuple)
//{
//   for (auto spec : table_tuple.speces_) {
//     cols_.push_back(Column(spec));
//   }
// }

std::vector<Column> Schema::find_columns(const char *table_name, const char *column_name)
{
  std::vector<Column> found_columns;

  if (column_name == nullptr) {
    if (table_name == nullptr) {
      // Wildcard with no table name: *
      found_columns.insert(found_columns.end(), cols_.begin(), cols_.end());
    } else {
      // Wildcard with a table name: t.*
      for (Column col : cols_) {
        if (0 == strcmp(col.get_table_name(), table_name)) {
          found_columns.push_back(col);
        }
      }
    }
  } else {
    if (table_name == nullptr) {
      // Column name with no table name: col
      for (Column col : cols_) {
        if (0 == strcmp(col.get_column_name(), column_name)) {
          found_columns.push_back(col);
        }
      }
    } else {
      // Column name with table name: t.col
      for (Column col : cols_) {
        if (0 == strcmp(col.get_column_name(), column_name) && 0 == strcmp(col.get_table_name(), table_name)) {
          found_columns.push_back(col);
        }
      }
    }
  }

  return found_columns;
}
