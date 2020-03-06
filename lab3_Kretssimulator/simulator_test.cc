//KOMPILERA
//w++17 Simulator.cc test_main.o simulator_test.cc

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "catch.hpp"
#include "Simulator.h"

using namespace std;

/*
KODEXEMPEL
Connection p, n;
vector<Component*> net;
net.push_back(new Battery("Bat", 24.0, p, n));
net.push_back(new Resistor("R1",  6.0, p, n));
net.push_back(new Resistor("R2",  8.0, p, n));
simulate(net, 10000, 10, 0.1);
*/
/*
TEST_CASE ("TEST_Mall")
{
  SECTION ("SECTION_Mall")
  {
  }
}
*/
// the following line will halt the compilation process. Move it
// one test case at the time and then start creating your own test
// cases

TEST_CASE ("Component konstruktor")
{
  SECTION ("Konstruktor")
  {
    Connection p, n;
    vector<Component*> net;

    net.push_back(new Battery{"Bat", 24, p, n});

    //CHECK(net.at(0).get_voltage() == 24);
  }
}

#if 0
#endif
