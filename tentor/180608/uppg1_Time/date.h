#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>

class Date{
public:
  Date(int y, int m, int d);

  bool is_leap_year(int year);
  int days_in_month(int year, int month);
  


  int get_year() const;
  int get_month() const;
  int get_day() const;

private:
  int year;
  int month;
  int day;
};

void print(Date const& d);

#endif
