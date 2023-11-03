// da3.cpp
// Lisa Jacklin
// 2023-09-24
// Updated 2023-11-01
//
// For CS 311 Fall 2023
// Source for Assignment 3 functions

#include "da3.hpp" // header file included

//--------------------------------------------------------------
// Exercise B

void didItThrow(const std::function<void()> &ff, bool &threw) {

  threw = false; // we need to set to false first, because if it throws, it will
                 // be true

  // now to begin the try block to search for exceptions
  try {
    ff();
  } catch (...) { // note the ... as this is special!
    threw = true; // so long as something is caught here, then something has
                  // been thrown, thus threw = true.
    throw;
  } // end of try block

} // end of didItThrow

//--------------------------------------------------------------
// Exercise D
// to make sure the client cannot access the recursive function, I am using
// namespace here
namespace {
// this function takes two values, and so long as they are both positive and a
// and b are not zero, the following can be performed.
int gcdRecursive(int a, int b) {

  if (b == 0)
    return a; // conditioning if b happens to be zero
  // so long as this if statement isn't met, we can return the gcd.
  return gcdRecursive(b, a % b);
} // end of gcdRecursive

} // end of namespace

// with the recursive function built, now we simply need to allow gcd to call
// this function.
int gcd(int a, int b) { return gcdRecursive(a, b); } // end of gcd