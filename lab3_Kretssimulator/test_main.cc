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

#include "Simulator.h"

using namespace std;

int main()
{
  /*
  Connection p, n;
  vector<Component*> net;

  net.push_back(new Battery("Bat", 24.0, p, n));
  net.push_back(new Resistor("Res", 6.0, p, n));
  net.push_back(new Capacitor("Cap", 0.8, p, n));

  simulate(net, 10000, 10, 0.1);
*/
  vector<Component*> net;
  Connection a, b, c, d;
  net.push_back(new Battery("Bat", 24.0, a, d));
  net.push_back(new Resistor("R1", 6.0, a, b));
  net.push_back(new Resistor("R2", 4.0, b, c));
  net.push_back(new Resistor("R3", 8.0, c, d));
  net.push_back(new Resistor("R4", 12.0, b, d));
  cout << "KRETS 1" << endl;
  simulate(net, 200000, 10, 0.01);

  vector<Component*> krets2;
  Connection p2, l2, r2, n2;
  krets2.push_back(new Battery("Bat", 24.0, p2, n2));
  krets2.push_back(new Resistor("R1", 150.0, p2, l2));
  krets2.push_back(new Resistor("R2", 50.0, p2, r2));
  krets2.push_back(new Resistor("R3", 100.0, l2, r2));
  krets2.push_back(new Resistor("R4", 300.0, l2, n2));
  krets2.push_back(new Resistor("R5", 250.0, r2, n2));
  cout << "KRETS 2" << endl;
  simulate(krets2, 200000, 10, 0.01);

  vector<Component*> krets3;
  Connection p, l, r, n;
  krets3.push_back(new Battery("Bat", 24.0, p, n));
  krets3.push_back(new Resistor("R1", 150.0, p, l));
  krets3.push_back(new Resistor("R2", 50.0, p, r));
  krets3.push_back(new Capacitor("C3", 1.0, l, r));
  krets3.push_back(new Resistor("R4", 300.0, l, n));
  krets3.push_back(new Capacitor("C5", 0.75, r, n));
  cout << "KRETS 3" << endl;
  simulate(krets3, 200000, 10, 0.01);

}
