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
  class Element;
public:
  Sorted_List();
  Sorted_List(Element* first, Element* last);
  ~Sorted_List();

  bool is_empty();
  void insert(int);
/*
  //initialized_list
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
      ~Element();

      Element* next{nullptr};
      Element* prev{nullptr};
      int data;
    };

    Element* firstptr{nullptr};
    Element* lastptr{nullptr};
    int size;

};

#endif
