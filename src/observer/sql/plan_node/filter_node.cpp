//
// Created by 37034 on 10/13/2022.
//

#include "filter_node.h"

#include <utility>

RC FilterNode::prepare()
{
  RC rc;
  assert(left_child_);
  rc = left_child_->prepare();
  output_schema_ = left_child_->get_schema();
  return rc;
}

RC FilterNode::next()
{
  RC rc;
  while ((rc = left_child_->next()) == RC::SUCCESS) {
    rc = left_child_->current_tuple(current_);
    if (rc != RC::SUCCESS) {
      return rc;
    }

    bool result = false;
    rc = is_selected(current_, result);

    if (rc != RC::SUCCESS || result) {
      return rc;
    }
  }

  return rc;
}

RC FilterNode::current_tuple(TupleRef &tuple)
{
  tuple = current_;
  return RC::SUCCESS;
}

RC FilterNode::is_selected(TupleRef tuple, bool &result)
{
  if (!predicate_) {
    result = true;
    return RC::SUCCESS;
  }

  env_->clear();
  env_->add_tuple(output_schema_, std::move(tuple));
  Value val;
  RC rc = predicate_->evaluate(env_, val);
  if (rc == RC::SUCCESS) {
    result = val.get_as<bool>();
    return rc;
  }
  LOG_ERROR("Evaluation failed");
  return rc;
}