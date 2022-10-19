#include "tuple_comparator.h"
#include <algorithm>
#include <utility>

RC TupleComparator::sort_tuples(std::vector<TupleRef>& sorted_res_)
{
  RC rc = RC::SUCCESS;
  std::sort(sorted_res_.begin(), sorted_res_.end(),
      [&rc, this](TupleRef lhs, TupleRef rhs) {
        int comp_res = comp(std::move(lhs), std::move(rhs));
        if (comp_res == -2) {
          rc = RC::EVALUATE;
        }
        return comp_res != 1;
      });
  return rc;
}

int TupleComparator::comp(TupleRef a, TupleRef b)
{
  RC rc;
  // create env
  EnvRef env_A = std::make_shared<Environment>();
  env_A->clear();
  env_A->add_tuple(schema, std::move(a));
  EnvRef env_B = std::make_shared<Environment>();
  env_B->clear();
  env_B->add_tuple(schema, std::move(b));

  int compare_res = 0;
  for (auto* order_description: *order_by_spec) {
    // evaluate
    ColumnName col(order_description->expr->table, order_description->expr->name);
    ColumnValueExpression expr(col);

    Value value_A, value_B;
    rc = expr.evaluate(env_A, value_A);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("order by expression evaluate failed");
      return -2;
    }
    rc = expr.evaluate(env_B, value_B);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("order by expression evaluate failed");
      return -2;
    }

    // is_null_, true: null; false: not null
    if (value_A.is_null()) {
      if (!value_B.is_null()) {
        compare_res = -1;
      }
      else {
        compare_res = 0;
      }
    }

    else if (value_B.is_null()) {
      compare_res = 1;
    }

    else {
      CmpRes cmp_res = value_A.compare(value_B);
      switch (cmp_res) {
        case CmpRes::EQ: {
          compare_res = 0;
          break;
        }
        case CmpRes::GT: {
          compare_res = 1;
          break;
        }
        case CmpRes::LT: {
          compare_res = -1;
          break;
        }
        default:
          break;
      }
    }

    if (compare_res != 0) {
      if (!is_ascending(order_description))
        compare_res = -1 * compare_res;
      break;
    }
  }

  return compare_res;
}

bool TupleComparator::is_ascending(hsql::OrderDescription* order_desc)
{
  if (order_desc->type == hsql::kOrderAsc) {
    return true;
  }
  return false;
}
