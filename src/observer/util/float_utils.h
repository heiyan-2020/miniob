#pragma once

#include <string>

auto format_float(float val, int digits = 2) -> std::string;
auto floor_float(float val, int digits) -> float;
auto round_float(std::string val, int digits) -> std::string;