#pragma once
#include "sql/parser/hsql/sql/Expr.h"
#include "rc.h"
#include "sql/expr/tuple.h"

enum RetType { rTupleCell, rBool };

using VoidRef = std::shared_ptr<void>;

template <typename To, typename From>
inline std::shared_ptr<To> reinterpret_pointer_cast(std::shared_ptr<From> const &ptr) noexcept
{
  return std::shared_ptr<To>(ptr, reinterpret_cast<To *>(ptr.get()));
}

class RetValue {
public:
  RetValue() = default;
  RetValue(VoidRef data, RetType type) : data_(data), type_(type)
  {}
  RC get_as_tuple(TupleCell &ret)
  {
    if (type_ != RetType::rTupleCell) {
      return RC::WRONGTYPE;
    }
    ret = *reinterpret_pointer_cast<TupleCell>(data_);
    return RC::SUCCESS;
  }

  RC get_as_bool(bool &ret)
  {
    if (type_ != RetType::rBool) {
      return RC::WRONGTYPE;
    }
    ret = *reinterpret_pointer_cast<bool>(data_);
    return RC::SUCCESS;
  }

private:
  std::shared_ptr<void> data_;
  RetType type_;
};

using RetValueRef = std::shared_ptr<RetValue>;