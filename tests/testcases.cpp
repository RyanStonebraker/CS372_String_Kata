// testcases.cpp
// 3/9/2018
// Ryan Stonebraker
// Test Cases for the string calculator kata.

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
    REQUIRE (stringSum("121") == 121);
    REQUIRE (stringSum("5252332") == 0);
    REQUIRE (stringSum("1000") == 1000);
    REQUIRE (stringSum("999") == 999);
    REQUIRE (stringSum("99857") == 0);
    REQUIRE (stringSum("1245299") == 0);
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
    REQUIRE(stringSum("123445,55314") == 0+0);
    REQUIRE(stringSum("999456,6341") == 0+0);
  }
  SECTION ("Multiple Numbers") {
    REQUIRE(stringSum("1,1,1") == 3);
    REQUIRE(stringSum("9,8,241") == 9 + 8 + 241);
    REQUIRE(stringSum("2313, 5113, 4621, 6621,    431,2") == 0 + 0 + 0 + 0 + 431 + 2);
    REQUIRE(stringSum("2, 523,  5") == 2 + 523 + 5);
  }
}

TEST_CASE("Newline Delimited Numbers") {
  SECTION ("Multiple Numbers") {
    REQUIRE(stringSum("1\n1") == 2);
    REQUIRE(stringSum("1\n0") == 1);
    REQUIRE(stringSum("131\n4141\n0\n896") == 131 + 0 + 0 + 896);
    REQUIRE(stringSum("16211\n415141\n10\n896\n4") == 0 + 0 + 10 + 896 + 4);
  }
}

TEST_CASE("Newline and Comma Delimited Numbers") {
  SECTION ("Multiple Numbers") {
    REQUIRE(stringSum("1\n0,3") == 4);
    REQUIRE(stringSum("51\n31,9") == 51 + 31 + 9);
    REQUIRE(stringSum("124,41, 54\n78\n2") == 124 + 41 + 54 + 78 + 2);
  }
}

TEST_CASE("Custom Delimiters") {
  SECTION ("Single Letter Delimiter") {
    REQUIRE (stringSum("//1\n123213") == 232 + 3);
    REQUIRE (stringSum("// t\n25t213") == 25 + 213);
    REQUIRE (stringSum("//9\n9999999") == 0);
    REQUIRE (stringSum("// 2\n23") == 3);
  }

  SECTION ("Muliple Letter Delimiter") {
    REQUIRE (stringSum("// [test]\n123test123test456") == 123 + 123 + 456);
    REQUIRE (stringSum("//[123]\n9912388812377771231") == 99 + 888 + 0 + 1);
    REQUIRE (stringSum("//   [987]\n9987898779876") == 9 + 8 + 7 + 6);
  }

  SECTION ("Multiple Single Letter Delimiters") {
    REQUIRE (stringSum("// 1 a b c 9 \n 213a4b5c697") == 2 + 3 + 4 + 5 + 6 + 7);
    REQUIRE (stringSum("//t a b \n 1t20a30b431") == 1 + 20 + 30 + 431);
  }

  SECTION ("Multiple Multi-Letter Delimiters") {
    REQUIRE (stringSum("// [abc][123] [1 2]\n 4abc512361 27") == 4 + 5 + 6 + 7);
    REQUIRE (stringSum("//[] [ab] [qw3rty]\n 123ab456qw3rty789") == 123 + 456 + 789);
  }

  SECTION ("Both Single and Multi-Letter Delimiters") {
    REQUIRE (stringSum("//[abc] a 2 [12]\n3abc4a526127a1") == 3 + 4 + 5 + 6 + 7 + 1);
    REQUIRE (stringSum("// 1 [,,][__] n\n3n4n516,,7__8") == 3 + 4 + 5 + 6 + 7 + 8);
  }
}
