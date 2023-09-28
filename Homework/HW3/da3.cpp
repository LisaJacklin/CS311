// da3.cpp  writeup from SKELETON
// Lisa Jacklin
// 2023-09-24
//
// For CS 311 Fall 2023
// Source for Assignment 3 functions

#include "da3.hpp"     // For Assignment 3 prototypes & templates

#include <functional>
using std::function;


void didItThrow(const function<void()> & ff,
                bool & threw)
{ // need to try and catch the exceptions
    try {
        ff(); //takes no par!
        threw = false;
    }
    catch (const std::exception&) {
        threw = true;
    }

}


int gcd(int a,
        int b)
{
    //note that this takes a / b to give the output
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
   
}

