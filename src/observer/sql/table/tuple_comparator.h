#ifndef MINIOB_TUPLE_COMPARATOR_H
#define MINIOB_TUPLE_COMPARATOR_H

#include <memory>
#include "sql/expr/column_value_expression.h"
#include <utility>
#include "common/log/log.h"
#include "sql/expr/function_call.h"

class TupleComparator;
using TupleComparatorRef = std::shared_ptr<TupleComparator>;

class TupleComparator {

public:
  TupleComparator(std::shared_ptr<Schema> shema, std::vector<AbstractExpressionRef> order_by_spec);
};

#endif  // MINIOB_TUPLE_COMPARATOR_H
