// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
#ifndef TIME_H
#define TIME_H
#include <string>

class Time{ //Stort T viktigt
public:
  Time(): hour{0}, minute{0}, second{0} {}
  Time(int h, int m, int s);
  Time(std::string text);

  Time operator +(int const& rhs);
  Time operator -(int const& rhs);
  Time operator ++(int);  // t++
  Time& operator ++();    // ++t
  Time operator --(int);
  Time& operator --();
//  Time operator >();
//  Time operator <();


  int gethour() const;
  int getminute() const;
  int getsecond() const;
  bool is_am()const;

  std::string to_string(bool const twelveh = false) const;
private:
  int hour;
  int minute;
  int second;
};
#endif
