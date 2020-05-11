#include "cargo.h"

#include <iostream>
#include <string>

using namespace std;

Cargo::Cargo (string n, int v):
name{n}, value{v} {}

string Cargo::get_name() const{
  return name;
}

int Cargo::get_value() const{
  return value;
}

Cargo Cargo::operator +(Cargo const& rhs) const{
  Cargo tmp{*this};

  Cargo c{tmp.get_name()+rhs.get_name(), tmp.get_value()+rhs.get_value()};
  return c;
}

std::ostream& operator <<(std::ostream & lhs, Cargo const& rhs){
  lhs << rhs.get_name() << " " << rhs.get_value();
  return lhs;
}
