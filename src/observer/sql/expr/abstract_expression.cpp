#include "abstract_expression.h"
#include "bool_expression.h"
#include "comparison_expression.h"
#include "arithmetic_expression.h"
#include "negate_expression.h"
#include "isnull_expression.h"
#include "symbol_finder.h"
#include "in_expression.h"

std::vector<ColumnName> AbstractExpression::get_all_symbols()
{
  std::shared_ptr<SymbolFinder> symbol_finder = std::make_shared<SymbolFinder>();
  traverse(symbol_finder);
  return symbol_finder->symbols_;
}

RC AbstractExpression::expression_factory(AbstractExpressionRef lhs, AbstractExpressionRef rhs, OperatorType ope_type, AbstractExpressionRef &out)
{
  switch (ope_type) {
    case OperatorType::OR :
    case OperatorType::AND : {
      out = std::make_shared<BoolExpression>(std::move(lhs), std::move(rhs), ope_type);
      return RC::SUCCESS;
    }
    case OperatorType::NOT : {
      out = std::make_shared<BoolExpression>(std::move(lhs), ope_type);
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
    case OperatorType::SLASH:
    case OperatorType::SUB:
    case OperatorType::PLUS:
    case OperatorType::MUL: {
      out = std::make_shared<ArithmeticExpression>(std::move(lhs), std::move(rhs), ope_type);
      return RC::SUCCESS;
    }
    case OperatorType::NEG: {
      out = std::make_shared<NegateExpression>(std::move(lhs));
      return RC::SUCCESS;
    }
    case OperatorType::IsNull: {
      out = std::make_shared<IsNullExpression>(std::move(lhs));
      return RC::SUCCESS;
    }
    default:
      LOG_PANIC("create expression error");
      return RC::UNIMPLENMENT;
  }
}

auto AbstractExpression::op_to_string(OperatorType op_type) -> std::string
{
  const struct info {
    OperatorType opt;
    std::string str;
  } infos[] = {
      {OperatorType::Equal, "="},
      {OperatorType::GreaterThan, ">"},
      {OperatorType::GreaterThanOrEqual, ">="},
      {OperatorType::NotEqual, "!="},
      {OperatorType::LessThan, "<"},
      {OperatorType::LessThanOrEqual, "<="},
      {OperatorType::AND, "and"},
      {OperatorType::OR, "or"},
      {OperatorType::NOT, "not"},
      {OperatorType::SLASH, "/"},
      {OperatorType::MUL, "*"},
      {OperatorType::PLUS, "+"},
      {OperatorType::SUB, "-"},
      {OperatorType::NEG, "-"}

  };
  for (auto info : infos) {
    if (info.opt == op_type) {
      return info.str;
    }
  };
  assert(false);
}