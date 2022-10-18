#pragma once
#include "abstract_expression.h"
#include "unary_expression.h"
#include <unordered_map>
#include <regex>

class LikeExpression : public UnaryExpression {
public:
  LikeExpression(AbstractExpressionRef &&left, const std::string& regex, bool reverse=false)
      : UnaryExpression(left), reverse_(reverse)
  {
    std::string pattern;
    for (const char &ch : regex) {
      if (ch == '%') {
        pattern += ".*";
      } else if (ch == '_') {
        pattern += '.';
      } else {
        pattern += ch;
      }
    }
    pattern_ = std::regex(pattern);
  }

  RC evaluate(EnvRef env, Value &out_value) override
  {
    Value lhs;
    RC rc = get_child_at(0)->evaluate(env, lhs);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Left hand expression evaluate failed");
      return rc;
    }
    std::string val(lhs.get_as<const char*>());
    if (std::regex_match(val, pattern_)) {
      out_value = {BOOL, !reverse_};
    } else {
      out_value = {BOOL, reverse_};
    }
    return rc;
  }

  auto convert_to_column(SchemaRef schema, Column &out_col) -> RC override
  {
    return RC::UNIMPLENMENT;
  }

  std::string to_string() const override
  {
    return {};
  }
private:
  std::regex pattern_;
  bool reverse_;
};