/*
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

int main(int argc, char* argv[])
{
    return Catch::Session{}.run(argc, argv);
}
*/

#include <string>
#include <iostream>
#include <sstream>

#include "component.h"

using namespace std;

int main()
{
  vector<Component*> net;

  Connection p, n;
  vector<Component*> net;
  
  net.push_back(new Battery("Bat", 24.0, p, n));
  net.push_back(new Resistor("R1",  6.0, p, n));

  simulate(net, 10000, 10, 0.1);
}
