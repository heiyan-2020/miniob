#include "group_aggregate_node.h"
#include "sql/expr/column_value_expression.h"
#include "sql/expr/function_call.h"

#include <utility>

GroupAggregateNode::GroupAggregateNode(PlanNodeRef child, std::vector<AbstractExpressionRef> group_by_exprs,
    std::map<std::string, AbstractExpressionRef> aggregates) :
      child_{std::move(child)}, group_by_exprs_{std::move(group_by_exprs)}, aggregates_{std::move(aggregates)}
{}

RC GroupAggregateNode::prepare()
{
  RC rc;
  assert(left_child_);
  left_child_->prepare();
  input_schema_ = left_child_->get_schema();
  rc = prepare_schema(input_schema_);
  return rc;
}

RC GroupAggregateNode::next()
{
  return LOCKED_SHAREDCACHE;
}

RC GroupAggregateNode::current_tuple(TupleRef &tuple)
{
  return LOCKED_SHAREDCACHE;
}

RC GroupAggregateNode::prepare_schema(SchemaRef input_schema)
{
  std::vector<Column> columns;
  std::vector<Column> tmp;

  // add columns based on the GROUP BY expression
  for (const auto& expr : group_by_exprs_) {
    std::shared_ptr<ColumnValueExpression> col_expr = std::dynamic_pointer_cast<ColumnValueExpression>(expr);
    if (col_expr) {
      // column reference expression.
      ColumnName col_name(col_expr->get_col_name());
      if (!col_name.is_wild_card()) {
        std::string table_name;
        if (!col_name.column_name().empty()) {
          table_name = col_name.table_name();
        }
        tmp = input_schema->find_columns(table_name, col_name.column_name());
        if (tmp.size() != 1) {
          return RC::INTERNAL;
        }
        columns.insert(columns.end(), tmp.begin(), tmp.end());
      } else {
        return RC::GENERIC_ERROR;
      }
    } else {
      return RC::UNIMPLENMENT;
    }
  }

  // add columns for aggregate function calls
  for (const auto& it : aggregates_) {
    auto expr = it.second;
    std::shared_ptr<FunctionCall> fn = std::dynamic_pointer_cast<FunctionCall>(expr);
    if (!fn) {
      return RC::INTERNAL;
    }
    
  }

  return RC::SUCCESS;
}
