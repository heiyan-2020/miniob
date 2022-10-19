#include "function_call.h"
#include "sql/function/avg_aggregate.h"
#include "sql/function/max_aggregate.h"
#include "sql/function/min_aggregate.h"
#include "sql/function/sum_aggregate.h"
#include "sql/function/round_function.h"
#include "sql/function/length_function.h"
#include "sql/function/date_format_function.h"

std::map<std::string, FunctionType> FunctionCall::function_directory = {
    {"count", FunctionType::COUNT},
    {"avg", FunctionType::AVG},
    {"max", FunctionType::MAX},
    {"min", FunctionType::MIN},
    {"sum", FunctionType::SUM},
    {"round", FunctionType::ROUND},
    {"length", FunctionType::LENGTH},
    {"date_format", FunctionType::DATE_FORMAT},
};

auto FunctionCall::function_factory(const std::string &fn_name, AbstractFunctionRef &out_fn) -> RC
{
  auto find = function_directory.find(fn_name);
  if (find == function_directory.end()) {
    return RC::UNIMPLENMENT;
  }
  switch (find->second) {
    case FunctionType::AVG:
      out_fn = std::make_shared<AvgAggregate>();
      return RC::SUCCESS;
    case FunctionType::COUNT:
      out_fn = std::make_shared<CountAggregate>();
      return RC::SUCCESS;
    case FunctionType::MAX:
      out_fn = std::make_shared<MaxAggregate>();
      return RC::SUCCESS;
    case FunctionType::MIN:
      out_fn = std::make_shared<MinAggregate>();
      return RC::SUCCESS;
    case FunctionType::SUM:
      out_fn = std::make_shared<SumAggregate>();
      return RC::SUCCESS;
    case FunctionType::ROUND:
      out_fn = std::make_shared<RoundFunction>();
      return RC::SUCCESS;
    case FunctionType::LENGTH:
      out_fn = std::make_shared<LengthFunction>();
      return RC::SUCCESS;
    case FunctionType::DATE_FORMAT:
      out_fn = std::make_shared<DateFormatFunction>();
      return RC::SUCCESS;
  }
  return RC::UNIMPLENMENT;
}
