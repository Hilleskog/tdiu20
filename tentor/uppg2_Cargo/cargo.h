#include <iostream>
#include <string>


class Cargo{
public:
  Cargo(std::string n, int v);

  std::string get_name() const;
  int get_value() const;

  Cargo operator +(Cargo const& rhs) const;

private:
  std::string name;
  int value;
};

std::ostream& operator <<(std::ostream & lhs, Cargo const& rhs);
