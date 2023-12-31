/*
 * Darian Marvel
 * 9/15/2021
 * Header containing template class SSArray
*/

#ifndef INCLUDED_SSARRAY_H
#define INCLUDED_SSARRAY_H

//std::size_t
#include <cstddef>

//assert
#include <cassert>

//swap
#include <utility>

//copy
#include <algorithm>

//Invariants: _arrPtr is always a valid pointer that can be deleted
template<typename Data_Type>
class SSArray {

    //Public Data Members
public:
    using value_type = Data_Type;
    using size_type = std::size_t;

    //constructors, deconstructor, etc.
public:

    SSArray() : _arrPtr(new value_type[8]), _size(8)
    {}

    explicit SSArray(size_type size)
    {
        assert(size >= 0);
        _arrPtr = new value_type[size];
        _size = size;
    }

    SSArray(size_type size, value_type item)
    {
        assert(size >= 0);
        _arrPtr = new value_type[size];
        _size = size;

        for (size_type i = 0; i < _size; i++) {
            _arrPtr[i] = item;
        }
    }

    ~SSArray() {
        delete[] _arrPtr;
    }

    //Copy Constructor
    SSArray(const SSArray<value_type>& other) {
        _size = other._size;
        _arrPtr = new value_type[_size];
        std::copy(other.begin(), other.end(), begin());
    }

    //Move Constructor
    SSArray(SSArray<value_type>&& other) noexcept
    {
        _size = other._size;
        _arrPtr = other._arrPtr;

        other._size = 0;
        other._arrPtr = nullptr;
    }

    //Copy Assignment
    SSArray<value_type>& operator=(const SSArray<value_type>& other)
    {
        SSArray<value_type> copy(other);
        swap(copy);
        return *this;
    }

    //Move assignment
    SSArray<value_type>& operator=(SSArray<value_type>&& other) noexcept
    {
        swap(other);
        return *this;
    }

    //public functions
public:

    value_type& operator[](size_type i) {
        assert(i >= 0);
        assert(i < _size);

        return _arrPtr[i];
    }

    const value_type& operator[](size_type i) const {
        assert(i >= 0);
        assert(i < _size);

        return _arrPtr[i];
    }

    value_type* begin() {
        return _arrPtr;
    }

    value_type* end() {
        return _arrPtr + _size;
    }

    const value_type* begin() const {
        return _arrPtr;
    }

    const value_type* end() const {
        return _arrPtr + _size;
    }

    size_type size() const {
        return _size;
    }

    //private functions
private:

    void swap(SSArray<value_type>& other) noexcept {
        assert(_arrPtr != nullptr);
        assert(_size != size_type(-1));

        assert(other._arrPtr != nullptr);
        assert(other._size != size_type(-1));

        std::swap(_size, other._size);
        std::swap(_arrPtr, other._arrPtr);
    }

    //Private Data Members
private:
    value_type* _arrPtr = nullptr;
    size_type _size = size_type(-1);
};

//Global Operator Functions
template<typename Data_Type>
bool operator==(const SSArray<Data_Type>& one, const SSArray<Data_Type>& two) {
    if (one.size() != two.size()) return false;

    for (std::size_t i = 0; i < one.size(); i++) {
        if (one[i] != two[i]) return false;
    }

    return true;
}

template<typename Data_Type>
bool operator!=(const SSArray<Data_Type>& one, const SSArray<Data_Type>& two) {
    return !(one == two);
}


template<typename Data_Type>
bool operator<(const SSArray<Data_Type>& one, const SSArray<Data_Type>& two) {
    for (std::size_t i = 0; i < one.size() && i < two.size(); i++) {
        if (one[i] < two[i]) return true;
        else if (two[i] < one[i]) return false;
    }

    if (two.size() > one.size()) return true;
    return false;
}

template<typename Data_Type>
bool operator<=(const SSArray<Data_Type>& one, const SSArray<Data_Type>& two) {
    return !(one > two);
}

template<typename Data_Type>
bool operator>(const SSArray<Data_Type>& one, const SSArray<Data_Type>& two) {
    return two < one;
}

template<typename Data_Type>
bool operator>=(const SSArray<Data_Type>& one, const SSArray<Data_Type>& two) {
    return !(one < two);
}

#endif