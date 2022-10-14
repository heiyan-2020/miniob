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
  return rc;
}

RC SortNode::next()
{
  return LOCKED_SHAREDCACHE;
}

RC SortNode::current_tuple(TupleRef &tuple)
{
  return LOCKED_SHAREDCACHE;
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
