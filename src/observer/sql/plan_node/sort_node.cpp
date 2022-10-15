#include "sort_node.h"
#include "sql/expr/column_value_expression.h"
#include <utility>
#include "common/log/log.h"
#include "sql/expr/function_call.h"

RC SortNode::prepare()
{
  RC rc;

  assert(left_child_);
  rc = left_child_->prepare();
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to prepare left child in planNode!: %s", strrc(rc));
    return rc;
  }

  output_schema_ = left_child_->get_schema();
  rc = prepare_comparator();
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to prepare order by comparator!: %s", strrc(rc));
    return rc;
  }

  return rc;
}

RC SortNode::next()
{
  assert(left_child_);
  if (sorted_res_.empty()) {
    // here call the left_child_'s next()
    prepare_sorted_res();
  }
  else {
    current_tuple_index++;
  }
  // here using current_tuple() to iterate
  // RC::RECORD_EOF returns in SortNode::current_tuple()
  // and this case has been handled in line 36, select_command.cpp
  return RC::SUCCESS;
}

RC SortNode::current_tuple(TupleRef &tuple)
{
  // doesn't pass this func through left_child_
  // just return current tuple in sorted_res in this layer
  if (current_tuple_index < sorted_res_.size()) {
    tuple = sorted_res_[current_tuple_index];
  }
  else {
    return RC::RECORD_EOF;
  }
  return RC::SUCCESS;
}

RC SortNode::prepare_comparator()
{
  RC rc = RC::SUCCESS;
  // We can prepare the tuple-comparator here too, since we know what the
  // subplan's schema will be.
  comparator = std::make_shared<TupleComparator>(output_schema_, order_by_spec_);
  if (comparator == nullptr) {
    rc = RC::INTERNAL;
    return rc;
  }
  return rc;
}

RC SortNode::prepare_sorted_res()
{
  RC rc;
  while (true) {
    rc = left_child_->next();
    if (rc == RC::RECORD_EOF) {
      break;
    }

    left_child_->current_tuple(current_);
    sorted_res_.emplace_back(current_);
  }

  rc = comparator->sort_tuples(sorted_res_);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to sort select res!: %s", strrc(rc));
    return rc;
  }
  current_tuple_index = 0;

  return rc;
}
