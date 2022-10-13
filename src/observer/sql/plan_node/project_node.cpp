//
// Created by 37034 on 10/5/2022.
//
#include "project_node.h"
#include "sql/expr/column_value_expression.h"

#include <utility>
#include "common/log/log.h"

RC ProjectNode::prepare()
{
  RC rc;
  assert(left_child_);
  left_child_->prepare();
  input_schema_ = left_child_->get_schema();
  rc = prepare_schema(input_schema_);
  return rc;
}

RC ProjectNode::next()
{
  if (left_child_) {
    return left_child_->next();
  }
  LOG_WARN("Project node should have a child.");
  return RC::GENERIC_ERROR;
}

RC ProjectNode::current_tuple(TupleRef &tuple)
{
  RC rc;
  rc = left_child_->current_tuple(current_);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  rc = project_tuple(current_, tuple);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  return RC::SUCCESS;
}

RC ProjectNode::prepare_schema(SchemaRef input_schema)
{
  std::vector<Column> columns;
  std::vector<Column> tmp;

  for (AbstractExpressionRef &expr : projection_spec_) {
    std::shared_ptr<ColumnValueExpression> col_expr = std::dynamic_pointer_cast<ColumnValueExpression>(expr);
    if (col_expr) {
      // column reference expression.
      ColumnName col_name(col_expr->get_col_name());
      if (col_name.is_wild_card()) {
        if (col_name.table_name().empty()) {
          // *
          tmp = input_schema->find_columns({}, {});
          columns.insert(columns.end(), tmp.begin(), tmp.end());
        } else {
          // t.*
          tmp = input_schema->find_columns(col_name.table_name(), {});
          columns.insert(columns.end(), tmp.begin(), tmp.end());
        }
      } else {
        std::string table_name;
        if (!col_name.column_name().empty())
          table_name = col_name.table_name();
        tmp = input_schema->find_columns(table_name, col_name.column_name());
        if (tmp.size() != 1) {
          return RC::INTERNAL;
        }
        columns.insert(columns.end(), tmp.begin(), tmp.end());
      }
    } else {
      // complicated expression
      Column exp_col;
      if (expr->convert_to_column(input_schema_, exp_col) != RC::SUCCESS) {
        return RC::SCHEMA;
      }
      columns.push_back(exp_col);
    }
  }
  output_schema_ = std::make_shared<Schema>(columns);
  return RC::SUCCESS;
}

RC ProjectNode::project_tuple(TupleRef original_tuple, TupleRef &out_tuple)
{
  RC rc;

  env_->clear();
  env_->add_tuple(input_schema_, original_tuple);

  std::vector<Value> out_tuple_values;
  std::vector<Column> involved_columns;

  common::Bitmap input_null_field_bitmap{original_tuple->get_record().data(), 32};
  char *tmp = (char *)calloc(4, sizeof(char));
  common::Bitmap output_null_field_bitmap{tmp, 32};

  for (AbstractExpressionRef expr : projection_spec_) {
    std::shared_ptr<ColumnValueExpression> col_expr = std::dynamic_pointer_cast<ColumnValueExpression>(expr);
    if (col_expr) {
      // column reference expression. including *, t.*, t.col
      ColumnName col_name(col_expr->get_col_name());
      involved_columns = input_schema_->find_columns(col_name.table_name(), col_name.column_name());
      for (Column &column : involved_columns) {
        size_t idx;
        rc = input_schema_->get_column_idx(column.get_name(), idx);
        if (rc != RC::SUCCESS) {
          return RC::INTERNAL;
        }
        if (input_null_field_bitmap.get_bit(idx)) {
          out_tuple_values.emplace_back(input_schema_->get_column(idx).get_type());
          output_null_field_bitmap.set_bit(idx);
        } else {
          out_tuple_values.push_back(original_tuple->get_value(input_schema_, idx));
        }
      }
    } else {
      // complicated expression.
      Value eval_result;
      rc = expr->evaluate(env_, eval_result);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      // TODO(zyx): evaluation result may be null?
      out_tuple_values.push_back(eval_result);
    }
  }

  out_tuple = std::make_shared<Tuple>(out_tuple_values, output_schema_, tmp);
  free(tmp);
  return RC::SUCCESS;
}
