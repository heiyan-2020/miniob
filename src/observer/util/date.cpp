#include "date.h"
#include "common/log/log.h"

#include <cstring>
#include <string>

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
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
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
  int first{-1};
  for (size_t i = 0; i < strlen(src); ++i) {
    if (*(src + i) == '-') {
      first = i;
      break;
    }
  }
  if (first == -1) {
    return RC::DATE;
  }

  int second{-1};
  for (size_t i = first + 1; i < strlen(src); ++i) {
    if (*(src + i) == '-') {
      second = i;
      break;
    }
  }
  if (second == -1) {
    return RC::DATE;
  }

  std::string s{src};
  std::string year_str = s.substr(0, first);
  std::string month_str = s.substr(first + 1, second - first - 1);
  std::string day_str = s.substr(second + 1);
  LOG_INFO("year: %s, month: %s, day: %s", year_str.c_str(), month_str.c_str(), day_str.c_str());

  int *trans = reinterpret_cast<int *>(dst);
  trans[0] = std::stoi(year_str);
  trans[1] = std::stoi(month_str);
  trans[2] = std::stoi(day_str);

  if (!Date::validate_date(dst)) {
    return RC::DATE;
  }

  return RC::SUCCESS;
}

std::string Date::to_string()
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
