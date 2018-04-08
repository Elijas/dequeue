#include <iostream>
#include <cassert>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "lib/catch.hpp"
#include "deck.hpp"
#define ASSERT(x) REQUIRE((x)) // Hot fix for bug when test library messes up pointers of the object tested, particulary "1 == d.peekLast()", when function implemented as "return this->first->data"


TEST_CASE("Nodes can be linked") {
    Node a(1);
    Node b(2);

    a.connectNext(&b);

    ASSERT(a.next->data == 2);
    ASSERT(b.previous->data == 1);
}

TEST_CASE("Deck is initialized empty") {
    //-

    Deck d;

    ASSERT(d.isEmpty());
}

TEST_CASE("Deck receives the first value correctly") {
    Deck d;

    d.pushBack(1);

    ASSERT(!d.isEmpty());
    ASSERT(d.peekFirst() == 1);
    ASSERT(d.peekLast() == 1);
}

TEST_CASE("Deck receives the second value correctly to front") {
    Deck d;
    d.pushFront(1);

    d.pushFront(2);

    ASSERT(d.peekFirst() == 2);
    ASSERT(d.peekLast() == 1);
}

TEST_CASE("Deck receives the second value correctly to back") {
    Deck d;
    d.pushBack(1);

    d.pushBack(2);

    ASSERT(d.peekFirst() == 1);
    ASSERT(d.peekLast() == 2);
}

TEST_CASE("Deck ignores deletion if deck is empty") {
    Deck d;

    d.deleteLast();

    ASSERT(d.isEmpty());
}

TEST_CASE("Deck deletes the single value correctly") {
    Deck d;
    d.pushBack(1);

    d.deleteLast();

    ASSERT(d.isEmpty());
}

TEST_CASE("Deck deletes the first value correctly") {
    Deck d;
    d.pushBack(1);
    d.pushBack(2);

    d.deleteFirst();

    ASSERT(d.peekFirst() == 2);
    ASSERT(d.peekLast() == 2);
}

TEST_CASE("Deck deletes the last value correctly") {
    Deck d;
    d.pushBack(1);
    d.pushBack(2);

    d.deleteLast();

    ASSERT(d.peekFirst() == 1);
    ASSERT(d.peekLast() == 1);
}
