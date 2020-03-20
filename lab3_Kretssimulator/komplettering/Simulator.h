//KOMPILERA
//w++17 Simulator.cc test_main.o simulator_test.cc
#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "Simulator.h" //??
#include <string>
#include <vector>

//TODO: De medlemsfunktioner som inte modifierar objektet ska vara const.
//TODO: Parametrar som inte modifieras ska passeras som const. alt. const ref.

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

  virtual double get_current() = 0; // Är pure virtual för att de alltid är olika
  virtual void simulate(double time_step) = 0;

  double get_voltage();
  std::string get_name();
private:
  std::string name;
protected:
  Connection& p;
  Connection& n;
};

class Battery : public Component
{
public:
  Battery(std::string name, double v, Connection  &a, Connection &b);

  double get_voltage(); //Prova utan override sen :D
  double get_current() override;
  void simulate(double time_step) override;
private:
  double voltage;
};

class Resistor : public Component
{
public:
  Resistor(std::string name, double r, Connection &a, Connection &b);

  double get_current() override;
  void simulate(double time_step) override;

private:
  double resistance;
};


class Capacitor : public Component
{
public:
  Capacitor(std::string name, double c, Connection  &a, Connection &b);

  double get_current() override;
  void simulate(double time_step) override;

private:
  double capacitance;
  double charge{0};
protected:
};

void simulate(std::vector<Component*> net, int iterations, int rows, double time_step);


#endif
