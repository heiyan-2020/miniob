#pragma once

#include "sql/expr/abstract_expression.h"

class PredicateUtils {
public:
  static void collect_conjuncts(AbstractExpressionRef expr, std::unordered_set<AbstractExpressionRef> &out_conjuncts);

  static void find_expr_using_schemas(std::unordered_set<AbstractExpressionRef> src_expr,
      std::unordered_set<AbstractExpressionRef> &dst_expr
      , std::vector<SchemaRef> schemas);
};
