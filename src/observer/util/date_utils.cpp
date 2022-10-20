#include "date_utils.h"
#include "common/log/log.h"

#include <string>
#include <regex>

Date::Date(void *data)
{
  auto *trans = reinterpret_cast<int32_t *>(data);
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
    return RC::DATEFORMAT;
  }
  if (m.size() != 4) {
    return RC::INTERNAL;
  }

  auto *trans = reinterpret_cast<int32_t *>(dst);
  trans[0] = std::stoi(m.str(1));
  trans[1] = std::stoi(m.str(2));
  trans[2] = std::stoi(m.str(3));

  if (!Date::validate_date(dst)) {
    return RC::DATEFORMAT;
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

static std::string month_english[] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
};

static std::string month_number[] = {
    "01",
    "02",
    "03",
    "04",
    "05",
    "06",
    "07",
    "08",
    "09",
    "10",
    "11",
    "12",
};

static std::string day_english[] = {
    "1st",
    "2nd",
    "3rd",
    "4th",
    "5th",
    "6th",
    "7th",
    "8th",
    "9th",
    "10th",
    "11th",
    "12th",
    "13th",
    "14th",
    "15th",
    "16th",
    "17th",
    "18th",
    "19th",
    "20th",
    "21st",  // note
    "22nd",  // note
    "23rd",  // note
    "24th",
    "25th",
    "26th",
    "27th",
    "28th",
    "29th",
    "30th",
    "31st",
};

static std::string day_number[] = {
    "01",
    "02",
    "03",
    "04",
    "05",
    "06",
    "07",
    "08",
    "09",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
    "16",
    "17",
    "18",
    "19",
    "20",
    "21",
    "22",
    "23",
    "24",
    "25",
    "26",
    "27",
    "28",
    "29",
    "30",
    "31",
};

auto format_date(const Date &date, const char *format) -> std::string
{
  std::string res{};
  size_t length = strlen(format);
  size_t curr_index{};
  while (curr_index < length) {
    if (format[curr_index] != '%' && curr_index + 1 < length) {
      res += format[curr_index];
      curr_index++;
    } else {
      switch (format[curr_index + 1]) {
        case 'Y': {
          res += std::to_string(date.year);
          curr_index += 2;
        } break;
        case 'y': {
          res += std::to_string(date.year).substr(2);
          curr_index += 2;
        } break;
        case 'M': {
          res += month_english[date.month - 1];
          curr_index += 2;
        } break;
        case 'm': {
          res += month_number[date.month - 1];
          curr_index += 2;
        } break;
        case 'D': {
          res += day_english[date.day - 1];
          curr_index += 2;
        } break;
        case 'd': {
          res += day_number[date.day - 1];
          curr_index += 2;
        } break;

        default: {
          // fall back normal character
          // ignore '%'
          // res += format[curr_index];
          curr_index += 1;
        } break;
      }
    }
  }
  return res;
}