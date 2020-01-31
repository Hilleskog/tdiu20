//Komplexa tal
//Realdel, Imaginärdel (real/imag)

#define CATCH_CONFIG_MAIN //Skapa en main så vi slipper
#include "complex.h"
#include "catch.hpp"
#include <sstream>


using namespace std;

TEST_CASE("Create")
{
  complex c {1,2}; //Testar skapa
  CHECK (c.getreal()==1); //Detta är en check, testa booleanskt uttryck
  CHECK (c.getimag()==2);

  complex const c1 {1,3};
  CHECK (c.getreal()==1);
}

TEST_CASE("Print")
{
  //complex c{1,5};
  ostringstringstream oss{};

  //I en SECTION kan allt i samma TEST_CASE användas (Slipp deklarera ostream för varje section)
  SECTION ("Positive values")
  {
    complex c {1,2};
    c.to_string(oss);
    REQUIRE (oss.str()=="1+2i"); //Ist f. CHECK. En require stoppar program ifall det ej fungerar
  }

  SECTION ("Negative values")
  {
    complex c {-1,-2};
    c.to_string(oss);
    REQUIRE(oss.str()=="-1-2i");
  }
}

TEST_CASE ("ADD")
{
  complex c1 {1,2};
  c1.add(5);
  CHECK (c1.getreal()==6);

  complex c2 {3,4};
  c1.add(c2);
  CHECK (c1.getreal()==9);
  CHECK (c1.getimag()==6);
}
