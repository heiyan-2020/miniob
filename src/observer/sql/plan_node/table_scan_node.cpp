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
    if (rc != RC::SUCCESS) {
      return rc;
    }

    bool result = false;
    rc = is_selected(std::make_shared<Tuple>(&current_record_), result);

    if (rc != RC::SUCCESS || result) {
      return rc;
    }
  }

  return RC::RECORD_EOF;

}

RC TableScanNode::current_tuple(TupleRef &tuple)
{
  RC rc = record_to_tuple(&current_record_, current_);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  tuple = current_;
  return RC::SUCCESS;
}

RC TableScanNode::is_selected(TupleRef tuple, bool &result)
{
  if (!predicate_) {
    result = true;
    return RC::SUCCESS;
  }

  env_->clear();
  env_->add_tuple(output_schema_, tuple);
  Value val;
  RC rc = predicate_->evaluate(env_, val);
  if (rc == RC::SUCCESS) {
    result = val.value_.bool_;
    return rc;
  }
  LOG_ERROR("Evaluation failed");
  return rc;
}

RC TableScanNode::record_to_tuple(Record *record, TupleRef &out_tuple)
{
  char *data = record->data();
  common::Bitmap null_field_bitmap{data, 32};
  std::vector<Value> values;
  for (size_t i = 0; i < output_schema_->get_column_count(); i++) {
    const auto &col = output_schema_->get_column(i);
    if (null_field_bitmap.get_bit(i)) {
      // null field
      values.emplace_back(col.get_type());
    } else {
      // non-null field
      values.push_back(Value{col.get_type()}.deserialize_from(data + col.get_offset(), col.get_len()));
    }
  }
  out_tuple = std::make_shared<Tuple>(values, output_schema_, data, record->rid());
  return RC::SUCCESS;
}
