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
