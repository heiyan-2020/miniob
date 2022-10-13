#include "nested_loop_join_node.h"

RC NestedLoopJoinNode::prepare()
{
  left_child_->prepare();
  right_child_->prepare();

  output_schema_ = std::make_shared<Schema>(left_child_->get_schema(), right_child_->get_schema());

  return RC::UNIMPLENMENT;
}

RC NestedLoopJoinNode::next()
{
  return RC::UNIMPLENMENT;
}

RC NestedLoopJoinNode::current_tuple(TupleRef &tuple)
{
  return RC::UNIMPLENMENT;
}

