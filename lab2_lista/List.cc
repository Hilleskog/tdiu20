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
{

  if (is_empty() == false)
  {
    Element* tmp = firstptr;
    while(tmp != lastptr){
      tmp = tmp->nextptr;
      delete tmp->prevptr;
    }
    delete tmp;
    firstptr = nullptr;
    lastptr = nullptr;
    list_size = 0;
  }
}

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
          lastptr = tmp->nextptr;
        }
      }
    }
    list_size++;
  }

  int Sorted_List::get_size()const
  {
    return list_size;
  }

  int Sorted_List::at(int const& position )const
  {
    if(position < get_size())
    {
    Element* tmp = firstptr;
    for (int i = 0; i < position; i++)
    {
      tmp = tmp->nextptr;
    }
    return tmp->data;
  }else{
    throw std::logic_error("Större än listan");

  }
  }

  void Sorted_List::remove(int const& pos)
  {
    Element* tmp = firstptr;
    /*
    for (int i = pos; i > 0; i--){
      tmp = tmp->nextptr;
    }
    */
    if (tmp->prevptr == nullptr){
      cout << "tmp->prevptr == nullptr" << endl;
      firstptr = tmp->nextptr;
      firstptr->prevptr = nullptr;
      //delete tmp;
    } else if (tmp->nextptr == nullptr){
      cout << "tmp->nextptr == nullptr" << endl;
      lastptr = tmp->prevptr;
      lastptr->nextptr = nullptr;
      delete tmp;
    } else {
      cout << "else" << endl;
      tmp->prevptr->nextptr = tmp->nextptr;
      delete tmp;
    }
  //  cout << get_size() <<endl;
    list_size--;
  //cout << get_size() <<endl;
  }

ostream& operator << (ostream & os, Sorted_List const& rhs)
{
  cout << rhs.get_size() << endl;
  for (int i {0}; i < rhs.get_size(); i++)
  {
    os << rhs.at(i);

    if (i+1 != rhs.get_size()){
    os << " ";
    }
  }
  return os;
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
*/
