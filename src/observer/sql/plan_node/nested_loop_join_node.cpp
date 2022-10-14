#include "nested_loop_join_node.h"

RC NestedLoopJoinNode::prepare()
{
  RC rc;
  rc = left_child_->prepare();
  if (rc != RC::SUCCESS) {
    return rc;
  }
  right_child_->prepare();

  output_schema_ = std::make_shared<Schema>(left_child_->get_schema(), right_child_->get_schema());
  return RC::SUCCESS;
}

RC NestedLoopJoinNode::next()
{
  Value val;
  RC rc;
  while ((rc = get_tuples()) == RC::SUCCESS) {
    if (can_join(val) == RC::SUCCESS && val.get_as<bool>()) {
      return RC::SUCCESS;
    }
  }

  return rc;
}

RC NestedLoopJoinNode::current_tuple(TupleRef &tuple)
{
  tuple = join_tuples(marked_left_, marked_right_);
  return RC::SUCCESS;
}

TupleRef NestedLoopJoinNode::join_tuples(TupleRef left, TupleRef right)
{
  SchemaRef left_schema = left_child_->get_schema(), right_schema = right_child_->get_schema();
  std::vector<Value> joined_values;

  common::Bitmap left_null_field_bitmap{left->get_record().data(), 32};
  common::Bitmap right_null_field_bitmap{right->get_record().data(), 32};
  char *tmp = (char *)calloc(4, sizeof(char));
  common::Bitmap output_null_field_bitmap{tmp, 32};

  for (size_t idx = 0; idx < left_schema->get_column_count(); idx++) {
    if (left_null_field_bitmap.get_bit(idx)) {
      joined_values.emplace_back(left_schema->get_column(idx).get_type());
      output_null_field_bitmap.set_bit(idx);
    } else {
      joined_values.push_back(left->get_value(left_schema, idx));
    }
  }

  size_t offset = left_schema->get_column_count();

  for (size_t idx = 0; idx < right_schema->get_column_count(); idx++) {
    if (right_null_field_bitmap.get_bit(idx)) {
      joined_values.emplace_back(right_schema->get_column(idx).get_type());
      output_null_field_bitmap.set_bit(idx + offset);
    } else {
      joined_values.push_back(right->get_value(right_schema, idx));
    }
  }

  TupleRef out = std::make_shared<Tuple>(joined_values, output_schema_, tmp);
  free(tmp);
  return out;
}

RC NestedLoopJoinNode::can_join(Value &out_value)
{
  if (!cond_) {
    return RC::SUCCESS;
  }

  env_->clear();
  env_->add_tuple(left_child_->get_schema(), marked_left_);
  env_->add_tuple(right_child_->get_schema(), marked_right_);

  if (cond_->evaluate(env_, out_value) != RC::SUCCESS) {
    return RC::EVALUATE;
  }
  return RC::SUCCESS;
}


RC NestedLoopJoinNode::get_tuples()
{
  RC rc;
  // case 0: first call, initialize left tuple.
  if (!marked_left_) {
    rc = left_child_->next();
    if (rc != RC::SUCCESS) {
      // no tuple needs to be joined.
      return rc;
    }
    rc = left_child_->current_tuple(marked_left_);
    if (rc != RC::SUCCESS) {
      // encounters some exception.
      return rc;
    }
  }
  while (true) {
    rc = right_child_->next();
    if (rc == RC::RECORD_EOF) {
      // case 1: right end, which indicates left has met all right tuples. So, iterate left and reset right.
      rc = left_child_->next();
      if (rc != RC::SUCCESS) {
        // all done or exception
        return rc;
      } else {
        left_child_->current_tuple(marked_left_);
        right_child_->initialize();
      }
    } else if (rc == RC::SUCCESS) {
      // case 2: left tuple hasn't met all right tuples.
      right_child_->current_tuple(marked_right_);
      break ;
    } else {
      // encounter some exceptions.
      return rc;
    }
  }

  return RC::SUCCESS;
}

