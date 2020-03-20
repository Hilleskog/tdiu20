













#include <vector>
#include <string>
#include <iostream>


class Crew{
public:
  Crew(std::string n, std::string r);

  std::string get_name() const;
  std::string get_rank() const;

private:
  std::string name;
  std::string rank;
};

class Ship{
public:
  Ship(std::string n, int l);

  void add_crew_member(Crew c);
  void print(std::ostream& os) const;

  std::string get_name() const;
  int get_length() const;
  std::vector<Crew> get_crew() const;

private:
  std::string name;
  int length;
  std::vector <Crew> crew;
};
