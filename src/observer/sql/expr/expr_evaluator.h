#pragma once

#include "ret_type.h"
#include "environment.h"

class Evaluator {
public:
  static RetValueRef evaluate(hsql::Expr *expr, Environment &env)
  {
    switch (expr->type) {
      case hsql::ExprType::kExprColumnRef: {
        return eval_col_value(expr, env);
      }
      case hsql::ExprType::kExprOperator: {
        return ope_dispatcher(expr, env);
      }
      default: {
        LOG_WARN("Unsupported expression type: %d\n", expr->type);
        break;
      }
    }
    return nullptr;
  }

private:
  static RetValueRef eval_col_value(hsql::Expr *expr, Environment &env)
  {
    TupleCell *ret_val = new TupleCell();
    RC rc = RC::SUCCESS;
    rc = env.get_column_value(expr->table, expr->name, *ret_val);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Get column value error.");
      return nullptr;
    }
    return std::make_shared<RetValue>(VoidRef(ret_val), RetType::rTupleCell);
  }

  static RetValueRef ope_dispatcher(hsql::Expr *expr, Environment &env)
  {
    switch (expr->opType) {
      case hsql::OperatorType::kOpEquals: {
      }
      default: {
        LOG_ERROR("Unsupported operator type: %d\n", expr->opType);
      }
    }

    return nullptr;
  }
};