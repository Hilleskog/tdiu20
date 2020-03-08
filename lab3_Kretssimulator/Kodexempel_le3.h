/*
#: protected
-: private
+: public

Component //Består av connection
# a: & connection
# b: & connection
+ virtual get_current(): double = 0
+ virtual simulate(): void = 0
+ get_voltage(): double

Connection
+ voltage: double // Public så andra kan komponenter kan ändra

Battery //Är en component
- voltage: double
+ simulate(): void

Resistor //Är en component
- resistance: double
+ get_current(): double // override
+ simulate(): void

Capacitor //Är en component
- capacitance: double
- inner_charge: double
+ get_current(): double // override
+ simulate(): void
*/
-------------------------------------------------------
class Animal
{
  void virtual speak() = 0; //Abstrakt klass --> Animal kan ej existera utan ex cat
}

class cat :public Animal
{
  void speak() override;
}

-------------------------------------------------------
class component
{

protected:
  virtual char a, b;

public:

private:
  double get_voltage();
  virtual double get_current()
}

class connection
{
public:
  double voltage;
}

class battery
{

}

class resistor
{

}
