#include "string_utils.h"

std::vector<std::string> split(const std::string& str) {
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

std::string trim(const std::string &str)
{
  std::string res{};
  bool in_str{};
  size_t len = str.size();
  size_t curr_index{};
  while (curr_index < len) {
    if (str[curr_index] == '\'') {
      if (!in_str) {
        in_str = true;
      } else {
        in_str = false;
      }
    }
    if (str[curr_index] == ' ') {
      if (in_str) {
        res += str[curr_index];
      }
    } else {
      res += str[curr_index];
    }
    curr_index++;
  }
  return res;
}
