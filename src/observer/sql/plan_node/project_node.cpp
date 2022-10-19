//
// Created by 37034 on 10/5/2022.
//
#include "project_node.h"
#include "sql/expr/column_value_expression.h"

#include <utility>
#include "common/log/log.h"
#include "sql/expr/function_call.h"

RC ProjectNode::prepare()
{
  RC rc;
  if (left_child_) {
    rc = left_child_->prepare();
    if (rc != RC::SUCCESS) {
      return rc;
    }

    input_schema_ = left_child_->get_schema();
    rc = prepare_schema(input_schema_);
    if (rc != RC::SUCCESS) {
      return rc;
    }
  } else {
    // Construct an empty schema to avoid nullptr error.
    input_schema_ = std::make_shared<Schema>();
  }
  rc = prepare_schema(input_schema_);
  return rc;
}

RC ProjectNode::next()
{
  RC rc;
  if (done) {
   return RC::RECORD_EOF;
  }

  if (left_child_) {
    rc = left_child_->next();
    if (rc == RC::RECORD_EOF) {
      done = true;
    }
  } else {
    // There is no from table, just iterate once.
    done = true;
    rc = RC::SUCCESS;
  }
  return rc;
}

RC ProjectNode::current_tuple(TupleRef &tuple)
{
  RC rc;
  if (left_child_) {
    rc = left_child_->current_tuple(current_);
    if (rc != RC::SUCCESS) {
      return rc;
    }
  }

  rc = project_tuple(current_, tuple);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  return RC::SUCCESS;
}

RC ProjectNode::prepare_schema(const SchemaRef& input_schema)
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
          LOG_PANIC("Ambiguous column name");
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

RC ProjectNode::project_tuple(const TupleRef& original_tuple, TupleRef &out_tuple)
{
  RC rc;

  env_->clear();
  env_->add_tuple(input_schema_, original_tuple);

  std::vector<Value> out_tuple_values;
  std::vector<Column> involved_columns;

  common::Bitmap input_null_field_bitmap;
  if (original_tuple) {
    input_null_field_bitmap = {original_tuple->get_record().data(), 32};
  }
  char *tmp = (char *)calloc(4, sizeof(char));
  common::Bitmap output_null_field_bitmap{tmp, 32};

  for (AbstractExpressionRef expr : projection_spec_) {
    std::shared_ptr<ColumnValueExpression> col_expr = std::dynamic_pointer_cast<ColumnValueExpression>(expr);
    if (col_expr) {
      // column reference expression. including *, t.*, t.col
      ColumnName col_name(col_expr->get_col_name());
      involved_columns = input_schema_->find_columns(col_name.table_name(), col_name.column_name());
      for (size_t i = 0; i < involved_columns.size(); i++) {
        size_t ori_idx; // 该列在原来 tuple 中的下标
        Column column = involved_columns[i];
        rc = input_schema_->get_column_idx(column.get_name(), ori_idx);
        if (rc != RC::SUCCESS) {
          return RC::INTERNAL;
        }
        if (input_null_field_bitmap.get_bit(ori_idx)) {
          out_tuple_values.emplace_back(input_schema_->get_column(ori_idx).get_type());
          output_null_field_bitmap.set_bit(i); // 设置 out_tuple 的 bitmap 时需要以该列在新 tuple 中的下标为准
        } else {
          out_tuple_values.push_back(original_tuple->get_value(input_schema_, ori_idx));
        }
      }
      continue;
    }

    std::shared_ptr<FunctionCall> fn_call = std::dynamic_pointer_cast<FunctionCall>(expr);
    if (fn_call) {
      std::shared_ptr<SimpleFunction> simple_fn = std::dynamic_pointer_cast<SimpleFunction>(fn_call->get_fn());
      if (!simple_fn) {
        // TODO(vgalaxy): assume aggregate functions
        Column exp_col;
        if (expr->convert_to_column(input_schema_, exp_col) != RC::SUCCESS) {
          return RC::SCHEMA;
        }
        size_t idx;
        rc = input_schema_->get_column_idx(exp_col.get_name(), idx);
        if (rc != RC::SUCCESS) {
          return RC::INTERNAL;
        }
        if (input_null_field_bitmap.get_bit(idx)) {
          out_tuple_values.emplace_back(input_schema_->get_column(idx).get_type());
          output_null_field_bitmap.set_bit(idx);
        } else {
          out_tuple_values.push_back(original_tuple->get_value(input_schema_, idx));
        }
      } else {
        Value eval_result;
        rc = expr->evaluate(env_, eval_result);
        if (rc != RC::SUCCESS) {
          return rc;
        }
        out_tuple_values.push_back(eval_result);
      }
      continue;
    }

    // complicated expression.
    Value eval_result;
    rc = expr->evaluate(env_, eval_result);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    // TODO(zyx): evaluation result may be null?
    out_tuple_values.push_back(eval_result);
  }

  out_tuple = std::make_shared<Tuple>(out_tuple_values, output_schema_, tmp);
  free(tmp);
  return RC::SUCCESS;
}
