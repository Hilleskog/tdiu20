// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
#ifndef TIME_H
#define TIME_H
#include <string>
#include <sstream>
#include <iostream>

/*
TODO:
Funktioner/operatorer som inte ska modifera objektet ska vara const
DONE
*/

class Time{ //Stort T viktigt
public:
  Time(): hour{0}, minute{0}, second{0} {}
  Time(int h, int m, int s);
  Time(std::string text);

  Time operator +(int const& rhs) const;
  Time operator -(int const& rhs) const;
  Time operator ++(int);  // t++
  Time& operator ++();    // ++t
  Time operator --(int);
  Time& operator --();

  bool operator >(Time const& rhs) const;
  bool operator <(Time const& rhs) const;
  bool operator ==(Time const& rhs) const;
  bool operator !=(Time const& rhs) const;
  bool operator <=(Time const& rhs) const;
  bool operator >=(Time const& rhs) const;

  int gethour() const;
  int getminute() const;
  int getsecond() const;
  bool is_am() const;
  std::string to_string(bool const twelveh = false) const;
  operator std::string();
private:
  int hour;
  int minute;
  int second;
};

  std::ostream& operator <<(std::ostream & lhs, Time const& rhs);
  std::istream& operator >>(std::istream & lhs, Time & rhs);

#endif
