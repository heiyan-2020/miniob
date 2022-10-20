#pragma once

#include <string>
#include <vector>
#include <regex>

std::vector<std::string> split(const std::string &str);
std::string trim(const std::string &str);
bool ends_with(const std::string &str, const std::string &suffix);