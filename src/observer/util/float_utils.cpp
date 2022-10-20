#include <cassert>
#include "float_utils.h"

auto format_float(float val, int digits) -> std::string
{
  // 尽可能不打印小数点，若存在小数点，最多保留 digits 位
  char *foo = (char *)calloc(32, sizeof(char));
  auto bar = static_cast<int64_t>(val);
  size_t length = std::to_string(bar).size();
  if (bar == 0) {
    length--;
  }
  sprintf(foo, "%.*g", static_cast<int>(length + digits), val);
  std::string res{foo};
  free(foo);
  return {res};
}

auto floor_float(float val, int digits) -> float
{
  std::string tmp{std::to_string(val)};
  std::string res{};
  auto find_dot = tmp.find('.');
  assert(find_dot != std::string::npos);
  res += tmp.substr(0, find_dot);
  if (digits > 0) {
    res += tmp.substr(find_dot, digits + 1);
  }
  return (float)atof(res.c_str());
}