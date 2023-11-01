// da3.hpp  Writeup from SKELETON
// Lisa Jacklin
// 2023-09-24
// Updated Submission 11/1/23
//
// For CS 311 Fall 2023
// Header for Assignment 3 functions

#ifndef FILE_DA3_HPP_INCLUDED
#define FILE_DA3_HPP_INCLUDED

#include "llnode.hpp"  // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <stdexcept>   // for std::out_of_range

//Exercise A
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 std::size_t index)
{
    //Remember, we need to throw exceptions
    //so the first one to throw, is if the list is empty
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    //need to throw another exception if the index size is zero 
    //an exception shouldbe thown that index is  negative or at least size.
    //lookup should then throw an exception....
    if (index !>= 0 && index! < 0 )
    {
        throw std::out_of_range("Size of zero");
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

    //I THINK THIS IS WHERE i AM HAVING TROUBLE AS IT STATES 'LOOKUP DOES NOT THROW'
    throw std::out_of_range("index out of range");
    //note that once this is thrown, the functions WHAT member should return a sting 

}

//Exercise B
// Implementation in source file
void didItThrow(const std::function<void()> & ff,
                bool & threw);

//Exercise C
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

//Exercise D
// Implementation in source file
//note that this is here to calculate the greatest common denominators
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DA3_HPP_INCLUDED

