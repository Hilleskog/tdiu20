#ifndef KITCHEN_H
#define KITCHEN_H

#include <string>
#include <iostream>
#include <vector>

//////////////////////////////////////////////
class Tool{
public:
  Tool(std::string t, int l);

  std::string get_type() const;
  int get_length() const;

  void inc_length(int a);

private:
  std::string type;
  int length;
};

  std::ostream& operator <<(std::ostream & lhs, Tool const& rhs);

//////////////////////////////////////////////

class Toolbox{
public:
  Toolbox(std::string n);

  void add_tool(Tool t);

  int get_size() const;
  std::string get_name() const;
  std::vector<Tool> get_tools() const;
  void print() const;

private:
  std::string name;
  std::vector <Tool> tools;

};

//////////////////////////////////////////////


#endif
