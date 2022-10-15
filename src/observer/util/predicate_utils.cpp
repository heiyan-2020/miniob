//
// Created by 37034 on 10/15/2022.
//
#include "predicate_utils.h"
#include "sql/expr/bool_expression.h"

void PredicateUtils::collect_conjuncts(AbstractExpressionRef expr, std::unordered_set<AbstractExpressionRef> &out_conjuncts)
{
  // If there is no condition, just return without doing anything.
  if (!expr) {
    return ;
  }

  std::shared_ptr<BoolExpression> converted = std::dynamic_pointer_cast<BoolExpression>(expr);
  if (converted) {
    if (converted->get_ope_type() == OperatorType::AND) {
      // AND expression can be split into multiple pieces.
      std::vector<AbstractExpressionRef> terms = converted->get_terms();
      for (const auto &term : terms) {
        out_conjuncts.insert(term);
      }
    } else {
      // OR/NOT expression can't be split further.
      out_conjuncts.insert(converted);
    }
  } else {
    // The predicate is not a Boolean expression, so just store it.
    // TODO(zyx): figure out the necessary of this line.
    out_conjuncts.insert(expr);
  }

}

void PredicateUtils::find_expr_using_schemas(std::unordered_set<AbstractExpressionRef> src_expr,
    std::unordered_set<AbstractExpressionRef> &dst_expr
    , std::vector<SchemaRef> schemas)
{

}