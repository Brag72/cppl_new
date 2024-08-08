#pragma once
#include "List.h"
#include "catch_amalgamated.hpp"

TEST_CASE("test list class")
{
    List list;
    list.PushFront(1);
    list.PushFront(5);
    list.PushFront(10);
    CHECK(list.Empty() == true);
    CHECK(list.Size() != 0);
    list.Clear();
    CHECK(list.Size() == 0);
}