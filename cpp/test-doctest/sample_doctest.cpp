#include "ApprovalTests.hpp"
#include "doctest/doctest.h"


TEST_CASE ("Good Unit Test") {
    SUBCASE("sample section") {
        REQUIRE(true == false);
    }
}


