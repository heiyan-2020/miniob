#include "group_aggregate_node.h"

GroupAggregateNode::GroupAggregateNode(PlanNodeRef child, std::vector<AbstractExpressionRef> group_by_exprs,
    std::map<std::string, AbstractFunctionRef> aggregates)
{}

RC GroupAggregateNode::prepare()
{
  return LOCKED_SHAREDCACHE;
}

RC GroupAggregateNode::next()
{
  return LOCKED_SHAREDCACHE;
}

RC GroupAggregateNode::current_tuple(TupleRef &tuple)
{
  return LOCKED_SHAREDCACHE;
}
