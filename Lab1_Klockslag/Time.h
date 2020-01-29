// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
#ifndef TIME_H
#define TIME_H

class Time{ //Stort T viktigt
public:
  Time(): hour{0}, minute{0}, second{0};
  Time(int h, int m, int s);
  Time
  int gethour() const;
  int getminute() const;
  int getsecond() const;
private:
  int hour;
  int minute;
  int second;
};
#endif
