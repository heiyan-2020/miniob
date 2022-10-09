#include "abstract_expression.h"
#include "symbol_finder.h"

std::vector<ColumnName> AbstractExpression::getAllSymbols()
{
  std::shared_ptr<SymbolFinder> symbol_finder = std::make_shared<SymbolFinder>();
  traverse(symbol_finder);
  return symbol_finder->symbols_;
}