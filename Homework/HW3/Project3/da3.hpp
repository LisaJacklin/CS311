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

//note that for simplification, i'm moving anything other than declarations to cpp
//Exercise A
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head, std::size_t index);

//Exercise B
// Implementation in source file
void didItThrow(const std::function<void()> & ff,bool & threw);

//Exercise C
template <typename FDIter>
bool checkSorted(FDIter first,FDIter last);

//Exercise D
// Implementation in source file
//note that this is here to calculate the greatest common denominators
int gcd(int a,int b);

#endif  //#ifndef FILE_DA3_HPP_INCLUDED

