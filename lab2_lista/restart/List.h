#ifndef LIST_H
#define LIST_H

#include "Element.h"

class List
{
public:
  List();
  void addToFirst()(const int&);
private:
  Element* first;
  Element* last;
  int size;

};

#endif
