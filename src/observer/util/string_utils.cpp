#include "string_utils.h"

std::string trim(const std::string &str)
{
  if (str.empty()) {
    return str;
  }
  std::string res{str};
  res.erase(0, res.find_first_not_of(' '));
  res.erase(res.find_last_not_of(' ') + 1);
  return res;
}

std::vector<std::string> split(const std::string &str)
{
  std::vector<std::string> res{};
  size_t len = str.size();
  size_t prev_index{};
  size_t curr_index{};
  bool in_fn{};
  while (curr_index < len) {
    if (str[curr_index] == '(') {
      in_fn = true;
    }
    if (str[curr_index] == ')') {
      in_fn = false;
    }
    if (str[curr_index] == ',') {
      if (!in_fn) {
        res.push_back(str.substr(prev_index, curr_index - prev_index));
        prev_index = curr_index + 1;
      }
    }
    curr_index++;
  }
  res.push_back(str.substr(prev_index, curr_index - prev_index));
  return res;
}

bool ends_with(const std::string &str, const std::string &suffix)
{
  if (suffix.length() > str.length()) {
    return false;
  }

  return (str.rfind(suffix) == (str.length() - suffix.length()));
}