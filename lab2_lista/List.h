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
  class element;
public:
  Sorted_List();

  Sorted_List(element* first, element* last);
  ~Sorted_List();

  //initialized_list
  //kopiering
  void print();
  void insert(int);
  void remove(int);
  int index(int index);
  int getsize();

private:
  class element
    {
    public:
      element(element* next_el, element* prev_el, int number);
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
<<<<<<< HEAD
=======
/*
class element
{
public:
  element(int data = null);
private:
  int data;
  element* next;
  element* prev;
};
*/
>>>>>>> 6ba19f133001381d649b8d5fac2e6e13ebc5c6c1
