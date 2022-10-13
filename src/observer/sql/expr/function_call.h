#pragma once

#include <string>
#include <utility>
#include <vector>
#include "abstract_expression.h"
#include "../function/abstract_function.h"

class FunctionCall : public AbstractExpression {
public:
  FunctionCall(std::string name, std::vector<AbstractExpressionRef> args) : name_{std::move(name)}, args_{std::move(args)}
  {}

  RC evaluate(EnvRef env, Value &out_value) const override
  {
    assert(false);
  }

  AbstractExpressionRef traverse(ProcessorRef processor) override
  {
    std::shared_ptr<AbstractExpression> sp = shared_from_this();
    processor->enter(sp);
    return processor->leave(sp);
  }

  auto convert_to_column(SchemaRef schema, Column &out_col) -> RC override
  {
    return RC::UNIMPLENMENT;
  }

  std::string to_string() const override
  {
    std::ostringstream oss;
    oss << name_ << "(";
    for (size_t i = 0; i < args_.size(); ++i) {
      oss << args_[i]->to_string();
      if (i != args_.size() - 1) {
        oss << ",";
      }
    }
    oss << ")";
    return oss.str();
  }

  auto get_fn_name() -> std::string
  {
    return name_;
  }

private:
  std::string name_{};
  std::vector<AbstractExpressionRef> args_{};
//  AbstractFunctionRef function_{};
};
