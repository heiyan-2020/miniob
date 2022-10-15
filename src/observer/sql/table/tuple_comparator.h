#ifndef MINIOB_TUPLE_COMPARATOR_H
#define MINIOB_TUPLE_COMPARATOR_H

#include <memory>
#include "sql/expr/column_value_expression.h"
#include <utility>
#include "common/log/log.h"
#include "sql/expr/function_call.h"
#include "sql/parser/hsql/sql/statements.h"

class TupleComparator;
using TupleComparatorRef = std::shared_ptr<TupleComparator>;

class TupleComparator {

public:
  TupleComparator(std::shared_ptr<Schema>& sche, std::vector<hsql::OrderDescription*>* order_by_spec)
      : order_by_spec(order_by_spec), schema(sche)
  {}
  ~TupleComparator() = default;

  RC sort_tuples(std::vector<TupleRef>& sorted_res_);

private:
//  RC deserialize_tuples(const std::vector<TupleRef>& sorted_res_, std::vector<std::map<TupleRef, Value>>* &deserialized_res);
  int comp(TupleRef a, TupleRef b);
  bool is_ascending(hsql::OrderDescription* order_desc);

  std::vector<hsql::OrderDescription*>* order_by_spec;
  std::shared_ptr<Schema>& schema;
};

#endif  // MINIOB_TUPLE_COMPARATOR_H
