#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "Time.h"

using namespace std;

// här lägger ni era testfall.
// Jobba enligt TDD;
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut

TEST_CASE ("Default constructor")
{
    Time t;

    CHECK(t.gethour() == 0);
    CHECK(t.getminute() == 0);
    CHECK(t.getsecond() == 0);
}

// the following line will halt the compilation process. Move it
// one test case at the time and then start creating your own test
// cases
TEST_CASE ( "Constructor with numeric arguments" )
{
    Time t{12,13,14};
    CHECK(t.gethour() == 12);
    CHECK(t.getminute() == 13);
    CHECK(t.getsecond() == 14);
}

TEST_CASE ("Constructor with faulty argument")
{
    CHECK_THROWS( Time{41,0,0} );
    CHECK_THROWS( Time{0,99,0} );
    CHECK_THROWS( Time{0,0,99} );
}

TEST_CASE ("String constructor")
{
    Time t{"12:23:12"};
    CHECK(t.gethour() == 12);
    CHECK(t.getminute() == 23);
    CHECK(t.getsecond() == 12);

    SECTION ("Throws as well")
    {
        CHECK_THROWS( Time{"02:11:74"} );
    }
}

TEST_CASE ("am or pm")
{
    Time t{12,12,31};
    CHECK_FALSE(t.is_am());
    Time t2{1,2,3};
    CHECK(t2.is_am());
}

TEST_CASE ("Convert to string" )
{
    CHECK( Time{12,12,12}.to_string()     ==    "12:12:12" );
    CHECK( Time{12, 1, 2}.to_string()     ==    "12:01:02" );

    CHECK( Time{14,33,12}.to_string(true) == "02:33:12 pm" );
    CHECK( Time{10,33,12}.to_string(true) == "10:33:12 am" );

    Time t{11,22,33};
    CHECK( t.to_string() == "11:22:33");
}


TEST_CASE ("Add n seconds")
{
  Time t {1, 2, 3};
  t = t + 30;
  CHECK(t.getsecond()==33);

  Time t2 {0,0,55};
  t2 + 25;
  CHECK (t.to_string() == "00:01:20");
}


#if 0



TEST_CASE ("Conversion to string" ) // WTF
{
    CHECK( string(Time{2,4,1}) == "02:04:01" );
}


TEST_CASE ("Output operator" )
{
    stringstream ss;
    SECTION("Simple output")
    {
        ss << Time{2,5,1};
        CHECK(ss.str() == "02:05:01");
    }
    SECTION("Chained output")
    {
        ss << Time{23,10,32} << "---";
        CHECK(ss.str() == "23:10:32---");
    }
    SECTION("Const time")
    {
        Time const t{23,23,23};
        ss << t;
        CHECK(ss.str() == "23:23:23");
    }
}
#endif
