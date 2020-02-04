#include "complex.h"
#include <iostream>

using namespace std;

complex::complex(int r, int i): //I complex finns complex
real{r}, imag{i} {}

int complex::getreal()
{
return real;
}

int complex::getimag()
{
  return imag;
}

void complex::to_string(ostream & os)
{
  if (real != 0 || imag == 0)
    os << real; //Sålänge vi har en rad behövs inga {}
  if (real != 0 && imag >0)
    os << "+";
  if (imag != 0)
    os << imag <<'i';
}

void complex::add(const int x)
{
  real+=x;
}

void complex::add(const complex & other)
{
  real=other.real;
  imag=other.imag;
}

complex sum (complex const & c1, complex const & c2)
{
  complex result {c1};
  result.add(c2);
  return result;
}
