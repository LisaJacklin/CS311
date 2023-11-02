// da3.cpp  writeup from SKELETON
// Lisa Jacklin
// 2023-09-24
//Updated 2023-11-01
//
// For CS 311 Fall 2023
// Source for Assignment 3 functions

#include "da3.hpp"     // For Assignment 3 prototypes & templates
#include "llnode.hpp"
#include <stdexcept>   // for std::out_of_range
#include <functional>  //for std::function
#include <cstddef>    // 
using std::function;


//Exercise A
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head, std::size_t index)
{
    //Remember, we need to throw exceptions
    //so the first one to throw, is if the list is empty
    if (head = nullptr) {
        throw std::out_of_range("List is empty" + index);   
    }

    //now to check the value of the index
    if (index == 0) 
       {return head ->_data;} 
  
    const LLNode <ValueType>* current = head; //to determine how many to iterate
    std::size_t counter = 0; //counter starts at zero

    //trying a do loop for each count for size
   while (current = current ->_next) {
  
        if (head == nullptr) {
            throw std::out_of_range("lookup: invalid Index value!" + index);
        }

        current = current->_next;
        ++counter;
    }
  
  throw std::out_of_range("Out of Range" + index);
}

//Exercise B
//this is to make sure that ff() throws
void didItThrow(const function<void()> & ff, bool & threw)
{ 
    threw = false;

    try {
        ff(); //takes no par!
    } //note ... as this is special!
    catch (...) {
        threw = true;
        throw; //since this condition is true, we need to throw an exception
    }

}

//Exercise C
template <typename FDIter>
bool checkSorted(FDIter first,FDIter last)
{
    if (first == last) {
        return true; //empty range might as well be sorted
  }

    FDIter next = first;
    ++next;

    while (next != last) { // iterating so long as we aren't at the last item
        if (*next < *first) {
            return false;
        }
        ++next;
    }
    //using is_sorted to check that things are sorted
    return is_sorted(first, last);
}

//need to define the recursive function!
namespace {
    int gcdRecursive(int a, int b) {
        if (b == 0) return a;  // Base case: if b is 0, then a is the GCD
        return gcdRecursive(b, a % b);  // Recursive case: gcd(a, b) = gcd(b, a % b)
    }
}

//Exercise D
//Preconditions: a and b and both not zero, 
//               a and b are both positive
int gcd(int a,int b)
{
    //since a separate function was built here, we can simply call it.    
    return gcdRecursive(a, b);
   
}

