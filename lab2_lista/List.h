/*
Hur ska elementet i klassen se ut?
Hur ska själva List-klassen se ut?
Vilka publika medlemsfunktioner ska listan ha?
Vilka publika medlemmar ska elementet ha?
Vilka privata medlemmar bör respektive klass ha?
Hur bör listan testas för att hitta så många felorsaker som möjligt

börja medlemsvariabler med typ _ eller m_
*/
#ifndef LIST_H
#define LIST_H

class Sorted_List //class
{
public:
  Sorted_List(): firstptr{nullptr}, lastptr{nullptr} {}
  Sorted_List(element* first, element* last):
  firstptr{first}, lastptr{last} {}
  ~Sorted_List();


  void print();
  void insert(int);
  void remove(int);
  int index(int index);
  int getsize();

private:
  class element
    {
    public:
      element(element* next_el, element* prev_el, int number)
    private:
      int data;
      element* next;
      element* prev;
    };

    element* firstptr;
    element* lastptr;
    int size;

};

#endif

class element
{
public:
  element(int data = null);
private:
  int data;
  element* next;
  element* prev;
};
