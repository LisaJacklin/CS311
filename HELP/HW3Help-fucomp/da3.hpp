#ifndef DA3_HPP
#define DA3_HPP

#include <stdexcept>
#include <cstddef>
#include "llnode.hpp"
#include <functional>
#include <algorithm>
#include <string>

template <typename ValueType>
ValueType lookup(const LLNode<ValueType>* head, std::size_t index) {
    const LLNode<ValueType>* current = head;
    std::size_t currentIndex = 0;

    while (current != nullptr) {
        if (currentIndex == index) {
            return current->_data;
        }
        current = current->_next;
        ++currentIndex;
    }

    throw std::out_of_range("Index " + std::to_string(index) + " is out of range for linked list lookup");
}

void didItThrow(const std::function<void()>& ff, bool& threw);

template <typename FDIter>
bool checkSorted(FDIter first, FDIter last) {
    return std::is_sorted(first, last);
}

int gcd(int a, int b) ;

#endif // DA3_HPP