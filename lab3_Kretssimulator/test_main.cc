/*
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

int main(int argc, char* argv[])
{
    return Catch::Session{}.run(argc, argv);
}
*/

#include <string>
#include <iostream>
#include <sstream>

#include "Simulator.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc == 5) {

    double battery_voltage{};
    double time_step{};
    int iterations {};
    int rows_to_print{};

    try{
      iterations = stoi(argv[1]);
      rows_to_print = stoi(argv[2]);
      time_step = stod(argv[3]);
      battery_voltage = stod(argv[4]);
    }
    catch(invalid_argument& e){
      cerr<< "Too many/few arguments" << endl;
      exit(0);
    }

    if (time_step <= 0 || battery_voltage <= 0 || iterations <= 0 || rows_to_print <= 0) {
      cerr << "Input out of range" << endl;
    }

    vector<Component*> net;
    Connection a, b, c, d;
    net.push_back(new Battery("Bat", battery_voltage, a, d));
    net.push_back(new Resistor("R1", 6.0, a, b));
    net.push_back(new Resistor("R2", 4.0, b, c));
    net.push_back(new Resistor("R3", 8.0, c, d));
    net.push_back(new Resistor("R4", 12.0, b, d));
    cout << "KRETS 1" << endl;
    simulate(net, iterations, rows_to_print, time_step);

    vector<Component*> krets2;
    Connection p2, l2, r2, n2;
    krets2.push_back(new Battery("Bat", battery_voltage, p2, n2));
    krets2.push_back(new Resistor("R1", 150.0, p2, l2));
    krets2.push_back(new Resistor("R2", 50.0, p2, r2));
    krets2.push_back(new Resistor("R3", 100.0, l2, r2));
    krets2.push_back(new Resistor("R4", 300.0, l2, n2));
    krets2.push_back(new Resistor("R5", 250.0, r2, n2));
    cout << "KRETS 2" << endl;
    simulate(krets2, iterations, rows_to_print, time_step);

    vector<Component*> krets3;
    Connection p, l, r, n;
    krets3.push_back(new Battery("Bat", battery_voltage, p, n));
    krets3.push_back(new Resistor("R1", 150.0, p, l));
    krets3.push_back(new Resistor("R2", 50.0, p, r));
    krets3.push_back(new Capacitor("C3", 1.0, l, r));
    krets3.push_back(new Resistor("R4", 300.0, l, n));
    krets3.push_back(new Capacitor("C5", 0.75, r, n));
    cout << "KRETS 3" << endl;
    simulate(krets3, iterations, rows_to_print, time_step);

  } else {
    cerr<< "Too many/few arguments" << endl;
  }
}
