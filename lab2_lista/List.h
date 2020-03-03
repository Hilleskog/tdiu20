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
#include "List.h"
#include <initializer_list>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

class Sorted_List //class
{
  //class Element;
public:
  Sorted_List();
  //Sorted_List(Element* first, Element* last);
  ~Sorted_List();
  Sorted_List(std::initializer_list<int> const &list);

  bool is_empty() const;
  void insert (int const& insert_data);
  int get_size()const;
  int at(int const& i) const;
  void remove(int const& pos);

  /*
  //kopiering
  void print();
  void remove(int);
  int index(int index);
  int getsize();
  */
private:

  class Element
  {
  public:
    Element(Element* next, Element* prev, int new_data);
    //~Element();

    Element* nextptr{nullptr};
    Element* prevptr{nullptr};
    int data;
  };

  Element* firstptr{nullptr};
  Element* lastptr{nullptr};
  int list_size{};

};

std::ostream& operator << (std::ostream & os, Sorted_List const& rhs);


#endif
