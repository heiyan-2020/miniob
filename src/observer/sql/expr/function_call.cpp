#include "function_call.h"

std::map<std::string, FunctionType> FunctionCall::function_directory = {
    {"count", FunctionType::COUNT},
    {"sum", FunctionType::SUM},
    {"max", FunctionType::MAX},
    {"min", FunctionType::MIN},
};

auto FunctionCall::function_factory(const std::string &fn_name, AbstractFunctionRef &out_fn) -> RC
{
  auto find = function_directory.find(fn_name);
  if (find == function_directory.end()) {
    return RC::UNIMPLENMENT;
  }
  switch (find->second) {
    case FunctionType::SUM:
      break;
    case FunctionType::COUNT:
      out_fn = std::make_shared<CountAggregate>();
      return RC::SUCCESS;
    case FunctionType::MAX:
      break;
    case FunctionType::MIN:
      break;
  }
  return RC::UNIMPLENMENT;
}
