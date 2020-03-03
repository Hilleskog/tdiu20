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

TEST_CASE ("b E k A r E constructor")
{
/*
  SECTION ("Empty")
  {
  Sorted_List l;
  CHECK(l.is_empty());
  }
*/
  SECTION ("initialized_list")
  {
  Sorted_List initialized_list{2,5,7};
  CHECK (initialized_list.at(0) == 2);
  CHECK (initialized_list.at(1) == 5);
  CHECK (initialized_list.at(2) == 7);
  }
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
  CHECK(l.at(0) == 6);
}

TEST_CASE ("Is sorted?")
{
  SECTION ("Insert flera ggr")
  {
    Sorted_List l{};

    //l.insert(666);
    //l.insert(1337);
    //l.insert(13);
    //l.insert(133);
    //l.insert(1);
    l.insert(1);
    CHECK(l.at(0) == 1);

    l.insert(3);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 3);

    l.insert(2);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 2);
    CHECK(l.at(2) == 3);

    l.insert(7);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 2);
    CHECK(l.at(2) == 3);
    CHECK(l.at(3) == 7);
  }
  SECTION("Konstruktor")
  {
    Sorted_List k{1337,666,999,13,123,666,2048};
    CHECK(k.at(0) == 13);
    CHECK(k.at(1) == 123);
    CHECK(k.at(2) == 666);
    CHECK(k.at(3) == 666);
    CHECK(k.at(4) == 999);
    CHECK(k.at(5) == 1337);
    CHECK(k.at(6) == 2048);
  }
}

TEST_CASE ("<< operator")
{
  stringstream ss;
  Sorted_List l {12, 56, 67, 13};
  ss << l;
  CHECK(ss.str() == "12 13 56 67");
}

TEST_CASE ("Remove function")
{

  stringstream ss;
  Sorted_List l {1,2,3};
/*  ss << l;
  CHECK(ss.str() == "1 2 3");
*/
  l.remove(0);
  ss << l;
  CHECK(ss.str() == "2 3");

}
