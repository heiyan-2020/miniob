#include "string_utils.h"

std::vector<std::string> split(const std::string& str, char delim) {
  std::string s;
  s.append(1, delim);
  std::regex reg(s);
  std::vector<std::string> elems(std::sregex_token_iterator(str.begin(), str.end(), reg, -1),
      std::sregex_token_iterator());
  return elems;
}

void trim(std::string &str) {
  size_t index = 0;
  if (!str.empty()) {
    while ((index = str.find(' ', index)) != std::string::npos) {
      str.erase(index, 1);
    }
  }
}
