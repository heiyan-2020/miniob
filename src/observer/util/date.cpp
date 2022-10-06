#include "date.h"
#include "common/log/log.h"

#include <cstring>
#include <string>
#include <regex>

Date::Date(void *data)
{
  int *trans = reinterpret_cast<int *>(data);
  this->year = trans[0];
  this->month = trans[1];
  this->day = trans[2];
}

bool Date::validate() const
{
  if (month > 12 || month < 1) {
    return false;
  } else {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
      if (month == 2) {
        if (day > 29 || day < 1)
          return false;
        else
          return true;
      }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
      if (day < 1 || day > 30)
        return false;
      else
        return true;
    } else if (month != 2) {
      if (day < 1 || day > 31)
        return false;
      else
        return true;
    } else {
      if (day < 1 || day > 28)
        return false;
      else
        return true;
    }
  }
}

bool Date::operator==(const Date &other) const
{
  return this->year == other.year && this->month == other.month && this->day == other.day;
}

bool Date::operator!=(const Date &other) const
{
  return !Date::operator==(other);
}

bool Date::operator<(const Date &other) const
{
  if (this->year < other.year) {
    return true;
  } else if (this->year == other.year) {
    if (this->month < other.month) {
      return true;
    } else if (this->month == other.month) {
      if (this->day < other.day) {
        return true;
      } else if (this->day == other.day) {
        return false;
      } else {
        return false;
      }
    } else {
      return false;
    }
  } else {
    return false;
  }
}

bool Date::operator<=(const Date &other) const
{
  return !Date::operator>(other);
}

bool Date::operator>(const Date &other) const
{
  if (this->year < other.year) {
    return false;
  } else if (this->year == other.year) {
    if (this->month < other.month) {
      return false;
    } else if (this->month == other.month) {
      if (this->day < other.day) {
        return false;
      } else if (this->day == other.day) {
        return false;
      } else {
        return true;
      }
    } else {
      return true;
    }
  } else {
    return true;
  }
}

bool Date::operator>=(const Date &other) const
{
  return !Date::operator<(other);
}

bool Date::validate_date(void *data)
{
  Date date{data};
  return date.validate();
}

RC Date::parse_date(void *dst, const char *src)
{
  std::cmatch m;
  std::regex reg(R"(^(\d+)-(\d+)-(\d+)$)");

  auto ret = std::regex_match(src, m, reg);
  if (!ret) {
    return RC::DATE;
  }
  if (m.size() != 4) {
    return RC::INTERNAL;
  }

  int *trans = reinterpret_cast<int *>(dst);
  trans[0] = std::stoi(m.str(1));
  trans[1] = std::stoi(m.str(2));
  trans[2] = std::stoi(m.str(3));

  if (!Date::validate_date(dst)) {
    return RC::DATE;
  }

  return RC::SUCCESS;
}

std::string Date::to_string() const
{
  std::string year_str = std::to_string(this->year);
  std::string month_str = std::to_string(this->month);
  if (month < 10) {
    month_str = "0" + month_str;
  }
  std::string day_str = std::to_string(this->day);
  if (day < 10) {
    day_str = "0" + day_str;
  }
  return year_str + "-" + month_str + "-" + day_str;
}
