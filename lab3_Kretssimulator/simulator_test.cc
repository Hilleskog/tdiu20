//KOMPILERA
//w++17 Simulator.cc test_main.o simulator_test.cc

#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "Simulator.h"

using namespace std;

// här lägger ni era testfall.
// Jobba enligt TDD;
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut

TEST_CASE ("TEST_Mall")
{
  SECTION ("SECTION_Mall")
  {
    /*
    KODEXEMPEL
    Connection p, n;vector<Component*> net;
    net.push_back(newBattery("Bat", 24.0, p, n));
    net.push_back(newResistor("R1",  6.0, p, n));
    net.push_back(newResistor("R2",  8.0, p, n));
    simulate(net, 10000, 10, 0.1);
    */
  }
}

// the following line will halt the compilation process. Move it
// one test case at the time and then start creating your own test
// cases
#if 0
#endif
