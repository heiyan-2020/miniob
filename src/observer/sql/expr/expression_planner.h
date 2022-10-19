#pragma once

#include "subquery_expression.h"
#include "sql/plan_node/plan_node.h"
#include "sql/binder/planner.h"
#include "expression_processor.h"
#include "util/macros.h"

class ExpressionPlanner : public ExpressionProcessor {
  friend class AbstractExpression;
public:
  ExpressionPlanner(Planner planner) : planner_(planner)
  {
    env_ = std::make_shared<Environment>();
  }

  RC enter(AbstractExpressionRef node) override
  {
    if (std::dynamic_pointer_cast<SubqueryExpression>(node)) {
      std::shared_ptr<SubqueryExpression> expr = std::dynamic_pointer_cast<SubqueryExpression>(node);
      hsql::SelectStatement *sel_clause = expr->subquery_;
      planner_.binder_.clear();
      RC rc = planner_.make_plan_sel(sel_clause, expr->subquery_plan_);
      HANDLE_EXCEPTION(rc, "plan subquery failed");
      expr->subquery_plan_->add_parent_env(env_);
      subquery_plans_.push_back(expr->subquery_plan_);
    }
  }

  AbstractExpressionRef leave(AbstractExpressionRef node) override
  {
    return node;
  }

  bool has_subquery() const
  {
    return !subquery_plans_.empty();
  }

  RC prepare_all()
  {
    RC rc;
    for (const auto &plan : subquery_plans_) {
      rc = plan->prepare();
      if (rc != RC::SUCCESS) {
        return rc;
      }
    }
    return RC::SUCCESS;
  }

  EnvRef get_env() const
  {
    return env_;
  }

private:
  std::vector<PlanNodeRef> subquery_plans_;
  Planner planner_;
  EnvRef env_;
};