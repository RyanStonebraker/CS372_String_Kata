#include "catch.hpp"
#include "string_kata.h"

#include <string>

TEST_CASE ("Empty String") {
    REQUIRE(stringSum("") == 0);
}
