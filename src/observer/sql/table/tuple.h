#ifndef MINIDB_TUPLE_H
#define MINIDB_TUPLE_H

#include <cstdint>
#include <memory>

#include "type/type_id.h"
#include "type/value.h"
#include "storage/record/record.h"
#include "sql/table/schema.h"

class Tuple;
using TupleRef = std::shared_ptr<Tuple>;



class Tuple {
public:
  // Default constructor (to create a dummy tuple)
  Tuple() = default;

  // constructor for creating a new tuple based on input value
  Tuple(std::vector<Value> values, SchemaRef schema);

  // constructor for table heap tuple
  explicit Tuple(Record *record);

//  ~Tuple() {
//    delete[] data_;
//    data_ = nullptr;
//  }

  Value get_value(SchemaRef schema, size_t column_idx) const;

  Record get_record() const;

private:
  const char *get_data_ptr(SchemaRef schema, size_t column_idx) const;
  RID rid_{};  // if pointing to the table heap, the rid is valid
  size_t size_{};
  char *data_{nullptr};
};

#endif