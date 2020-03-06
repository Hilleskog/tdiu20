//KOMPILERA
//w++17 Simulator.cc test_main.o simulator_test.cc
#include "Simulator.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
// ---------------- CONSTRUCTORS ---------------- //

Connection::Connection(){}

Component::Component(std::string n, Connection& a, Connection& b):
name{n}, c1{a}, c2{b}
{}

Battery::Battery(std::string name, double v, Connection& a, Connection& b):
Component(name, a, b), voltage(v)
{}

/*
Battery::Battery(std::string name, double Voltage, Connection &Connection1, Connection &Connection2):
Component(name, Connection1, Connection2), V{Voltage}{
*/

Resistor::Resistor(std::string name, double r, Connection &a, Connection &b):
Component(name, a, b), resistance(r)
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

void Connection::set_voltage(double & input)
{
  voltage = input;
}

// ---------------- BATTERY ---------------- //
/*
double Battery::get_voltage()
{
  return voltage;
}

double Battery::get_current()
{
  return 0.0;
}
*/
// ---------------- BATTERY ---------------- //
