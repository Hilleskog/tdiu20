//KOMPILERA
//w++17 Simulator.cc test_main.o simulator_test.cc
#include "Simulator.H"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
// ---------------- CONSTRUCTORS ---------------- //
Component::Component(std::string n, Connection& a, Connection& b):
name{n}, c1{a}, c2{b}
{}

Battery::Battery(std::string name, double v, Connection& a, Connection& b):
Component(name, c1, c2), voltage(v)
{}


// ---------------- COMPONENT ---------------- //

string Component::get_name()
{
  return name;
}

double Component::get_voltage()
{
  double voltage{};

  if (c1.get_voltage() >= c2.get_voltage())
  {
    voltage = c1.get_voltage() - c2.get_voltage();
  } else {
    voltage = c2.get_voltage() - c1.get_voltage();
  }

  return voltage;
}

// ---------------- CONNECTION ---------------- //

double Connection::get_voltage()
{
  return voltage;
}

// ---------------- BATTERY ---------------- //

double Battery::Battery get_voltage()
{
  return voltage;
}

double Battery::Battery get_current()
{
  return 0.0;
}

// ---------------- BATTERY ---------------- //
