//
// Created by 37034 on 10/4/2022.
//

#ifndef MINIDB_ENVIRONMENT_H
#define MINIDB_ENVIRONMENT_H

#include "sql/table/schema.h"
#include "sql/table/tuple.h"

class Environment;
using EnvRef = std::shared_ptr<Environment>;

class Environment {
public:
  RC add_tuple(SchemaRef schema, TupleRef tuple)
  {
    if (!schema || !tuple) {
      LOG_ERROR("Internal error: Adding empty schema or tuple into env.");
      return RC::INTERNAL;
    }

    current_schemas_.push_back(schema);
    current_tuples_.push_back(tuple);
  }

  RC clear()
  {
    current_schemas_.clear();
    current_tuples_.clear();
  }

  RC get_column_value(const char *table_name, const char *column_name, TupleCell &ret)
  {
    assert(column_name != nullptr);
    RC rc = RC::SUCCESS;
    for (int i = 0; i < current_tuples_.size(); i++) {
      TupleRef tuple = current_tuples_[i];
      SchemaRef schema = current_schemas_[i];

      std::vector<ColumnRef> found = schema->findColumns(table_name, column_name);
      if (found.size() > 1) {
        LOG_ERROR("column name[%s.%s] is ambiguous", table_name, column_name);
        return RC::INTERNAL;
      }
      rc = tuple->cell_at(found[0]->get_index(), ret);
      if (rc != RC::SUCCESS) {
        LOG_ERROR("Couldn't find %s.%s", table_name, column_name);
        return rc;
      }
      return rc;
    }
    LOG_ERROR("May be in the parent env which hasn't implemented yet.");
    return RC::UNIMPLENMENT;
  }

private:
  std::vector<SchemaRef> current_schemas_;
  std::vector<TupleRef> current_tuples_;
  std::vector<EnvRef> parent_envs_;
};

#endif  // MINIDB_ENVIRONMENT_H
