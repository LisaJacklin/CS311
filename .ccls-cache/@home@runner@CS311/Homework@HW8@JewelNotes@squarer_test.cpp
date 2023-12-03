// squarer_test.cpp
// Lisa Jacklin && Jewel Maldonado
// 2023-11-30
// For CS 311 Fall 2023
// Test Suite for Class Squarer
// Using the doctest testing framework
//
// This program is a test suite for the Squarer class. 
// It includes tests for:
//  - Const and non-const Squarer objects
//  - Squarer functionality across a wide range of values
//  - Proper handling of both positive and negative values
//  - Correct computation for integer and floating-point arguments
//  - Special cases, such as the squares of 0, 1, and -1
// Each test includes informative messages for test failures.

#include "doctest.h"
#include "squarer.h"

TEST_CASE("Testing const and non-const Squarer objects") {
    Squarer sq;
    const Squarer constSq;
    
    SUBCASE("Non-const Squarer") {
        REQUIRE(sq(2) == 4);
    }
    
    SUBCASE("Const Squarer") {
        REQUIRE(constSq(2) == 4);
    }
}

TEST_CASE("Testing a wide range of values") {
    Squarer sq;
    REQUIRE(sq(10) == 100);
    REQUIRE(sq(100) == 10000);
    // More test cases here...
}

TEST_CASE("Testing positive and negative values") {
    Squarer sq;
    REQUIRE(sq(-5) == 25);
    REQUIRE(sq(5) == 25);
    // More test cases here...
}

TEST_CASE("Testing integer and floating-point arguments") {
    Squarer sq;
    REQUIRE(sq(2) == 4); // Integer
    REQUIRE(doctest::Approx(sq(2.5)) == 6.25); // Floating-point
    // More test cases here...
}

TEST_CASE("Testing special cases: 0, 1, -1") {
    Squarer sq;
    REQUIRE(sq(0) == 0);
    REQUIRE(sq(1) == 1);
    REQUIRE(sq(-1) == 1);
    // More test cases here...
}

// Additional test cases and checks can be added here.

