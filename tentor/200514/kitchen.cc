#include "kitchen.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//////////////////////////////////////////////
Tool::Tool (string t, int l):
type{t}, length{l} {}

string Tool::get_type() const{
  return type;
}

int Tool::get_length() const{
  return length;
}

void Tool::inc_length(int a){
  length = get_length() + a;
}

ostream& operator <<(std::ostream & lhs, Tool const& rhs){
  lhs << rhs.get_type() << " " << rhs.get_length() << endl;
  return lhs;
}

//////////////////////////////////////////////

Toolbox::Toolbox (string n):
name{n} {}

void Toolbox::add_tool(Tool t){
  tools.push_back(t);
}

int Toolbox::get_size() const {
  int tmp = tools.size();
  return tmp;
}

string Toolbox::get_name() const{
  return name;
}

vector<Tool> Toolbox::get_tools() const{
  return tools;
}

void Toolbox::print() const{
  cout << "Toolbox " << get_name() << " innehåller följande: " << endl;

  vector <Tool> vtmp = get_tools();
  int tmp_size = vtmp.size();

  for (int i = 0; i < tmp_size; i++) {
    cout << vtmp[i].get_type() << " " << vtmp[i].get_length() << endl;
  }
  cout << endl;
}

//////////////////////////////////////////////
