#pragma once

#include <cmath>
#include <string>

#include "type/value.h"
#include "type/float_type.h"

class TypeConverter {
public:
  static Value get_from_int(TypeId dst_type, int raw)
  {
    switch (dst_type) {
      case INT:
        return {INT, raw};
      case FLOAT:
        return {FLOAT, (float) raw};
      case CHAR: {
        std::string converted = std::to_string(raw);
        return {CHAR, converted.c_str(), converted.size()};
      }
      default:
        assert(false);
    }
    return Value{};
  }

  static Value get_from_float(TypeId dst_type, float raw)
  {
    switch (dst_type) {
      case INT:
        // 四舍五入, 而非直接抹去小数位
        return {INT, (int) std::round(raw)};
      case FLOAT:
        return {FLOAT, raw};
      case CHAR: {
        Value tmp = {FLOAT, raw};
        std::string converted = tmp.to_string();
        return {CHAR, converted.c_str(), converted.size()};
      }
      default:
        assert(false);
    }
    return Value{};
  }

  static Value get_from_char(TypeId dst_type, const char *raw, size_t size)
  {
    switch (dst_type) {
      case INT:
        return {INT, atoi(raw)};
      case FLOAT:
        return {FLOAT, (float) atof(raw)};
      case CHAR: {
        return {CHAR, raw, size};
      }
      default:
        assert(false);
    }
    return Value{};
  }
};