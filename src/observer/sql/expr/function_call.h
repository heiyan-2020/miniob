#pragma once

#include <string>
#include <utility>
#include <vector>
#include "abstract_expression.h"
#include "sql/function/abstract_function.h"
#include "sql/function/count_aggregate.h"
#include "leaf_node_expression.h"
#include "sql/function/simple_function.h"

enum class FunctionType {
  AVG, COUNT, MAX, MIN, SUM, ROUND, LENGTH, DATE_FORMAT
};

class FunctionCall : public AbstractExpression {
public:
  FunctionCall(std::string name, std::vector<AbstractExpressionRef> args, AbstractFunctionRef function) :
        name_{std::move(name)}, args_{std::move(args)}, function_{std::move(function)}
  {}

  RC evaluate(EnvRef env, Value &out_value) override
  {
    std::shared_ptr<SimpleFunction> simple_fn = std::dynamic_pointer_cast<SimpleFunction>(function_);
    if (!simple_fn) {
      // TODO(vgalaxy): assume aggregate functions
      return RC::UNIMPLENMENT;
    }
    return simple_fn->evaluate(env, args_, out_value);
  }

  auto convert_to_column(SchemaRef schema, Column &out_col) -> RC override
  {
    std::shared_ptr<SimpleFunction> simple_fn = std::dynamic_pointer_cast<SimpleFunction>(function_);
    if (!simple_fn) {
      // TODO(vgalaxy): assume aggregate functions
      // aggregate function col has been generated in group aggregate node
      ColumnName column_name{to_string()};
      size_t idx;
      RC rc = schema->get_column_idx(column_name, idx);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      out_col = schema->get_column(idx);
      return RC::SUCCESS;
    } else {
      Value value = simple_fn->get_return_type(args_, schema);
      if (value.get_type() == UNDEFINED) {
        LOG_ERROR("simple function return type error");
        return RC::GENERIC_ERROR;
      }
      ColumnName column_name{to_string()};
      out_col = {column_name, value.get_type(), value.get_len()};
      return RC::SUCCESS;
    }
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

  auto traverse(ProcessorRef processor) -> AbstractExpressionRef override
  {
    std::shared_ptr<AbstractExpression> sp = shared_from_this();
    processor->enter(sp);

    for (auto &arg : args_) {
      arg = arg->traverse(processor);
    }

    return processor->leave(sp);
  }

  auto get_fn_name() const -> std::string
  {
    return name_;
  }

  auto get_fn() const -> AbstractFunctionRef
  {
    return function_;
  }

  auto get_args() const -> std::vector<AbstractExpressionRef>
  {
    return args_;
  }

public:
  static auto function_factory(const std::string& fn_name, AbstractFunctionRef &out_fn) -> RC;
  static std::map<std::string, FunctionType> function_directory;

private:
  std::string name_{};
  std::vector<AbstractExpressionRef> args_{};
  AbstractFunctionRef function_{};
};
