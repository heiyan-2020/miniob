#include "update_operator.h"
#include "sql/stmt/update_stmt.h"

RC UpdateOperator::open()
{
  if (children_.size() != 1) {
    LOG_WARN("update operator must has 1 child");
    return RC::INTERNAL;
  }

  Operator *child = children_[0];
  RC rc = child->open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  Table *table = update_stmt_->table();
  const TableMeta &table_meta = table->table_meta();
  const FieldMeta *field_meta = table_meta.find_field_by_offset(update_stmt_->value_offset());
  if (nullptr == field_meta) {
    LOG_WARN("update stmt offset has no related field");
    return RC::INTERNAL;
  }

  while (RC::SUCCESS == (rc = child->next())) {
    Tuple *tuple = child->current_tuple();
    if (nullptr == tuple) {
      LOG_WARN("failed to get current record: %s", strrc(rc));
      return rc;
    }

    auto *row_tuple = dynamic_cast<RowTuple *>(tuple);
    Record &old_record = row_tuple->record();

    // update data
    int record_size = table_meta.record_size();
    char *data = new char[record_size];
    memcpy(data, old_record.data(), record_size);
    const Value *value = update_stmt_->value();
    memcpy(data + field_meta->offset(), value->data, field_meta->len());

    Record new_record;
    new_record.set_rid(old_record.rid());
    new_record.set_data(data);

    // update record
    rc = table->update_record(nullptr, &old_record, &new_record);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to update record: %s", strrc(rc));
      return rc;
    }
  }
  return RC::SUCCESS;
}

RC UpdateOperator::next()
{
  return RC::RECORD_EOF;
}

RC UpdateOperator::close()
{
  children_[0]->close();
  return RC::SUCCESS;
}
