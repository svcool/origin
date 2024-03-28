#include <iostream>
#include "List.cpp"
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"

TEST_CASE("List", "test-1") {
    List lst;
    SECTION("Empty LIST") {
        CHECK(lst.Empty() == true);
    }  
    SECTION("Size List") {
        lst.PushBack(5);
        lst.PushBack(3);
        CHECK(lst.Size() == 2);
    }
    SECTION("Clear Lllllist") {
        lst.Clear();
        CHECK(lst.Size() == 0);
    }
 }

int main() {
	return Catch::Session().run();
}