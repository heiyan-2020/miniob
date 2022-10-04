#pragma once

#include <string>
#include "rc.h"

class Date {
public:
  explicit Date(void *data);
  bool validate() const;
  static RC parse_date(void *dst, const char *src);
  std::string to_string() const;

private:
  static bool validate_date(void *data);

public:
  // TODO: three-way comparison
  bool operator<(const Date &other) const;
  bool operator<=(const Date &other) const;
  bool operator>(const Date &other) const;
  bool operator>=(const Date &other) const;
  bool operator==(const Date &other) const;
  bool operator!=(const Date &other) const;

private:
  int year;
  int month;
  int day;
};