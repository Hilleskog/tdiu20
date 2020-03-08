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
name{n}, p{a}, n{b}
{}

Battery::Battery(std::string name, double v, Connection& a, Connection& b):
Component(name, a, b), voltage(v)
{}

Resistor::Resistor(std::string name, double r, Connection &a, Connection &b):
Component(name, a, b), resistance(r)
{}
/*
Capacitor::Capacitor(std::string name, double cap, double charge, Connection &a, Connection &b):
component(name, a, b), capacitance(c)
{}

Battery::Battery(std::string name, double Voltage, Connection &Connection1, Connection &Connection2):
Component(name, Connection1, Connection2), V{Voltage}{
*/

// ---------------- CONNECTION ---------------- //
double Connection::get_voltage()
{
  return voltage;
}

void Connection::set_voltage(double & input)
{
  voltage = input;
}

// ---------------- COMPONENT ---------------- //
string Component::get_name()
{
  return name;
}

double Component::get_voltage()
{
  double voltage{};

  if (p.get_voltage() >= n.get_voltage())
  {
    voltage = p.get_voltage() - n.get_voltage();
  } else {
    voltage = n.get_voltage() - p.get_voltage();
  }

  return voltage;
}

double Component::get_current()
{
  return 0.0; // Ja men precis
}

// ---------------- BATTERY ---------------- //
double Battery::get_voltage()
{
  return voltage;
}

double Battery::get_current()
{
  return 0.0;
}

void Battery::simulate(double time)
{
  p.voltage = get_voltage();
  n.voltage = 0.0;
}

// ---------------- RESISTOR ---------------- //

double Resistor::get_current()
{
  double tmp{};

  tmp = get_voltage()/resistance;
  return tmp;
}

double Resistor::get_resistance()
  {
    return resistance;
  }

void Resistor::simulate(double time_rate)
  {
    p.voltage = get_voltage();
    n.voltage = 0.0;
  }

// ---------------- CAPACITOR ---------------- //


// --------- SIMULATE AND STIMULATE --------- //

void simulate(std::vector<Component*> net, int iterations, int rows, double time_step)
{
  for (int i = 0; i < net.size(); i++) {
    cout << setw(14) << net[i]->get_name();
  }
  cout << endl;
}
