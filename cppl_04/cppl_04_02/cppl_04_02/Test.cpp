#include "List.h"

TEST_CASE("test list class")
{
    List list;
    list.PushBack(5);
    CHECK(list.Size() == 1);
    list.PushFront(1);
    CHECK(list.Size() == 2);
    list.PushFront(3);
    list.PushBack(10);
    list.PushFront(25);
    CHECK(list.Size() == 10);

    REQUIRE_THROWS(list.PopBack() == 1);
    REQUIRE_THROWS(list.PopFront() == 25);
    REQUIRE_THROWS(list.PopBack() == 10);

    list.Clear();
    REQUIRE_THROWS(list.PopBack() == 1);
    REQUIRE_THROWS(list.PopFront() == 25);
}