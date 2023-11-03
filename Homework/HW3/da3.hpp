// da3.hpp
// Lisa Jacklin
// 2023-09-24
// Updated 2023-11-02
//
// For CS 311 Fall 2023
// Source for Assignment 3 functions

#ifndef DA3_HPP
#define DA3_HPP

//note that all includes are in header to clean up the source file for viewing purposes
#include <stdexcept>   // for std::out_of)range
#include <cstddef>     //for std::size_t
#include "llnode.hpp"  //required unmodified header
#include <functional>  //for std::function
#include <algorithm>   //for std::is_sorted
#include <string>      //for std::to_string

//--------------------------------------------------------------
//Exercise A
template <typename ValueType>
ValueType lookup(const LLNode<ValueType>* head, 
                 std::size_t index) {
  
    const LLNode<ValueType>* current = head;
    std::size_t currentIndex = 0;         //initialized size

    //need to make sure that the current start value is not a null value!
    while (current != nullptr) {
        if (currentIndex == index) {
            return current->_data;
        }
        current = current->_next;
        ++currentIndex;                   //continue through to next index value
    }
    //throw an exception if the index is out of range including the index tag
    throw std::out_of_range("Index out of range:  " + std::to_string(index));
} //end of lookup.

//--------------------------------------------------------------
//Exercise B
//declaration of didItThrow
void didItThrow(const std::function<void()>& ff, bool& threw);

//--------------------------------------------------------------
//Exercise C
template <typename FDIter>
bool checkSorted(FDIter first, FDIter last) {
    
    return std::is_sorted(first, last);    //within STL algorithms, we can check if something is sorted using is_sorted 
                                           //so long as it is given the first and last iterator values.
} //end of checkSorted.

//--------------------------------------------------------------
//Exercise D
//declaration of gcd which uses a recursive function which is built in source file.
int gcd(int a, int b) ;

#endif // end DA3_HPP