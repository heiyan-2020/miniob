#pragma once
#include "abstract_expression.h"
#include "binary_expression.h"

class SymbolFinder;

class BoolExpression : public AbstractExpression {
  friend SymbolFinder;

public:
  public:
    BoolExpression(AbstractExpressionRef &&left, AbstractExpressionRef &&right, OperatorType type)
        : AbstractExpression({std::move(left), std::move(right)}), ope_type_(type) {}

    BoolExpression(AbstractExpressionRef &&left, OperatorType type)
        : AbstractExpression({std::move(left)}), ope_type_(type) {}

    BoolExpression(std::unordered_set<AbstractExpressionRef> terms, OperatorType type)
        : ope_type_(type)
    {
      for (auto &term : terms) {
        children_.push_back(term);
      }
    }


    RC evaluate(EnvRef env, Value &out_value) override;

    AbstractExpressionRef traverse(ProcessorRef processor) override;

    auto convert_to_column(SchemaRef schema, Column &out_col) -> RC override
    {
      out_col = {ColumnName(to_string()), TypeId::BOOL, Type::get_type_size( TypeId::BOOL)};
      return RC::SUCCESS;
    }

    std::string to_string() const override
    {
      assert(ope_type_ != OperatorType::NOT);
      assert(children_.size() == 2);
      // always 2 children in testcases.
      std::string left = children_[0]->to_string();
      std::string right = children_[1]->to_string();
      return left + " " + AbstractExpression::op_to_string(ope_type_) + " " + right;
    }

    auto get_ope_type() const -> OperatorType
    {
      return ope_type_;
    }

    auto get_terms() -> std::vector<AbstractExpressionRef> &
    {
      return children_;
    }

private:
  OperatorType ope_type_;
};