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
    throw std::logic_error("Incorrect number");
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
    throw std::logic_error{"Not ok"};
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
//Comment: Kan returnera själva satsen. Alltså tex return !(tmp >= 12);
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
/*
TODO:
4-3. Upprepa inte manipulatorer med effekt som gäller tills
vidare.Exempelvis setprecision(n) och fixed.

Man vill använda setfill/setw för att slippa många if-satser. Just ni har ni kvar många, ni bör ska ta bort de som inte behövs.
DONE
*/

string Time::to_string(bool const twelveh) const
{
  stringstream strem;
  string result;
  int tmp{hour};

  if (twelveh == true && is_am() == false)
  {
    tmp = tmp - 12;
    strem << setfill('0') << setw(2) << fixed  << tmp  << ":" ; //Setw(2)
  } else {
    strem << setfill('0') << setw(2) << fixed  << tmp  << ":" ; //Setw(2)
  }

  strem << setfill('0') << setw(2) << fixed << minute << ":";

  strem << setfill('0') << setw(2) << fixed << second;

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


Time Time::operator +(int const& rhs) const
{
  Time tmp{*this};
  for (int i{}; i<rhs; i++)
  {
    tmp.second++;
    if (tmp.second>59)
    {
      tmp.minute++;
      tmp.second = 0;
      if (tmp.minute>59){
        tmp.hour++;
        tmp.minute = 0;
      }
    }
  }
  return tmp;
}

Time Time::operator -(int const& rhs) const
{
  Time tmp{*this};

  for (int i{}; i<rhs; i++)
  {
    tmp.second--;
    if (tmp.second<0)
    {
      tmp.second = 59;
      tmp.minute--;
      if (tmp.minute<0)
      {
        tmp.minute = 59;
        tmp.hour--;
      }
    }
  }
  return tmp;
}
//TODO För mycket kodupprepning. Ni ska använda antingen +operatorn
// och/eller skapa post/pre och använda den när ni skapar den andra
//Samma för --
//DONE

Time Time::operator ++(int) // t++
{
  Time tmp {*this};
  *this = *this + 1;
  return tmp;
}

Time& Time::operator ++() // ++t
{
  *this = *this + 1;
  return *this;
}

Time Time::operator --(int) //t--
{
  Time tmp {*this};
  *this = *this - 1;
  return tmp;
}

Time& Time::operator --() //pre-increment
{
  *this = *this - 1;
  return *this;
}

//TODO Ni ska göra max 2 av jämförelseoperatorerna från scratch och
//sen använda dem för att skapa resten.
//DONE

bool Time::operator >(Time const& rhs) const
{
  if( hour > rhs.gethour())
  {
    return true;
  } else if (hour == rhs.gethour() && minute > rhs.getminute())
  {
    return true;
  }
  else if (hour == rhs.gethour() && minute == rhs.getminute() && second > rhs.getsecond())
  {
    return true;
  }

  return false;
}


bool Time::operator <(Time const& rhs) const
{
  if( hour < rhs.gethour())
  {
    return true;
  } else if (hour == rhs.gethour() && minute < rhs.getminute())
  {
    return true;
  }
  else if (hour == rhs.gethour() && minute == rhs.getminute() && second < rhs.getsecond()){
    return true;
  }
  return false;
}


bool Time::operator ==(Time const& rhs) const
{
  if ((*this > rhs) == false && (*this < rhs) == false)
  {
    return true;
  } else {
    return false;
  }
}

bool Time::operator !=(Time const& rhs)const
{
  if ((*this == rhs) == true)
  {
    return false;
  } else {
    return true;
  }
}

bool Time::operator <=(Time const& rhs)const
{
  if ((*this == rhs) == true || (*this < rhs) == true)
  {
    return true;
  } else {
    return false;
  }
}

bool Time::operator >=(Time const& rhs) const
{
  if ((*this == rhs) == true || (*this > rhs) == true)
  {
    return true;
  } else {
    return false;
  }
}

std::ostream& operator <<(std::ostream & lhs, Time const& rhs)
{
  lhs << rhs.to_string();
  return lhs;
}

std::istream& operator >>(std::istream & lhs, Time & rhs)
{
  char trash;
  int tmp_h, tmp_m, tmp_s;
  lhs >> tmp_h >> trash >> tmp_m >> trash >> tmp_s;

  try
  {
    rhs = Time{tmp_h, tmp_m, tmp_s};
  }
  catch(exception & e)
  {
    lhs.setstate(std::ios_base::failbit);
  }
  //rhs = Time{tmp_h, tmp_m, tmp_s};
  return lhs;
}

Time::operator string()
{
  return to_string();
}
