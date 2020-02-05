// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
#include "Time.h"
#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
//Hello
using namespace std;

Time::Time(int h, int m, int s):
hour{h}, minute{m}, second{s}
{
  if(h>23 || h<00 || m< 00|| s<00|| m> 59 || s>59 )
  {
    throw std::logic_error{"git fukd"};
  }
}

Time::Time(std::string text):
hour{0}, minute{0}, second{0}
{
  stringstream strem{text};
  char garbage;
  strem >> hour >> garbage >> minute >> garbage >> second;

  if(hour>23 || hour<00 || minute< 00 || minute> 59 || second<00 || second>59 )
  {
    throw std::logic_error{"git fukd"};
  }
}

int Time::gethour()const
{
  return hour;
}

int Time::getminute()const
{
  return minute;
}

int Time::getsecond()const
{
  return second;
}

bool Time::is_am()const
{
  int tmp{hour};
  if (tmp >= 12)
  { //PM
    return false;
  }
  else
  {  //AM
    return true;
  }
}

string Time::to_string(bool const twelveh) const
{
  stringstream strem;
  string result;
  int tmp{hour};

  if (twelveh == true && is_am() == false)
  {
    tmp = tmp - 12;

    if (tmp < 10){
      strem << setfill('0') << setw(2) << fixed  << tmp  << ":" ; //Setw(2)
    }
  } else {
    if (hour < 10){
      strem << setfill('0') << setw(2) << fixed  << tmp  << ":" ; //Setw(2)
    } else {
      strem << hour << ":";
    }
  }

  if (minute < 10){
    strem << setfill('0') << setw(2) << fixed << minute << ":";
  } else {
    strem << minute << ":";
  }

  if (second < 10){
    strem << setfill('0') << setw(2) << fixed << second;
  } else {
    strem << setfill('0') << setw(2) << fixed << second;
  }

  if (twelveh == true)
  {
    if (is_am() == true)
    {
      strem << setfill(' ') << setw(3)<< right << fixed << "am";
    } else {
      strem << setfill(' ') << setw(3)<< right << fixed << "pm";
    }
  }
  return strem.str();
}

Time Time::operator+(int const& rhs)
{
  for (int i{}; i<rhs; i++)
  {
    second++;
    if (second>59)
    {
      minute++;
      second = 0;
      if (minute>59){
        hour++;
        minute = 0;
      }
    }
  }
  Time tmp_t{hour,minute,second};
  return tmp_t;
}

Time Time::operator -(int const& rhs)
{
  for (int i{}; i<rhs; i++)
  {
    second--;
    if (second<0)
    {
      second = 59;
      minute--;
      if (minute<0)
      {
        minute = 59;
        hour--;
      }
    }
  }
  Time tmp_t{hour,minute,second};
  return tmp_t;
}

Time Time::operator ++(int) // t++
{
  Time tmp {*this};
  second++;
  if (second>59)
  {
    minute++;
    second= 0;
    if (minute>59){
      hour++;
      minute = 0;
    }
  }
  return tmp;
}

Time& Time::operator ++() // ++t
{
  second++;
  if (second>59)
  {
    minute++;
    second= 0;
    if (minute>59){
      hour++;
      minute = 0;
    }
  }
  return *this;
}

Time Time::operator --(int)
{
  Time tmp {*this};
  second--;
  {
    second--;
    if (second<0)
    {
      minute--;
      second = 59;
      if (minute<0)
      {
        minute = 59;
        hour--;
      }
    }
  }
  return tmp;
}

Time& Time::operator --() //pre-increment
{
  --second;
  {
    second--;
    if (second<0)
    {
      minute--;
      second = 59;
      if (minute<0)
      {
        minute = 59;
        hour--;
      }
    }
  }
  return *this;
}
/*
int i{3}
i++; //i = 3
i    //i = 4
++i; //i = 5
Time & operator ++()
Time operator ++(int)

*/
