#include "List.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

Sorted_List::Sorted_List():
firstptr{nullptr}, lastptr{nullptr}
{}

Sorted_List::~Sorted_List()
{}

Sorted_List::Sorted_List(std::initializer_list<int> const &list):
Sorted_List()
{
  for (int i : list)
  {
    insert(i);
  }
}

Sorted_List::Element::Element(Element* next, Element* prev, int new_data):
nextptr{next}, prevptr{prev}, data{new_data}
//next{nullptr}, prev{nullptr}, new_data{0}
{}

bool Sorted_List::is_empty()
{
  if (firstptr == nullptr && lastptr == nullptr) //inte nödvändigt att kolla lastptr också men idgaf
  {
    return true;
  } else {
    return false;
  }
}

void Sorted_List::insert (int const& insert_data)
{
  Element* tmp = firstptr;

  if (tmp->data > insert_data)
  {

   firstptr = new Element {tmp, nullptr, insert_data};
    tmp->prevptr = firstptr;

  } else {

    while (tmp->nextptr->data < insert_data && tmp->nextptr != lastptr)
    {
      tmp = tmp->nextptr;
    }

    Element* tmp1 = tmp->nextptr;
    tmp->nextptr = new Element {tmp1, tmp, insert_data};
    tmp1->prevptr = tmp->nextptr;

  }
}

std::ostream& operator << (std::ostream & os, Sorted_List const& rhs)
{
  if(rhs.firstptr != nullptr && rhs.lastptr !=nullptr)
  {
    Sorted_List::Element* tmp {rhs.firstptr};
    while (tmp->nextptr != rhs.lastptr)
    {
      os << tmp->nextptr->value;
      tmp = tmp->nextptr;
      if(tmp->nextptr != rhs.lastptr)
      {
        os << " ";
      }
    }
  }
  return os;
}
/*

/home/eripe625/tdiu20/lab2_lista/List.cc:40: undefined reference
 to `Sorted_List::Element::Element(Sorted_List::Element*,
   Sorted_List::Element*, int)'

*/
//initialized_list som använder sig av insert
//initialized_list element

//if data < nästa_element insert()
//if prev = nullptr{ first= new_el}
//if next = nullptr { last = new_el || om next.data = null }
