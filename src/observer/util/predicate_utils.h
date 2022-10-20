#pragma once

#include "sql/expr/abstract_expression.h"

class PredicateUtils {
public:
  /**
   * Destructing expr into pieces.
   * @param expr
   * @param out_conjuncts
   */
  static void collect_conjuncts(AbstractExpressionRef expr, std::unordered_set<AbstractExpressionRef> &out_conjuncts);

  /**
   * Put all expressions which only reference to 'schemas' into dst_expr.
   * @param src_expr
   * @param dst_expr
   * @param schemas
   */
  static void find_expr_using_schemas(std::unordered_set<AbstractExpressionRef> &src_expr,
      std::unordered_set<AbstractExpressionRef> &dst_expr, const std::vector<SchemaRef> &schemas);

  /**
   * Constructing conjuncts to a predicate.
   * @param conjuncts
   * @return
   */
  static AbstractExpressionRef make_predicate(std::unordered_set<AbstractExpressionRef> conjuncts);
};
