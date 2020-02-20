#include "List.h"
using namespace std;

Sorted_List::Sorted_List():
firstptr{nullptr}, lastptr{nullptr} {}

Sorted_List::~Sorted_List()
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

    Sorted_List::Element* tmp = firstptr;

    if (tmp->data > insert_data)
    {

      firstptr = new Element {tmp, nullptr, insert_data};
      tmp->prev = firstptr;

    } else {

      while (tmp->next->data < insert_data && tmp->next != lastptr)
      {
        tmp = tmp->next;
      }

      Sorted_List::Element* tmp1 = tmp->next;
      tmp->next = new Element {tmp1, tmp, insert_data};
      tmp1->prev = tmp->next;

    }
  }

  //initialized_list som använder sig av insert
  //initialized_list element

//if data < nästa_element insert()
//if prev = nullptr{ first= new_el}
//if next = nullptr { last = new_el || om next.data = null }
