//KOMPILERA
//w++17 Simulator.cc test_main.o simulator_test.cc
#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "Simulator.H" //??
#include <string>

class Connection //class
{
public:
  Connection();
  double get_voltage();
  double voltage{};
};

class Component
{
public:
  Component(std::string n, Connection &a, Connection &b);
  virtual ~Component();

  virtual double get_voltage();
  virtual double get_current() = 0;
  virtual std::string get_name();

  virtual void simulate() = 0;
private:
  std::string name;
protected:
  Connection& c1;
  Connection& c2;
};

class Battery : Public Component
{
public:
  Battery(std::string name, double v, Connection  &a, Connection &b);

  double get_current();
private:
  double voltage;
protected:
};

/*
class Resistor
{
public:
private:
protected:
}

class Capacitor
{
public:
private:
protected:
}
*/
#endif
