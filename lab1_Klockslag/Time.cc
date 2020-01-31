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

  if (twelveh == true)
  {
    if (is_am() == false)
    { //PM
      tmp = tmp - 12;

      if (tmp < 10){
        strem << "0" << tmp << ":"; //Setw(2)
      } else {
        strem << tmp << ":";
      }

      if (minute < 10){
        strem << "0" << minute << ":";
      } else {
        strem << minute << ":";
      }

      if (second < 10){
        strem << fixed << setw(2) << "0" << second  << " pm";
      } else {
        strem << fixed << setw(2) << second << " pm";
      }


    }
    else
    {  //AM
      if (hour < 10){
        strem << "0" << hour << ":";
      } else {
        strem << hour << ":";
      }

      if (minute < 10){
        strem << "0" << minute << ":";
      } else {
        strem << minute << ":";
      }

      if (second < 10){
        strem << "0" << second << " am";
      } else {
        strem << second << " am";
      }
    }
  }

  else
  {
    if (hour < 10){
      strem << "0" << hour << ":";
    } else {
      strem << hour << ":";
    }

    if (minute < 10){
      strem << "0" << minute << ":";
    } else {
      strem << minute << ":";
    }

    if (second < 10){
      strem << "0" << second;
    } else {
      strem << second;
    }
  }

  strem >> result;
  return result;
}
