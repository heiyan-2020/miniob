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

void PredicateUtils::find_expr_using_schemas(std::unordered_set<AbstractExpressionRef> &src_expr,
    std::unordered_set<AbstractExpressionRef> &dst_expr,
    const std::vector<SchemaRef>& schemas)
{
  std::vector<ColumnName> symbols;
  for (auto it = src_expr.begin(); it != src_expr.end();) {
    const auto& expr = *it;
    symbols.clear();
    symbols = expr->get_all_symbols();

    // all_ref indicates whether all symbols of this expression reference at least one schema.
    bool all_ref = true;
    for (const auto &symbol : symbols) {
      // ref indicates whether this symbol references at least one schema.
      bool ref = false;
      for (const auto &schema : schemas) {
        if (!schema->find_columns(symbol.table_name(), symbol.column_name()).empty()) {
          ref = true;
          break;
        }
      }

      if (!ref) {
        all_ref = false;
        break;
      }
    }

    if (all_ref) {
      dst_expr.insert(expr);
      src_expr.erase(it++);
    } else {
      ++it;
    }
  }
}

AbstractExpressionRef PredicateUtils::make_predicate(std::unordered_set<AbstractExpressionRef> conjuncts)
{
  AbstractExpressionRef expression;
  if (conjuncts.size() == 1)
    expression = *conjuncts.begin();
  else if (conjuncts.size() > 1) {
    expression = std::make_shared<BoolExpression>(conjuncts, OperatorType::AND);
  }
  // if conjuncts are empty, just return nullptr.
  return expression;
}