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

Component::Component(std::string const& n, Connection & a, Connection & b):
name{n}, p{a}, n{b}
{}

Battery::Battery(std::string const name, double const v, Connection & a, Connection & b):
Component(name, a, b), voltage{v}
{}

Resistor::Resistor(std::string const name, double const r, Connection &a, Connection &b):
Component(name, a, b), resistance{r}
{}

Capacitor::Capacitor(std::string const name, double const c, Connection  &a, Connection &b):
Component(name, a, b), capacitance{c}, charge{0.0}
{}


// ---------------- CONNECTION ---------------- //
double Connection::get_voltage() const
{
  return voltage;
}

void Connection::set_voltage(double const& input)
{
  voltage = input;
}

// ---------------- COMPONENT ---------------- //
string Component::get_name() const
{
  return name;
}

double Component::get_voltage() const
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

double Component::get_current() const
{
  return 0.0; // Ja men precis
}

// ---------------- BATTERY ---------------- //
double Battery::get_voltage() const
{
  return voltage;
}

double Battery::get_current() const
{
  return 0.0;
}

void Battery::simulate(double const time_step)
{
  p.voltage = get_voltage();
  n.voltage = 0.0 * time_step;
}

// ---------------- RESISTOR ---------------- //

double Resistor::get_current() const
{
  double tmp{};

  tmp = get_voltage()/resistance;
  return tmp;
}

void Resistor::simulate(double const time_step)
{
  double tmp = (get_voltage()/resistance)*time_step;
  if (p.voltage == n.voltage){
    return;
  } else if(p.voltage > n.voltage) {
    p.voltage -= tmp;
    n.voltage += tmp;
  } else {
    p.voltage += tmp;
    n.voltage -= tmp;
  }
}

// ---------------- CAPACITOR ---------------- //
double Capacitor::get_current() const
{
  double tmp = capacitance*(get_voltage()-charge);
  return tmp;
}

void Capacitor::simulate(double const time_step)
{
  double tmp = get_current()*time_step;
  charge = charge + tmp;

  if(p.voltage >= n.voltage) {
    p.voltage -= tmp;
    n.voltage += tmp;
  } else {
    p.voltage += tmp;
    n.voltage -= tmp;
  }

}

// --------- SIMULATE AND STIMULATE --------- //

void simulate(std::vector<Component*> net, int const iterations, int const rows, double const time_step)
{
  double net_size = net.size();
  for (int i = 0; i < net_size; i++) {
    cout << setw(10) << net[i]->get_name()<<"     |";
  }
  cout << endl;

  for (int i = 0; i < net_size; i++) {
    cout << setw(7) << "Volt" << setw(7) << "Curr"<<" |";
  }
  cout << endl;

  for (int i = 0; i < rows; i++){
    for (int i = 0; i < iterations/rows; i++) {
    for (Component* c : net){ // Simulerar alla komponenter i nätet
      c->simulate(time_step);
    }
    }
    for (Component* c : net){ // Skriv ut värden för samtliga komponenter vid denna tidpunkt
      cout << setw(7) << setprecision(2) << fixed << c->get_voltage()
      << setw(7) << setprecision(2) << c->get_current() << " |";
    }
    cout << endl;
  }
  for (int i=0; i<net.size(); i++) {
    delete net[i];
  }
}
