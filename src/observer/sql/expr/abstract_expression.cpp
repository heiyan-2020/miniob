#include "abstract_expression.h"
#include "bool_expression.h"
#include "comparison_expression.h"
#include "symbol_finder.h"

std::vector<ColumnName> AbstractExpression::getAllSymbols()
{
  std::shared_ptr<SymbolFinder> symbol_finder = std::make_shared<SymbolFinder>();
  traverse(symbol_finder);
  return symbol_finder->symbols_;
}

AbstractExpressionRef AbstractExpression::expression_factory(AbstractExpressionRef lhs, AbstractExpressionRef rhs, OperatorType ope_type)
{
  switch (ope_type) {
    case OperatorType::OR :
    case OperatorType::AND :
    case OperatorType::NOT :
      return std::make_shared<BoolExpression>(std::move(lhs), std::move(rhs), ope_type);
    case OperatorType::LessThanOrEqual:
    case OperatorType::LessThan:
    case OperatorType::NotEqual:
    case OperatorType::GreaterThanOrEqual:
    case OperatorType::GreaterThan:
    case OperatorType::Equal:
      return std::make_shared<ComparisonExpression>(std::move(lhs), std::move(rhs), ope_type);
    default:
      LOG_PANIC("create expression error");
      assert(false);
  }
}