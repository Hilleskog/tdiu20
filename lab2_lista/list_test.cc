#include "catch.hpp"
#include "List.h"

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
  Sorted_List empty{nullptr, nullptr};

  CHECK(empty.firstptr == nullptr);
  CHECK(empty.lastptr == nullptr);

  //Sorted_List initialized_list{2,5,7};
}
