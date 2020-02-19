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

  void insert (const int& data){
    Element* newOne = new Element(data);

    if (first == nullptr)
    {
      first = newOne;
    }
    else
    {
      newOne->next = first;
      first = newOne;
    }
    size++;
  }
