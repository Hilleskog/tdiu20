#include <iostream>
#include <string>
#include <array>

#include "date.h"

using namespace std;

Date::Date (int y, int m, int d):
year{y}, month{m}, day{d}
{
  if ( month < 1 || month > 12 )
  {
    throw std::domain_error{"Month " + std::to_string(month) + " doesn't exist!"};
  }
  if (  day < 1 || day > days_in_month( year, month ) )
  {
    throw std::domain_error{"Day " + std::to_string(day) + " invalid"};
  }
  //return {year, month, day};
}

bool Date::is_leap_year(int year){
  if ( year % 400 == 0 )
    return true;
  if ( year % 100 == 0 )
    return false;
  return year % 4 == 0;
}

int Date::days_in_month(int year, int month){
  static constexpr const std::array<int, 13> days
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (month < 1 || month > 12)
    return 0;

  if ( month == 2 && is_leap_year( year ) )
    return 29;

  return days.at(month);
}

void print(Date const& d){
  cout << d.get_year() << "-" << d.get_month() << "-" << d.get_day() << endl;
}


int Date::get_year() const {
  return year;
}

int Date::get_month() const {
  return month;
}

int Date::get_day() const {
  return day;
}
