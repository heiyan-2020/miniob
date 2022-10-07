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
  if (!record_scanner_.has_next()) {
    return RC::RECORD_EOF;
  }

  RC rc = record_scanner_.next(current_record_);
  return rc;
}

TupleRef TableScanNode::current_tuple()
{
  current_ = std::make_shared<Tuple>(&current_record_);
  return current_;
}
