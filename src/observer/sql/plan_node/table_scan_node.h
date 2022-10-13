//
// Created by 37034 on 10/4/2022.
//

#ifndef MINIDB_TABLE_SCAN_NODE_H
#define MINIDB_TABLE_SCAN_NODE_H

#include "plan_node.h"
#include "storage/record/record_manager.h"
#include "storage/common/table.h"

class TableScanNode : public PlanNode {
public:
  TableScanNode(Table *table, AbstractExpressionRef predicate) : PlanNode(), table_(table), predicate_(predicate)
  {}
  ~TableScanNode() override
  {
    record_scanner_.close_scan();
  }
  RC prepare() override;
  RC initialize() override
  {
    return RC::UNIMPLENMENT;
  }
  RC next() override;

  RC current_tuple(TupleRef &tuple) override;

  AbstractExpressionRef get_predicate()
  {
    return predicate_;
  }
  void set_predicate(AbstractExpressionRef expr)
  {
    predicate_ = expr;
  }

private:
  // support error handling, so use out_param to convey return value.
  RC is_selected(TupleRef tuple, bool &result);

private:
  Table *table_;
  AbstractExpressionRef predicate_;
  TupleRef current_;
  RecordFileScanner record_scanner_;
  Record current_record_;
};

#endif  // MINIDB_TABLE_SCAN_NODE_H
