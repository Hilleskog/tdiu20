#include <iostream>
#include <string>

#include "date.h"

using namespace std;

int main () {

  int y, m, d;
  char slask;

  cout << "Enter a date: ";
  cin >> y;
  cin >> slask;
  cin >> m;
  cin >> slask;
  cin >> d;

  Date d1{y, m, d};
  cout << "You entered: " << print(d1) << endl;

return 0;
}
