













#include "spaceship.h"
#include <string>
#include <vector>
#include <iostream>


using namespace std;

Ship::Ship (string n, int l):
name{n}, length{l} {};

Crew::Crew (string n, string r):
name{n}, rank{r} {};

void Ship::add_crew_member(Crew c){
  crew.push_back(c);
}

void Ship::print (ostream& os) const{
  os << "name: " << get_name() << endl;
  os << "length: " << get_length() << endl;
  os << "crew: " << endl;

  vector <Crew> c = get_crew();

  for (int i{0}; i < c.size(); i++){
    os << c[i].get_name() << " - " << c[i].get_rank() << endl;
  }

}

string Ship::get_name() const{
  return name;
}

int Ship::get_length() const{
  return length;
}

vector <Crew> Ship::get_crew() const{
  return crew;
}

string Crew::get_name() const{
  return name;
}
string Crew::get_rank() const{
  return rank;
}
