#include "List.h"

using namespace std;

List::List(): first(NULL), last(NULL), size(0)
{}

void List::addToFirst(const int& data)
{
  Element* newOne = new Elemenent(data);

  if (first == NULL)
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
