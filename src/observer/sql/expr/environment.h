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
    return RC::SUCCESS;
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
    for (size_t i = 0; i < current_tuples_.size(); i++) {
      TupleRef tuple = current_tuples_[i];
      SchemaRef schema = current_schemas_[i];

      std::vector<Column> found = schema->find_columns(name.table_name_, name.column_name_);
      if (found.empty()) {
        continue ;
      }
      if (found.size() > 1) {
        LOG_ERROR("column name[%s.%s] is ambiguous", name.table_name_.c_str(), name.column_name_.c_str());
        return RC::INTERNAL;
      }
      common::Bitmap null_field_bitmap{tuple->get_record().data(), 32};
      size_t idx = 0;
      if (schema->get_column_idx(found[0].get_name(), idx) != RC::SUCCESS) {
        return RC::INTERNAL;
      }
      if (null_field_bitmap.get_bit(idx)) {
        out_value = Value{schema->get_column(idx).get_type()};
      } else {
        out_value = tuple->get_value(schema, idx);
      }
      return rc;
    }

    // can't find column in current env, find it in the parent if it has.
    if (!parent_envs_.empty()) {
      for (const auto &parent : parent_envs_) {
        rc = parent->get_column_value(name, out_value);
        if (rc == RC::SUCCESS) {
          return rc;
        }
        if (rc == RC::ENV) {
          continue ;
        }
        return rc; // unexpected situation, return failure.
      }
    }

    return RC::ENV;
  }

  void add_parent_env(EnvRef parent)
  {
    parent_envs_.push_back(std::move(parent));
  }

private:
  std::vector<SchemaRef> current_schemas_;
  std::vector<TupleRef> current_tuples_;
  std::vector<EnvRef> parent_envs_;
};

#endif  // MINIDB_ENVIRONMENT_H
