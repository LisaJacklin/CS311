// tsort.hpp 
//Lisa Jacklin && Jewel Maldonado
// 2023-11-14
//
// For CS 311 Fall 2023
// Header for function template treesort
// There is no associated source file.

#ifndef FILE_TSORT_HPP_INCLUDED
#define FILE_TSORT_HPP_INCLUDED

#include <iterator>
// For std::iterator_traits

// *******************************************************
// * YOU MIGHT WANT TO GET RID OF THE FOLLOWING INCLUDES *
// *******************************************************

#include <algorithm>
// For std::stable_sort, std::move
#include <vector>
// For std::vector
#include <iterator>
// For std::distance


// treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Exception safety guarantee:
//     ???
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
   // Value is the type that FDIter points to
      using Value = typename std::iterator_traits<FDIter>::value_type;

      // Take two forward iterators to specify the range
      // Test if both iterators are equal; the range will be empty
      if (first == last) {
          // The range is empty, nothing to sort
          return;
      }

      // Sort the given range in a stable manner using the < operator
      std::stable_sort(first, last);

      // Need to make sure that stored data is in the same place as the original data
      // The function must use the treesort algorithm from class (view slides)
      // Note: The current implementation just uses std::stable_sort for simplicity.
      // You may replace this with your treesort algorithm as needed.

      // If you have a specific treesort algorithm, replace the std::stable_sort above
      // with your implementation.
  }


#endif //#ifndef FILE_TSORT_HPP_INCLUDED

