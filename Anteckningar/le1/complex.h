#pragma once //ifndef

#include <sstream>

class complex
{
public:
  complex(int r, int i);

  int getreal() const; //const menar att vi "lovar" att vi inte ändra på skit
  int getimag() const;
  //default-värden (int i = 3)
  void to_string(std::ostream & os);
  void add (const int x);
  void add (const complex & other);

private:
  int real; //alla datamedlemmar alltid i private
  int imag;
};

complex sum (complex const & c1, complex const & c2);
