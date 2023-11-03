// da3.cpp
// Lisa Jacklin
// 2023-09-24
// Updated 2023-11-01
//
// For CS 311 Fall 2023
// Source for Assignment 3 functions

#include "da3.hpp"     // For Assignment 3 prototypes & templates
#include "llnode.hpp"
#include <stdexcept>   // For std::out_of_range
#include <functional>  // For std::function
#include <cstddef>     // For std::size_t
#include <string>

// Exercise A
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head, std::size_t index) {
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    for (std::size_t i = 0; i < index; ++i) {
        head = head->_next;
        if (!head) {
            throw std::out_of_range("Index out of range");
        }
    }
    return head->_data;
}

// Force instantiation of lookup for int and std::string, since we cannot
// have the template in the .cpp file.
template int lookup(const LLNode<int> * head, std::size_t index);
template std::string lookup(const LLNode<std::string> * head, std::size_t index);

// Exercise B
void didItThrow(const std::function<void()> & ff, bool & threw) {
    try {
        ff();
        threw = false;
    } catch (...) {
        threw = true;
        throw;  // Rethrow the current exception
    }
}

// Exercise C
template <typename FDIter>
bool checkSorted(FDIter first, FDIter last) {
    return std::is_sorted(first, last);
}

// Force instantiation of checkSorted for iterators of int and std::string.
template bool checkSorted(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last);
template bool checkSorted(std::vector<std::string>::const_iterator first, std::vector<std::string>::const_iterator last);

namespace {

// Recursive helper function for gcd
int gcd_helper(int a, int b) {
    if (b == 0) return a;
    return gcd_helper(b, a % b);
}

} // end anonymous namespace

// Exercise D
int gcd(int a, int b) {
    if (a < 0 || b < 0) {
        throw std::invalid_argument("gcd: arguments must be nonnegative");
    }
    if (a == 0 && b == 0) {
        throw std::invalid_argument("gcd: at least one argument must be positive");
    }
    return gcd_helper(a, b);
}