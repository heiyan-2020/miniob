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

auto round_float(std::string val, int digits) -> std::string
{
  std::string res{};
  auto find_dot = val.find('.');
  assert(find_dot != std::string::npos);
  res += val.substr(0, find_dot);
  if (digits > 0) {
    res += val.substr(find_dot, digits);
    size_t last = val.at(find_dot + digits) - '0';
    size_t after_last = val.at(find_dot + digits + 1) - '0';
    if (after_last >= 5) {
      res += std::to_string(last + 1);
    } else {
      res += std::to_string(last);
    }
  }
  return res;
}
