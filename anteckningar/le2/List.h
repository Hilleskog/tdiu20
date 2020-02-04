/*
Hur ska elementet i klassen se ut?
Hur ska själva List-klassen se ut?
Vilka publika medlemsfunktioner ska listan ha?
Vilka publika medlemmar ska elementet ha?
Vilka privata medlemmar bör respektive klass ha?
Hur bör listan testas för att hitta så många felorsaker som möjligt

börja medlemsvariabler med typ _ eller m_
*/

class listan
{
public:
  list():
  firstptr{nullptr}, lastptr{nullptr}
  {}

  void print();
  void insert(int);
  void remove(int);
  -List();
  int index(int index);
  int getsize();
private:
  class element
  {
  public:
    elem* forward;
    elem* backward;
    int data;
  };
  elem firstptr;
  elem lastptr;
  int size;
};
