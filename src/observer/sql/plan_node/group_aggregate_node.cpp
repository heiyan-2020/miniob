#include "group_aggregate_node.h"
#include "sql/expr/column_value_expression.h"
#include "sql/expr/function_call.h"

#include <utility>

GroupAggregateNode::GroupAggregateNode(PlanNodeRef child, std::vector<AbstractExpressionRef> group_by_exprs,
    std::map<std::string, AbstractExpressionRef> aggregates) :
      PlanNode(std::move(child)), group_by_exprs_{std::move(group_by_exprs)}, aggregates_{std::move(aggregates)}
{}

RC GroupAggregateNode::prepare()
{
  RC rc;
  assert(left_child_);
  rc = left_child_->prepare();
  if (rc != RC::SUCCESS) {
    return rc;
  }
  input_schema_ = left_child_->get_schema();
  rc = prepare_output_schema(input_schema_);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  rc = prepare_group_values_schema(input_schema_);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  return compute_aggregates();
}

RC GroupAggregateNode::initialize()
{
  return RC::UNIMPLENMENT;
}

RC GroupAggregateNode::next()
{
  return LOCKED_SHAREDCACHE;
}

RC GroupAggregateNode::current_tuple(TupleRef &tuple)
{
  return LOCKED_SHAREDCACHE;
}

RC GroupAggregateNode::prepare_output_schema(SchemaRef input_schema)
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
    AbstractExpressionRef expr = it.second;
    std::shared_ptr<FunctionCall> fn_call = std::dynamic_pointer_cast<FunctionCall>(expr);
    if (!fn_call) {
      return RC::INTERNAL;
    }
    AbstractFunctionRef fn = fn_call->get_fn();
    std::shared_ptr<AggregateFunction> agg_fn = std::dynamic_pointer_cast<AggregateFunction>(fn);
    if (!fn_call) {
      return RC::INTERNAL;
    }
    auto args = fn_call->get_args();
    if (args.size() != 1) {
      LOG_ERROR("aggregate function should have one argument");
      return RC::GENERIC_ERROR;
    }
    Value value = agg_fn->get_return_type(args, input_schema);
    ColumnName column_name{fn_call->to_string()};
    columns.emplace_back(column_name, value.get_type(), value.get_len());
  }

  output_schema_ = std::make_shared<Schema>(std::move(columns));
  return RC::SUCCESS;
}

RC GroupAggregateNode::compute_aggregates()
{
  if (group_by_exprs_.empty()) {
    TupleRef current_tuple;
    while (true) {
      RC rc = left_child_->next();
      if (rc != RC::RECORD_EOF) {
        return rc;
      }
      rc = left_child_->current_tuple(current_tuple);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      TupleRef group_values;
      rc = evaluate_group_by_exprs(current_tuple, group_values);
      if (rc != RC::SUCCESS) {
        return rc;
      }
    }
  } else {

  }
  return RC::SUCCESS;
}

RC GroupAggregateNode::evaluate_group_by_exprs(TupleRef original_tuple, TupleRef &out_tuple)
{
  if (group_by_exprs_.empty()) {
    return RC::SUCCESS;
  }

  std::vector<Value> group_values;
  char *tmp = (char *)calloc(4, sizeof(char));
  common::Bitmap output_null_field_bitmap{tmp, 32};

  env_->clear();
  env_->add_tuple(input_schema_, original_tuple);

  for (const auto& group_by_expr : group_by_exprs_) {
    Value eval_result;
    RC rc = group_by_expr->evaluate(env_, eval_result);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    // TODO(vgalaxy): evaluation result may be null?
    group_values.push_back(eval_result);
  }

  out_tuple = std::make_shared<Tuple>(group_values, output_schema_, tmp);
  free(tmp);
  return RC::SUCCESS;
}

RC GroupAggregateNode::prepare_group_values_schema(SchemaRef input_schema)
{
  if (group_by_exprs_.empty()) {
    return RC::SUCCESS;
  }
  std::vector<Column> columns{};
  for (const auto& group_by_expr : group_by_exprs_) {
    std::shared_ptr<ColumnValueExpression> expr = std::dynamic_pointer_cast<ColumnValueExpression>(group_by_expr);
    if (!expr) {
      LOG_ERROR("group by exprs contains non-column-value expr");
      return RC::UNIMPLENMENT;
    }
    size_t idx;
    RC rc = input_schema->get_column_idx(expr->get_col_name(), idx);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    columns.push_back(input_schema->get_column(idx));
  }
  group_values_schema_ = std::make_shared<Schema>(std::move(columns));
  return RC::SUCCESS;
}
