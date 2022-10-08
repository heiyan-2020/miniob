//
// Created by 37034 on 10/5/2022.
//

#include "table_scan_node.h"

RC TableScanNode::prepare()
{
  RC rc = table_->get_record_scanner(record_scanner_);
  if (rc == RC::SUCCESS) {}
  output_schema_ = std::make_shared<Schema>(table_, table_->table_meta().field_metas());
  return rc;
}

RC TableScanNode::next()
{
  RC rc;
  while (record_scanner_.has_next()) {
    rc = record_scanner_.next(current_record_);
    if (rc == RC::SUCCESS && is_selected(std::make_shared<Tuple>(&current_record_))) {
      return rc;
    }
  }

  return RC::RECORD_EOF;

}

TupleRef TableScanNode::current_tuple()
{
  current_ = std::make_shared<Tuple>(&current_record_);
  return current_;
}

bool TableScanNode::is_selected(TupleRef tuple)
{
  if (!predicate_)
    return true;

  env_->clear();
  env_->add_tuple(output_schema_, tuple);
  Value val;
  RC rc = predicate_->evaluate(env_, val);
  if (rc == RC::SUCCESS) {
    return val.value_.bool_;
  }
  LOG_ERROR("Evaluation failed");
  return false;
}
