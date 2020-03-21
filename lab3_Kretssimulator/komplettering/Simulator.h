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

  double get_voltage() const;
  void set_voltage(double const& input);
  double voltage{};
};

class Component
{
public:
  Component(std::string const& n, Connection& a, Connection& b);
  virtual ~Component() = default;

  virtual double get_current() const = 0; // Är pure virtual för att de alltid är olika
  virtual void simulate(double const time_step) = 0;

  double get_voltage() const;
  std::string get_name() const;
private:
  std::string name;
protected:
  Connection& p;
  Connection& n;
};

class Battery : public Component
{
public:
  Battery(std::string const name, double const v, Connection & a, Connection & b);

  double get_voltage() const; //Prova utan override sen :D
  double get_current() const override;
  void simulate(double const time_step) override;
private:
  double voltage;
};

class Resistor : public Component
{
public:
  Resistor(std::string const name, double const r, Connection &a, Connection &b);

  double get_current() const override;
  void simulate(double const time_step) override;

private:
  double resistance;
};


class Capacitor : public Component
{
public:
  Capacitor(std::string const name, double const c, Connection  &a, Connection &b);

  double get_current() const override;
  void simulate(double const time_step) override;

private:
  double capacitance;
  double charge{0};
protected:
};

void simulate(std::vector<Component*> net, int const iterations, int const rows, double const time_step);


#endif
