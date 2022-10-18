#include "float_utils.h"

auto format_float(float val, int digits) -> std::string
{
  // 尽可能不打印小数点，若存在小数点，最多保留 digits 位
  char *foo = (char *) calloc(32, sizeof(char));
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