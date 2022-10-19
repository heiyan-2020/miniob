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
  return RC::SUCCESS;
}

RC GroupAggregateNode::initialize()
{
  initialized_ = false;
  computed_aggregates_.clear();
  left_child_->initialize();
  return RC::SUCCESS;
}

RC GroupAggregateNode::next()
{
  if (!initialized_) {
    RC rc = compute_aggregates();
    if (rc != RC::SUCCESS) {
      return rc;
    }
    initialized_ = true;
  }
  if (!computed_aggregates_.empty()) {
    return RC::SUCCESS;
  }
  return RC::RECORD_EOF;
}

RC GroupAggregateNode::current_tuple(TupleRef &tuple)
{
  if (computed_aggregates_.empty()) {
    return RC::RECORD_EOF;
  }

  auto curr = *computed_aggregates_.begin();
  auto group_values = curr.first;
  auto group_aggregates = curr.second;
  computed_aggregates_.erase(group_values);

  char *tmp = (char *)calloc(4, sizeof(char));
  common::Bitmap output_null_field_bitmap{tmp, 32};

  std::vector<Value> values;

  size_t idx{};
  for (const auto &value : group_values.values) {
    values.push_back(value);
    idx++;
  }

  for (const auto &it : group_aggregates) {
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
    Value res = agg_fn->get_result();
    if (res.is_null()) {
      output_null_field_bitmap.set_bit(idx);
    }
    values.push_back(res);
    idx++;
  }

  tuple = std::make_shared<Tuple>(values, output_schema_, tmp);
  free(tmp);
  return RC::SUCCESS;
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
    if (value.get_type() == UNDEFINED) {
      LOG_ERROR("aggregate function return type error");
      return RC::GENERIC_ERROR;
    }
    ColumnName column_name{fn_call->to_string()};
    columns.emplace_back(column_name, value.get_type(), value.get_len());
  }

  output_schema_ = std::make_shared<Schema>(std::move(columns));
  return RC::SUCCESS;
}

RC GroupAggregateNode::compute_aggregates()
{
  TupleRef current_tuple;
  RC rc;
  while (true) {
    rc = left_child_->next();
    if (rc == RECORD_EOF) {
      break ;
    }
    if (rc != RC::SUCCESS) {
      return rc;
    }
    rc = left_child_->current_tuple(current_tuple);
    if (rc != RC::SUCCESS) {
      return rc;
    }

    env_->clear();
    env_->add_tuple(input_schema_, current_tuple);

    HashAggregateKey group_values{};
    rc = evaluate_group_by_exprs(current_tuple, group_values);
    if (rc != RC::SUCCESS) {
      return rc;
    }

    std::map<std::string, AbstractExpressionRef> group_aggregates{};
    auto find = computed_aggregates_.find(group_values);
    if (find == computed_aggregates_.end()) {
      for (const auto& it : aggregates_) {
        auto expr = it.second;
        std::shared_ptr<FunctionCall> fn_call = std::dynamic_pointer_cast<FunctionCall>(expr);
        if (!fn_call) {
          return RC::INTERNAL;
        }
        AbstractFunctionRef fn;
        rc = FunctionCall::function_factory(fn_call->get_fn_name(), fn);  // construct new fn here
        if (rc != RC::SUCCESS) {
          return rc;
        }
        auto args = fn_call->get_args();
        AbstractExpressionRef expr_copy = std::make_shared<FunctionCall>(fn_call->get_fn_name(), args, fn);
        group_aggregates.emplace(it.first, expr_copy);
      }
    } else {
      group_aggregates = find->second;
      computed_aggregates_.erase(group_values);
    }
    rc = update_aggregates(group_aggregates);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    computed_aggregates_.emplace(group_values, group_aggregates);
  }
  return RC::SUCCESS;
}

RC GroupAggregateNode::update_aggregates(std::map<std::string, AbstractExpressionRef> group_aggregates)
{
  for (const auto &it : group_aggregates) {
    auto expr = it.second;
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
    auto arg = args[0];
    Value eval_result;
    std::shared_ptr<ColumnValueExpression> col_expr = std::dynamic_pointer_cast<ColumnValueExpression>(arg);
    if (!(col_expr && col_expr->get_col_name().is_wild_card())) {
      // eval non-star-expr
      RC rc = arg->evaluate(env_, eval_result);
      if (rc != RC::SUCCESS) {
        return rc;
      }
    } else {
      eval_result = Value{INT, 0};  // dummy value to avoid null
    }
    agg_fn->add_value(eval_result);
  }
  return RC::SUCCESS;
}

RC GroupAggregateNode::evaluate_group_by_exprs(TupleRef original_tuple, HashAggregateKey &out_values)
{
  if (group_by_exprs_.empty()) {
    return RC::SUCCESS;
  }

  std::vector<Value> group_values;
  for (const auto& group_by_expr : group_by_exprs_) {
    Value eval_result;
    RC rc = group_by_expr->evaluate(env_, eval_result);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    // TODO(vgalaxy): evaluation result may be null?
    group_values.push_back(eval_result);
  }

  out_values = HashAggregateKey{group_values};
  return RC::SUCCESS;
}

