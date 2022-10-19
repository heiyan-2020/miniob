#pragma once

#include "abstract_expression.h"

enum ThreeValueLogic {FALSE, UNKNOWN, TRUE};

class InValueExpression : public AbstractExpression {
public:
  InValueExpression(AbstractExpressionRef &&left, std::vector<AbstractExpressionRef> right)
  {
    children_.push_back(std::move(left));
    children_.insert(children_.end(), right.begin(), right.end());
  }

  RC evaluate(EnvRef env, Value &out_value) override
  {
    Value lhs;
    RC rc;
    rc = children_[0]->evaluate(env, lhs);
    HANDLE_EXCEPTION(rc, "Left expression of IN operator evaluation failed");

    std::vector<Value> value_list(children_.size() - 1);
    for (size_t idx = 1; idx < children_.size(); idx++) {
      rc = children_[idx]->evaluate(env, value_list[idx - 1]);
      HANDLE_EXCEPTION(rc, "Right expression of IN operator evaluation failed");
    }

    ThreeValueLogic res = FALSE;

    for (const auto &val : value_list) {
      if (lhs.is_null() || val.is_null()) {
        res = ThreeValueLogic::UNKNOWN;
      } else if (lhs.compare_equals(val).get_as<bool>()) {
        res = ThreeValueLogic::TRUE;
        break;
      }
    }

    if (res == ThreeValueLogic::FALSE) {
      out_value = {BOOL, false};
    } else if (res == ThreeValueLogic::UNKNOWN) {
      out_value = {BOOL, false};
      // Using is_null_ to indicate that this is UNKOWN
      out_value.is_null_ = true;
    } else {
      out_value = {BOOL, true};
    }
    return RC::SUCCESS;
  }

  virtual RC traverse(ProcessorRef processor, AbstractExpressionRef &out_value)
  {
    std::shared_ptr<AbstractExpression> sp = shared_from_this();
    RC rc;
    rc = processor->enter(sp);
    HANDLE_EXCEPTION(rc, "");
    AbstractExpressionRef out;

    for (auto &child : children_) {
      rc = child->traverse(processor, out);
      HANDLE_EXCEPTION(rc, "");
      child = out;
      out.reset();
    }
    out_value = processor->leave(sp);

    return RC::SUCCESS;
  }

  auto convert_to_column(SchemaRef schema, Column &out_col) -> RC override
  {
    return RC::UNIMPLENMENT;
  }

  std::string to_string() const override
  {
    return {};
  }
};