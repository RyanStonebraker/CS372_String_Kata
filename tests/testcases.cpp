#include "catch.hpp"
#include "string_kata.h"

#include <string>

TEST_CASE ("Empty String") {
    REQUIRE(stringSum("") == 0);
}

TEST_CASE ("Single Number Tests.") {
  SECTION ("Single Digit") {
    REQUIRE (stringSum("0") == 0);
    REQUIRE (stringSum("1") == 1);
    REQUIRE (stringSum("3") == 3);
    REQUIRE (stringSum("5") == 5);
    REQUIRE (stringSum("8") == 8);
  }
  SECTION ("Double Digit") {
    REQUIRE (stringSum("10") == 10);
    REQUIRE (stringSum("32") == 32);
    REQUIRE (stringSum("51") == 51);
    REQUIRE (stringSum("89") == 89);
    REQUIRE (stringSum("99") == 99);
  }
  SECTION ("Many Digits") {
    REQUIRE (stringSum("12131231") == 12131231);
    REQUIRE (stringSum("5252332") == 5252332);
    REQUIRE (stringSum("1000000000") == 1000000000);
    REQUIRE (stringSum("909012331") == 909012331);
    REQUIRE (stringSum("99857") == 99857);
    REQUIRE (stringSum("1245299") == 1245299);
  }

  SECTION ("Negative Numbers (Checking for throw).") {
    SECTION ("-1 Should Throw.") {
      bool didThrow = false;
      try {
        stringSum("-1");
      } catch (...) {
        didThrow = true;
      }
      REQUIRE(didThrow);
    }
    SECTION ("-5 Should Throw.") {
      bool didThrow = false;
      try {
        stringSum("-5");
      } catch (...) {
        didThrow = true;
      }
      REQUIRE(didThrow);
    }
    SECTION ("-2414141425 Should Throw.") {
      bool didThrow = false;
      try {
        stringSum("-2414141425");
      } catch (...) {
        didThrow = true;
      }
      REQUIRE(didThrow);
    }
  }
}

TEST_CASE("Comma Delimited Numbers") {
  SECTION ("Two Numbers") {
    REQUIRE(stringSum("1,1") == 2);
    REQUIRE(stringSum("9,8") == 17);
    REQUIRE(stringSum("5,5") == 10);
    REQUIRE(stringSum("125,54") == 125+54);
    REQUIRE(stringSum("123445,55314") == 123445+55314);
    REQUIRE(stringSum("999456,6341") == 999456+6341);
  }
  SECTION ("Multiple Numbers") {
    REQUIRE(stringSum("1,1,1") == 3);
    REQUIRE(stringSum("9,8,241") == 9 + 8 + 241);
    REQUIRE(stringSum("2313, 5113, 4621, 6621,    431,2") == 2313 + 5113 + 4621 + 6621 + 431 + 2);
    REQUIRE(stringSum("2, 523,  5") == 2 + 523 + 5);
  }
}

TEST_CASE("Newline Delimited Numbers") {
  SECTION ("Multiple Numbers") {
    REQUIRE(stringSum("1\n1") == 2);
    REQUIRE(stringSum("1\n0") == 1);
    REQUIRE(stringSum("131\n4141\n0\n896") == 131 + 4141 + 0 + 896);
    REQUIRE(stringSum("16211\n415141\n10\n896\n4") == 16211 + 415141 + 10 + 896 + 4);
  }
}

TEST_CASE("Newline and Comma Delimited Numbers") {
  SECTION ("Multiple Numbers") {
    REQUIRE(stringSum("1\n0,3") == 4);
    REQUIRE(stringSum("51\n31,9") == 51 + 31 + 9);
    REQUIRE(stringSum("124,41, 54\n78\n2") == 124 + 41 + 54 + 78 + 2);
  }
}
