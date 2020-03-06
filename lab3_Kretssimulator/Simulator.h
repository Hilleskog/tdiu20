//KOMPILERA
//w++17 Simulator.cc test_main.o simulator_test.cc
#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "Simulator.h" //??
#include <string>

class Connection //class
{
public:
  Connection();

  double get_voltage();
  void set_voltage(double & input);
  double voltage{};
};

class Component
{
public:
  Component(std::string n, Connection &a, Connection &b);
  virtual ~Component() = default;

  virtual double get_voltage() = 0;
  virtual double get_current() = 0;
  //virtual void simulate() = 0;
  virtual std::string get_name();

private:
  std::string name;
protected:
  Connection& c1;
  Connection& c2;
};

class Battery : public Component
{
public:
  Battery(std::string name, double v, Connection  &a, Connection &b);

  //double get_voltage() override;
  //double get_current() override;
private:
  double voltage;
};

class Resistor : Component
{
public:
  Resistor(std::string name, double r, Connection &a, Connection &b);
  double get_current() override;
private:
  double resistance;
protected:
};

/*
class Capacitor
{
public:
private:
protected:
}
*/
#endif
