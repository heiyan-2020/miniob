#include "bool_expression.h"

RC BoolExpression::evaluate(EnvRef env, Value &out_value)
{
  RC rc = RC::EVALUATE;
  if (children_.empty()) {
    return RC::EVALUATE;
  }

  Value child_result;

  if (ope_type_ == OperatorType::NOT) {
    if (children_.size() != 1) {
      return RC::EVALUATE;
    }

    rc = children_[0]->evaluate(env, child_result);
    if (rc != RC::SUCCESS || child_result.get_type() != TypeId::BOOL) {
      return rc;
    }
    out_value = child_result.negation();
    if (child_result.is_null()) {
      out_value = {BOOL, false};
    }
    return RC::SUCCESS;
  } else {
    if (children_.size() < 1) {
      return RC::EVALUATE;
    }
    bool inter_result;
    if (ope_type_ == OperatorType::AND) {
      inter_result = true;
    } else if (ope_type_ == OperatorType::OR) {
      inter_result = false;
    } else {
      // shouldn't reach here.
      LOG_WARN("Unrecognized operator type");
      return RC::EVALUATE;
    }

    for (const auto &child : children_) {
      rc = child->evaluate(env, child_result);
      if (rc != RC::SUCCESS || child_result.get_type() != TypeId::BOOL) {
        return RC::EVALUATE;
      }
      if (ope_type_ == OperatorType::AND && !child_result.get_as<bool>()) {
        inter_result = false;
        break;
      } else if (ope_type_ == OperatorType::OR && child_result.get_as<bool>()) {
        inter_result = true;
        break;
      }
    }
    out_value = Value{TypeId::BOOL, inter_result};
    return RC::SUCCESS;
  }
}

AbstractExpressionRef BoolExpression::traverse(ProcessorRef processor)
{
  std::shared_ptr<AbstractExpression> sp = shared_from_this();
  processor->enter(sp);

  for (auto &child : children_) {
    child = child->traverse(processor);
  }

  return processor->leave(sp);
}
