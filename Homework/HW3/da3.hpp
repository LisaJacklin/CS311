// da3.hpp
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
#include <stdexcept>   // For std::out_of_range
#include <algorithm>   // For std::is_sorted
#include "da3.hpp"  // For template implementations


// Exercise A
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head, std::size_t index);

// Exercise B
void didItThrow(const std::function<void()> & ff, bool & threw);

// Exercise C
template <typename FDIter>
bool checkSorted(FDIter first, FDIter last);

// Exercise D
int gcd(int a, int b);


#endif  //#ifndef FILE_DA3_HPP_INCLUDED