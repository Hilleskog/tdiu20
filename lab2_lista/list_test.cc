#include "catch.hpp"
#include "List.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;


// här lägger ni era testfall.
// Jobba enligt TDD;
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut

TEST_CASE ("Bekare constructor")
{
  Sorted_List l;
  CHECK(l.is_empty());

  //Sorted_List initialized_list{2,5,7};
}
/*
TEST_CASE ("INSERT")
{
  stringstream ss{};
  Sorted_List l{};
  l.insert(5);
  ss << l;
  CHECK(ss.str() == "5");
}
*/
