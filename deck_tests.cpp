#include <iostream>
#include <cassert>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "lib/catch.hpp"
#include "deck.hpp"

TEST_CASE("Nodes can be linked") {
    Node a{.data=1};
    Node b{.data=2};

    a.connectNext(&b);

    REQUIRE(a.next->data == 2);
    REQUIRE(b.previous->data == 1);
}
