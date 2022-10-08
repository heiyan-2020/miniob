//
// Created by 37034 on 10/4/2022.
//

#ifndef MINIDB_ENVIRONMENT_H
#define MINIDB_ENVIRONMENT_H


#include "sql/table/schema.h"
#include "sql/table/tuple.h"
#include "rc.h"


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
    return RC::SUCCESS;
  }

  RC get_column_value(ColumnName name, Value &out_value)
  {
    RC rc = RC::SUCCESS;
    for (int i = 0; i < current_tuples_.size(); i++) {
      TupleRef tuple = current_tuples_[i];
      SchemaRef schema = current_schemas_[i];

      std::vector<Column> found = schema->find_columns(name.table_name_, name.column_name_);
      if (found.size() > 1) {
        LOG_ERROR("column name[%s.%s] is ambiguous", name.table_name_.c_str(), name.column_name_.c_str());
        return RC::INTERNAL;
      }
      out_value = tuple->get_value(schema, schema->get_column_idx(found[0].get_name()));
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
