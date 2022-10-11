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

RC AbstractExpression::expression_factory(AbstractExpressionRef lhs, AbstractExpressionRef rhs, OperatorType ope_type, AbstractExpressionRef &out)
{
  switch (ope_type) {
    case OperatorType::OR :
    case OperatorType::AND :
    case OperatorType::NOT : {
      out = std::make_shared<BoolExpression>(std::move(lhs), std::move(rhs), ope_type);
      return RC::SUCCESS;
    }
    case OperatorType::LessThanOrEqual:
    case OperatorType::LessThan:
    case OperatorType::NotEqual:
    case OperatorType::GreaterThanOrEqual:
    case OperatorType::GreaterThan:
    case OperatorType::Equal: {
      out = std::make_shared<ComparisonExpression>(std::move(lhs), std::move(rhs), ope_type);
      return RC::SUCCESS;
    }
    default:
      LOG_PANIC("create expression error");
      return RC::UNIMPLENMENT;
  }
}