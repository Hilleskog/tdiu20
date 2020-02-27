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

TEST_CASE ("l.get_size")
{
  Sorted_List l;
  l.insert(666);
  CHECK(l.get_size() == 1);

  l.insert(1337);
  l.insert(13);
  l.insert(133);
  l.insert(1);
  CHECK(l.get_size() == 5);
}

TEST_CASE ("l.at(i)")
{
  Sorted_List l;
  l.insert(6);
  CHECK(l.at(1) == 6);
}
TEST_CASE ("Is sorted?")
{
  Sorted_List l;

  //l.insert(666);
  //l.insert(1337);
  l.insert(13);
  l.insert(133);
  l.insert(1);
  CHECK(l.at(1) == 1);
  CHECK(l.at(2) == 13);
  CHECK(l.at(3) == 133);
  //CHECK(l.at(4) == 666);
  //CHECK(l.at(5) == 1337);
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
