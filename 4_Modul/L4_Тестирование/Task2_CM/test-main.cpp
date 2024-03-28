#include <iostream>
#include "List.cpp"
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"
//Нужно проверить работу функций :
//
//PushBack.
//PushFront.
//PopBack.Проверьте правильность работы на пустом списке.
//PopFront.Проверьте правильность работы на пустом списке.

TEST_CASE("PushBack", "test-1") {
    List lst;
    SECTION("PushBack LIST") {
        INFO("PushBack");
        lst.PushBack(5);
        lst.PushBack(4);
        CHECK(lst.Size() == 2);
        lst.Clear();
    }  
    SECTION("PushFront") {
        lst.PushFront(2);
        lst.PushFront(5);
        CHECK(lst.Size() == 2);
        lst.Clear();
    }
    SECTION("PopBack") {
        lst.PushFront(2);
        lst.PushFront(5);
        lst.PopBack();
        CHECK(lst.Size() == 1);
        lst.Clear();
    }
    SECTION("PopFront") {
        lst.PushFront(2);
        lst.PushFront(5);
        lst.PopFront();
        CHECK(lst.Size() == 1);
    }
 }

int main() {
	return Catch::Session().run();
}