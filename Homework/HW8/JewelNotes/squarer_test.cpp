// squarer_test.cpp
// Lisa Jacklin && Jewel Maldonado
// 2023-11-30
// For CS 311 Fall 2023
// Test Suite for Class Squarer
// Using the doctest testing framework
// This program is a test for the Squarer class. 
// It includes tests for:
//  - Const and non-const Squarer objects
//  - Squarer functionality across a wide range of values
//  - Proper handling of both positive and negative values
//  - Correct computation for integer and floating-point arguments
//  - Special cases, such as the squares of 0, 1, and -1

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "squarer.h"
#include <limits>
#include <cmath>
#include <string>

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
    REQUIRE(sq(-2) == 4);
    REQUIRE(sq(-10) == 100);
    REQUIRE(sq(10) == 100);
    REQUIRE(sq(100) == 10000);
    REQUIRE(sq(50) == 2500);
    REQUIRE(sq(500) == 250000);

}

TEST_CASE("Testing positive and negative values") {
    Squarer sq;
    REQUIRE(sq(-5) == 25);
    REQUIRE(sq(5) == 25);
    // Test squaring of large negative numbers.
    REQUIRE(sq(-100) == 10000);
    REQUIRE(sq(-1000) == 1000000);
    // Test squaring of alternating positive and negative numbers.
    REQUIRE(sq(-15) == 225);
    REQUIRE(sq(15) == 225);


}

TEST_CASE("Testing integer and floating-point arguments") {
    Squarer sq;
    REQUIRE(sq(2) == 4); // Integer
    REQUIRE(doctest::Approx(sq(2.5)) == 6.25); // Floating-point
    REQUIRE(doctest::Approx(sq(0.1)) == 0.01);
    REQUIRE(doctest::Approx(sq(-2.5)) == 6.25);
    // Test squaring of edge floating-point values like very close to zero, or very large/small numbers.
    REQUIRE(doctest::Approx(sq(1e-7)) == 1e-14);
    REQUIRE(doctest::Approx(sq(-1e7)) == 1e14);

}

TEST_CASE("Testing special cases: 0, 1, -1") {
    Squarer sq;
    REQUIRE(sq(0) == 0);
    REQUIRE(sq(1) == 1);
    REQUIRE(sq(-1) == 1);
}

TEST_CASE("Squaring Very Small Floating-Point Numbers") {
    Squarer sq;
    double small_number = 0.0001;
    REQUIRE(doctest::Approx(sq(small_number)) == small_number * small_number);
}


//TEST_CASE("Stress Test for Squarer") {
//    Squarer sq;
//    for (int i = -10000; i <= 10000; ++i) {
//        REQUIRE(sq(i) == i * i);
//    }
//}

TEST_CASE("Squaring NaN and Inf (Floating-Point)") {
    Squarer sq;
    double nan_value = std::numeric_limits<double>::quiet_NaN();
    double inf_value = std::numeric_limits<double>::infinity();

    REQUIRE(std::isnan(sq(nan_value)));
    REQUIRE(sq(inf_value) == std::numeric_limits<double>::infinity());
}

//This one is probably unnecesary cause it may cross with other test cases but the thought is still there maybe can turn into subcases?
TEST_CASE("Squaring Different Data Types") {
    Squarer sq;
    REQUIRE(sq(static_cast<int>(2)) == 4);
    REQUIRE(doctest::Approx(sq(static_cast<double>(2.5))) == 6.25);
    //Lomg Integers
    REQUIRE(sq(static_cast<long>(100000L)) == 100000L * 100000L);
    REQUIRE(sq(static_cast<long long>(123456789LL)) == 123456789LL * 123456789LL);
    // Short and Unsigned
    REQUIRE(sq(static_cast<short>(20)) == 400);
    REQUIRE(sq(static_cast<unsigned int>(300u)) == 90000u);
    // Floats
    REQUIRE(doctest::Approx(sq(static_cast<float>(3.14f))) == 9.8596f);
    REQUIRE(doctest::Approx(sq(static_cast<float>(-2.5f))) == 6.25f);
    // char
    REQUIRE(sq(static_cast<char>(5)) == 25);
    REQUIRE(sq(static_cast<unsigned char>(10)) == 100);
    //itty bitty floats
    REQUIRE(doctest::Approx(sq(static_cast<double>(1e-4))) == 1e-8);
    REQUIRE(doctest::Approx(sq(static_cast<float>(1e-4f))) == 1e-8f);
}