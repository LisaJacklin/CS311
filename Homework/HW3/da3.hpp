// da3.hpp  Writeup from SKELETON
// Lisa Jacklin
// 2023-09-24
//
// For CS 311 Fall 2023
// Header for Assignment 3 functions

#ifndef FILE_DA3_HPP_INCLUDED
#define FILE_DA3_HPP_INCLUDED

#include "llnode.hpp"  // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function


template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 std::size_t index)
{
    //Remember, we need to throw exceptions
    //so the first one to throw, is if the list is empty
    if (!head) {
        throw std::_Xout_of_range("List is empty");
    }

    const LLNode <ValueType>* current = head; //to determine how many to iterate
    std::size_t counter = 0; //counter starts at zero

    while (current) 
    {
        if (counter == index) {
            return current->_data;
        }

        current = current->_next;
        ++counter;
    }
    return ValueType();  // DUMMY
    throw std::_Xout_of_range("index out of range");

}


// Implementation in source file
void didItThrow(const std::function<void()> & ff,
                bool & threw);


template <typename FDIter>
bool checkSorted(FDIter first,
                 FDIter last)
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
        ++first;
        ++next;
    }
    return true;
}


// Implementation in source file
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DA3_HPP_INCLUDED

