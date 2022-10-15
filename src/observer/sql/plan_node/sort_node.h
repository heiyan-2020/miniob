#pragma once
#ifndef MINIOB_SORT_NODE_H
#define MINIOB_SORT_NODE_H

#include <utility>

#include "plan_node.h"
#include "sql/table/tuple_comparator.h"

class SortNode : public PlanNode {
public:
  SortNode(std::shared_ptr<PlanNode> left_child, std::vector<hsql::OrderDescription*>* order_by_spec_)
      : PlanNode(std::move(left_child)), order_by_spec_(order_by_spec_)
  {}
  ~SortNode() override = default;
  
  RC prepare() override;
  RC initialize() override
  {
    current_.reset();
    left_child_->initialize();
    return RC::SUCCESS;
  }
  RC next() override;

  RC current_tuple(TupleRef &tuple) override;

private:
  RC prepare_comparator();
  RC prepare_sorted_res();

  TupleComparatorRef comparator;
  std::vector<hsql::OrderDescription*>* order_by_spec_;
  std::vector<TupleRef> sorted_res_;
  TupleRef current_;
  int current_tuple_index;

};

#endif  // MINIOB_SORT_NODE_H