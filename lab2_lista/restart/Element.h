#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
  friend class List; // List will be able to access private stuff

public:
  Element(int data = 0);
private:
  int data;
  Element* next;
  Element* prev;
};

#endif
