// da3.cpp  writeup from SKELETON
// Lisa Jacklin
// 2023-09-24
//
// For CS 311 Fall 2023
// Source for Assignment 3 functions

#include "da3.hpp"     // For Assignment 3 prototypes & templates

#include <functional> //for std::function
using std::function;

//Exercise B
//this is to make sure that ff() throws
void didItThrow(const function<void()> & ff, bool & threw)
{ 
    try {
        ff(); //takes no par!
        threw = false;
    } //note ... as this is special!
    catch (...) {
        threw = true;
        throw; //since this condition is true, we need to throw an exception
    }

}

//Exercise D
//Preconditions: a and b and both not zero, 
//               a and b are both positive
int gcd(int a,int b)
{
    //note that this takes a / b to give the output

    if (b == 0)  //part 1 when b is zero
       {return a;} 
    else if (a > b) //need to check for if a is greater than b as well
        {return gcd(b, a);}
    else  //and lastly the general condition for gcd.
       {return gcd(b, a % b); } 
    
   
}

