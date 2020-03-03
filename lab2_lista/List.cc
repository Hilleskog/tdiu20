#include "List.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;


Sorted_List::Sorted_List(): //element* first, element* last
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

  bool Sorted_List::is_empty() const
  {
    if (firstptr == nullptr && lastptr == nullptr) //inte nödvändigt att kolla lastptr också men idgaf
    {
      return true;
    } else {
      return false;
    }
  }

  void Sorted_List::print_list()const
  {

    for (int i{1}; i < list_size; i++)
    {
      cout<< at(i) << "  ";
    }
    cout << endl;
  }

  void Sorted_List::insert (int const& insert_data)
  {
    if (is_empty() == true)
    {
      firstptr = new Element {nullptr, nullptr, insert_data};
      lastptr = firstptr;
    } else {
      Element* tmp = firstptr;
      if (insert_data < tmp->data)
      {
        firstptr = new Element {tmp, nullptr, insert_data};
        tmp->prevptr = firstptr;
      } else {
        while (insert_data > tmp->data && tmp->nextptr != nullptr)
        {
          tmp = tmp->nextptr;
        }
        if (tmp->data >= insert_data)
        {
          Element* tmp1 = tmp;
          tmp = tmp->prevptr;

          tmp->nextptr = new Element {tmp1, tmp, insert_data};
          tmp1->prevptr = tmp->nextptr;

        } else {
          tmp->nextptr = new Element {nullptr, tmp, insert_data};
        }
      }
    }
    list_size++;

  }

  int Sorted_List::get_size()const
  {
    return list_size;
  }

  int Sorted_List::at(int position)const
  {
    Element* tmp = firstptr;
    for (int i = 0; i < position; i++)
    {
      tmp = tmp->nextptr;
    }
    return tmp->data;
  }
/*
std::ostream& operator << (std::ostream & os, Sorted_List const& rhs)
{
  if(rhs.is_empty() == false)
  {
    Element* tmp = rhs->firstptr;
    while (tmp->nextptr != rhs->lastptr)
    {
      os << tmp->nextptr->value;
      tmp = tmp->nextptr;
      if(tmp->nextptr != rhs->lastptr)
      {
        os << " ";
      }
    }
  }
  return os;
}

if (is_empty() == false)
{
  Element* tmp = firstptr;

  if (tmp->data > insert_data)
  {
    firstptr = new Element {tmp, nullptr, insert_data};
    tmp->prevptr = firstptr;
    cout << "in-data mindre än nästa data i listan   " << insert_data << " <  "<< tmp->data << endl;
  } else {
    cout << "In-data större än nästa data i listan   " << insert_data <<endl;
    while (tmp->data < insert_data && tmp->nextptr != nullptr)
    {
      cout << "Vi går ett steg   " << insert_data << "   " << tmp->data << endl;
      if (tmp->nexptr == nullptr)
      {

      }
      tmp = tmp->nextptr;
    }
      cout << "Dags för insert   " << insert_data <<"   " << tmp->data << endl;
      if (tmp->nextptr == nullptr)
      {
        cout << "tmp->nextptr == nullptr  " << insert_data << "   " << tmp->data << endl;
        tmp->nextptr = new Element {nullptr, tmp, insert_data};
      } else {
        cout << "tmp->nextptr != nullptr   " << insert_data << "   " << tmp->data << endl;
        Element* tmp1 = tmp->nextptr;
        tmp->nextptr = new Element {tmp1, tmp, insert_data};
        tmp1->prevptr = tmp->nextptr;
      }
  }
} else {
  firstptr = new Element {nullptr, nullptr, insert_data};
  lastptr = firstptr;
  cout << "Listan är tom. "<< insert_data << " nullptr" << endl;
}
list_size++;

*/




//error: expected initializer before ‘using’ using namespace std;

//initialized_list som använder sig av insert
//initialized_list element

//if data < nästa_element insert()
//if prev = nullptr{ first= new_el}
//if next = nullptr { last = new_el || om next.data = null }
