//
// Created by 37034 on 10/4/2022.
//

#ifndef MINIDB_TABLE_SCAN_NODE_H
#define MINIDB_TABLE_SCAN_NODE_H
#include "plan_node.h"
#include "storage/record/record_manager.h"

class TableScanNode : public PlanNode {
public:
  TableScanNode(Table *table, hsql::Expr *predicate) : table_(table), predicate_(predicate)
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

  Tuple *current_tuple() override;

  hsql::Expr *get_predicate()
  {
    return predicate_;
  }
  void set_predicate(hsql::Expr *expr)
  {
    predicate_ = expr;
  }

private:
  Table *table_;
  hsql::Expr *predicate_;
  RowTuple current_;
  RecordFileScanner record_scanner_;
  Record current_record_;
};

#endif  // MINIDB_TABLE_SCAN_NODE_H
