class Employee : public Person
{
public:
  Employee(string n, string p, string w, int s);
  string get_phone() const; //Ersätter Person:s medlemsfunction
private:
  string work_phone;
  int salary
}

//---------------

class Person
{
public:
  ...blabla;

private: //endast för klassen själv
  string name;

protected: // endast för klassen själv och härledda klasser
string phone;
}

//sid 28 på föreläsningen
class shape // possible subclasses : curckem square, rect
{
  virtual int area() const = 0; // pure virtual
}
