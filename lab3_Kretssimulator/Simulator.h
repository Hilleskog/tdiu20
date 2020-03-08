//KOMPILERA
//w++17 Simulator.cc test_main.o simulator_test.cc
#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "Simulator.h" //??
#include <string>
#include <vector>

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
  Component(std::string n, Connection& a, Connection& b);
  virtual ~Component() = default;

  virtual double get_voltage() = 0;
  virtual double get_current() = 0;
  virtual void simulate(double time_step) = 0;

  virtual std::string get_name();

private:
  std::string name;
protected:
  Connection& p;
  Connection& n;
};

class Battery : public Component{
public:
  Battery(std::string name, double v, Connection  &a, Connection &b);

  double get_voltage() override; //Prova utan override sen :D
  double get_current() override;
  void simulate(double time_step) override;

  //std::string get_name();
private:
  double voltage;
};

class Resistor : public Component
{
public:
  Resistor(std::string name, double r, Connection &a, Connection &b);

  double get_current() override;
  void simulate(double time_step) override;

  double get_resistance();

//  void simulate(double time) override;

  //std::string get_name();
private:
  double resistance;
};
/*
class Capacitor
{
public:
  Capacitor::Capacitor(std::string name, double r, Connection &a, Connection &b);

  double get_current() override;

  double get_voltage();
  std::string get_name();
private:
  double capacitance;
  double charge;
protected:
};
*/

void simulate(std::vector<Component*> net, int iterations, int rows, double time_step);


#endif
