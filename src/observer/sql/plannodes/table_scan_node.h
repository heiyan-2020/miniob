//
// Created by 37034 on 10/4/2022.
//

#ifndef MINIDB_TABLE_SCAN_NODE_H
#define MINIDB_TABLE_SCAN_NODE_H
#include "PlanNode.h"
#include "storage/record/record_manager.h"

class TableScanNode : public PlanNode {
public:
  TableScanNode(Table *table, hsql::Expr *predicate):table_(table), predicate_(predicate) {}
  ~TableScanNode() {
    record_scanner_.close_scan();
    std::cerr << "close" << std::endl;
  }
  virtual RC prepare() override;
  virtual RC initialize() override {
    return RC::UNIMPLENMENT;
  }
  virtual RC next() override;

  virtual Tuple *current_tuple();

  hsql::Expr *getPredicate() { return predicate_; }
  void setPredicate(hsql::Expr *expr) { predicate_ = expr; }


private:
  Table *table_;
  hsql::Expr *predicate_;
  RowTuple current_;
  RecordFileScanner record_scanner_;
  Record current_record_;
};

#endif  // MINIDB_TABLE_SCAN_NODE_H
