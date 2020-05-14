#include "kitchen.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main () {

  Tool t1{"Stekspade", 1};
  Tool t2{"Slev", 666};
  Tool t3{"Visp", 1337};

  cout << t1.get_type() << " " << t1.get_length() << endl << endl;

  t1.inc_length(12);

  cout << t1 << t2 << endl;

  Toolbox tb{"Låda"};

  cout << "Du har skapat en toolbox vid namn " << tb.get_name() << endl << endl;

  tb.add_tool(t1);
  tb.add_tool(t2);
  tb.add_tool(t3);

  cout << "Toolbox " << tb.get_name() << " innehåller " << tb.get_size() << " st föremål" << endl << endl;

  tb.print();

  return 0;
}
