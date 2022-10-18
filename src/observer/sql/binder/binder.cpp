#include "binder.h"
#include "sql/table/schema.h"
#include "util/date.h"
#include "sql/expr/symbol_finder.h"
#include "sql/expr/bool_expression.h"
#include "planner.h"
#include "sql/expr/function_call.h"
#include "sql/expr/in_expression.h"
#include "sql/expr/scalar_expression.h"
#include "sql/expr/like_expression.h"
#include "sql/expr/in_value_expression.h"
#include "sql/expr/exists_expression.h"

RC Binder::bind_select(const hsql::SelectStatement *sel_stmt)
{
  RC rc;

  // Bind from tables.
  std::unordered_set<std::string> from_table_names;
  rc = bind_from(sel_stmt->fromTable, from_schema_);
  if (rc != RC::SUCCESS) {
    LOG_WARN("Can't find table");
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }
  from_table_names = from_schema_->get_involved_tables();

  // Bind select values.
  for (const auto selVal : *sel_stmt->selectList) {
    if (selVal->isType(hsql::kExprStar)) {
      ColumnName column_name;
      if (selVal->hasTable()) {
        if (from_table_names.find(selVal->table) == from_table_names.end()) {
          return RC::SCHEMA_TABLE_NOT_EXIST;
        }
        column_name.set_table_name(selVal->table);
      }
      select_values_.push_back(std::make_shared<ColumnValueExpression>(column_name));
    } else {
      // An expression that is not a wildcard.  It could contain
      // column references that need to be resolved.
      AbstractExpressionRef bound_expr;
      rc = bind_expression(selVal, bound_expr);
      if (rc != RC::SUCCESS) {
        LOG_PANIC("Bind select values failed");
        return rc;
      }
      std::vector<ColumnName> symbols = bound_expr->get_all_symbols();
      for (auto const &name : symbols) {
        std::vector<Column> cols;
        cols = from_schema_->find_columns(name.table_name(), name.column_name());
        if (cols.size() != 1) {
          LOG_PANIC("select value has ambiguous value");
          return RC::INTERNAL;
        }
      }
      select_values_.push_back(bound_expr);
    }
  }

  // Bind where expression if there is.
  if (sel_stmt->whereClause) {
    AbstractExpressionRef expr;
    rc = bind_expression(sel_stmt->whereClause, expr);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    std::vector<ColumnName> symbols = expr->get_all_symbols();
    for (auto const &name : symbols) {
      rc = find_columns(name.table_name(), name.column_name());
      if (rc != RC::SUCCESS) {
        return rc;
      }
    }
    where_predicate_ = expr;
  }

  // Bind group by expression if there is.
  if (sel_stmt->groupBy) {
    for (auto col : *sel_stmt->groupBy->columns) {
      AbstractExpressionRef bound_expr;
      rc = bind_expression(col, bound_expr);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      std::vector<ColumnName> symbols = bound_expr->get_all_symbols();
      for (auto const &name : symbols) {
        std::vector<Column> found = from_schema_->find_columns(name.table_name(), name.column_name());
        if (found.size() != 1) {
          LOG_PANIC("group by expression has wrong column reference");
          return RC::SCHEMA_FIELD_NOT_EXIST;
        }
      }
      group_by_exprs_.push_back(bound_expr);
    }
    // TODO(vgalaxy): bind having expr
  }

  return RC::SUCCESS;
}

RC Binder::bind_from(hsql::TableRef *root_table, SchemaRef &out_schema)
{
  if (nullptr == root_table)
    return RC::SUCCESS;

  RC rc;
  switch (root_table->type) {
    case hsql::TableRefType::kTableName: {
      const char *table_name = root_table->getName();
      if (nullptr == table_name) {
        return RC::INVALID_ARGUMENT;
      }
      Table *tp = db_->find_table(table_name);
      if (!tp) {
        return RC::SCHEMA_TABLE_NOT_EXIST;
      }
      out_schema = std::make_shared<Schema>(tp, tp->table_meta().field_metas());
      return RC::SUCCESS;
    }
    case hsql::TableRefType::kTableJoin: {
      this->has_multi_table_ = true;
      SchemaRef left_schema, right_schema;
      rc = bind_from(root_table->join->left, left_schema);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      rc = bind_from(root_table->join->right, right_schema);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      out_schema = std::make_shared<Schema>(left_schema, right_schema);
      return RC::SUCCESS;
    }
    case hsql::TableRefType::kTableCrossProduct: {
      this->has_multi_table_ = true;
      assert(root_table->list->size() > 1);
      std::vector<SchemaRef> schemas;
      for (auto table_ref : *root_table->list) {
        SchemaRef tmp;
        rc = bind_from(table_ref, tmp);
        if (rc != RC::SUCCESS) {
          return rc;
        }
        schemas.push_back(std::move(tmp));
      }
      out_schema = std::make_shared<Schema>(schemas);
      return RC::SUCCESS;
    }
    default: {
      LOG_PANIC("Unsupported from type");
      // just for test
      return RC::UNIMPLENMENT;
    }
  }
}

RC Binder::bind_expression(hsql::Expr *expr, AbstractExpressionRef &out_expr)
{
  if (expr == nullptr) {
    return RC::SUCCESS; // nullptr won't be bound, caller should handle potential error.
  }

  switch (expr->type) {
    case hsql::kExprLiteralInt: {
      out_expr = std::make_shared<ConstantValueExpression>(Value(TypeId::INT, static_cast<int32_t>(expr->ival)));
      return RC::SUCCESS;
    }
    case hsql::kExprLiteralFloat: {
      out_expr = std::make_shared<ConstantValueExpression>(Value(TypeId::FLOAT, static_cast<float>(expr->fval)));
      return RC::SUCCESS;
    }
    case hsql::kExprLiteralString: {
      // handle DATE and CHAR here
      // TODO(vgalaxy): check
      void *dst = calloc(1, sizeof(int32_t[3]));
      RC rc = Date::parse_date(dst, expr->name);
      if (rc != RC::SUCCESS) {
        free(dst);
      } else {
        Value val{TypeId::DATE, static_cast<const int32_t *>(dst)};
        free(dst);
        out_expr = std::make_shared<ConstantValueExpression>(std::move(val));
        return RC::SUCCESS;
      }
      out_expr = std::make_shared<ConstantValueExpression>(Value(TypeId::CHAR, expr->name, strlen(expr->name)));
      return RC::SUCCESS;
    }
    case hsql::kExprLiteralNull: {
      out_expr = std::make_shared<ConstantValueExpression>(Value(TypeId::UNDEFINED));
      return RC::SUCCESS;
    }
    case hsql::kExprStar: {
      ColumnName col_name;
      if (expr->hasTable()) {
        col_name.set_table_name(expr->table);
      }
      out_expr = std::make_shared<ColumnValueExpression>(col_name);
      return RC::SUCCESS;
    }
    case hsql::kExprColumnRef: {
      out_expr = std::make_shared<ColumnValueExpression>(ColumnName(expr->table, expr->name));
      return RC::SUCCESS;
    }
    case hsql::kExprOperator: {
      AbstractExpressionRef lhs, rhs;
      RC rc = bind_expression(expr->expr, lhs);
      if (rc != RC::SUCCESS) {
        return rc;
      }

      // special case: Constructing IN-expression needs select clause which others don't.
      if (expr->opType == hsql::OperatorType::kOpIn) {
        if (expr->select != nullptr) {
          // in (subquery)
          out_expr = std::make_shared<InExpression>(expr->select, lhs);
          return RC::SUCCESS;
        } else {
          // in (value1, value2, ...)
          assert(expr->exprList != nullptr);
          std::vector<AbstractExpressionRef> value_list;
          for (const auto& value_expr : *expr->exprList) {
            AbstractExpressionRef value;
            rc = bind_expression(value_expr, value);
            HANDLE_EXCEPTION(rc, "Bind expression of IN operator failed.");

            value_list.push_back(value);
          }
          out_expr = std::make_shared<InValueExpression>(std::move(lhs), value_list);
          return RC::SUCCESS;

        }
      }

      if (expr->opType == hsql::OperatorType::kOpExists) {
        out_expr = std::make_shared<ExistsExpression>(expr->select);
        return RC::SUCCESS;
      }

      if (expr->opType == hsql::OperatorType::kOpLike) {
        out_expr = std::make_shared<LikeExpression>(std::move(lhs), expr->expr2->name);
        return RC::SUCCESS;
      }

      if (expr->opType == hsql::OperatorType::kOpNotLike) {
        out_expr = std::make_shared<LikeExpression>(std::move(lhs), expr->expr2->name, true);
        return RC::SUCCESS;
      }

      rc = bind_expression(expr->expr2, rhs);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      OperatorType op;
      rc = bind_operator(expr->opType, op);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      rc = AbstractExpression::expression_factory(lhs, rhs, op, out_expr);
      return rc;
    }
    case hsql::kExprFunctionRef: {
      std::vector<AbstractExpressionRef> args{};
      for (auto arg : *expr->exprList) {
        AbstractExpressionRef bound_expr{};
        RC rc = bind_expression(arg, bound_expr);
        if (rc != RC::SUCCESS) {
          return rc;
        }
        args.push_back(bound_expr);
      }
      AbstractFunctionRef fn;
      RC rc = FunctionCall::function_factory(expr->name, fn);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      out_expr = std::make_shared<FunctionCall>(expr->name, args, fn);
      return RC::SUCCESS;
    }
    case hsql::kExprSelect: {
      out_expr = std::make_shared<ScalarExpression>(expr->select);
      return RC::SUCCESS;
    }
    default: {
      LOG_ERROR("Unsupported expression type: %d", expr->type);
      return RC::UNIMPLENMENT;
    }
  }
}

RC Binder::bind_operator(hsql::OperatorType opt, OperatorType &out)
{
  const struct info {
    hsql::OperatorType opt;
    OperatorType ct;
  } infos[] = {
      {hsql::OperatorType::kOpEquals, OperatorType::Equal},
      {hsql::OperatorType::kOpGreater, OperatorType::GreaterThan},
      {hsql::OperatorType::kOpGreaterEq, OperatorType::GreaterThanOrEqual},
      {hsql::OperatorType::kOpNotEquals, OperatorType::NotEqual},
      {hsql::OperatorType::kOpLess, OperatorType::LessThan},
      {hsql::OperatorType::kOpLessEq, OperatorType::LessThanOrEqual},
      {hsql::OperatorType::kOpAnd, OperatorType::AND},
      {hsql::OperatorType::kOpOr, OperatorType::OR},
      {hsql::OperatorType::kOpNot, OperatorType::NOT},
      {hsql::OperatorType::kOpSlash, OperatorType::SLASH},
      {hsql::OperatorType::kOpAsterisk, OperatorType::MUL},
      {hsql::OperatorType::kOpPlus, OperatorType::PLUS},
      {hsql::OperatorType::kOpMinus, OperatorType::SUB},
      {hsql::OperatorType::kOpUnaryMinus, OperatorType::NEG},
      {hsql::OperatorType::kOpIsNull, OperatorType::IsNull},
      {hsql::OperatorType::kOpIn, OperatorType::IN}

  };
  for (auto info : infos) {
    if (info.opt == opt) {
      out = info.ct;
      return RC::SUCCESS;
    }
  }
  LOG_PANIC("Unsupported operator type: %d", opt);
  return RC::UNIMPLENMENT;
}

RC Binder::find_columns(const std::string& table_name, std::string column_name)
{
  size_t found_cnt = 0;
  std::vector<Column> found_columns;
  // start from current schema.
  found_columns = from_schema_->find_columns(table_name, column_name);
  found_cnt += found_columns.size();
  for (const auto& parent_schema : enclosing_) {
    found_columns = parent_schema->find_columns(table_name, column_name);
    found_cnt += found_columns.size();
  }

  if (found_cnt == 1) {
    // exists and unique
    return RC::SUCCESS;
  } else {

  }
  LOG_PANIC("can't find columns or it's ambiguous");
  return RC::SCHEMA_FIELD_NOT_EXIST;

}