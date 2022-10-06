//
// Created by 37034 on 10/6/2022.
//

#ifndef MINIDB_COLUMN_H
#define MINIDB_COLUMN_H
#include "storage/common/field.h"
#include "sql/expr/tuple.h"

class TupleCellSpec; /**
                      * This class encapsulates (table_name, column_name, column_index), where column_index indicates
                      * the index of associated TupleCellSpec in tuple. i.e. Tuple.cell_at(col_idx_) could get
                      * associated column.
                      */
class Column {
public:
  Column(TupleCellSpec *spec) : spec_(spec)
  {}
  const char *get_table_name()
  {
    return ((FieldExpr *)spec_->expression())->table_name();
  }
  const char *get_column_name()
  {
    return ((FieldExpr *)spec_->expression())->field_name();
  }
  void set_alias(const char *alias)
  {
    spec_->set_alias(alias);
  }
  int get_index()
  {
    return col_idx_;
  }
  TupleCellSpec *get_spec()
  {
    return spec_;
  }

private:
  const char *table_name_;
  const char *column_name_;
  int col_idx_;
  TupleCellSpec *spec_;
};

#endif  // MINIDB_COLUMN_H
