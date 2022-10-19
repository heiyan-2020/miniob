//
// Created by 37034 on 10/19/2022.
//
#include "rename_node.h"


RC RenameNode::prepare()
{
  RC rc;
  assert(left_child_);
  rc = left_child_->prepare();
  output_schema_ = left_child_->get_schema();
  output_schema_->set_table_name(alias_);
  return rc;
}

RC RenameNode::next()
{
  RC rc = left_child_->next();
  return rc;
}

RC RenameNode::current_tuple(TupleRef &tuple)
{
  RC rc = left_child_->current_tuple(current_);
  HANDLE_EXCEPTION(rc, "Rename node");
  tuple = current_;
  return RC::SUCCESS;
}