// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
#include "Time.h"
#include <stdexcept>
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
