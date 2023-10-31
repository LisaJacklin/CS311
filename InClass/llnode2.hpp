// llnode2.hpp  UNFINISHED
// Glenn G. Chappell
// 2023-10-26
//
// For CS 311 Fall 2023
// Header for struct LLNode2
// Singly Linked List node
// Based on llnode.hpp. Function size from use_list.cpp.
// There is no associated source file.

#ifndef FILE_LLNODE2_HPP_INCLUDED
#define FILE_LLNODE2_HPP_INCLUDED

#include <cstddef>
// For std::size_t
#include <memory>
//for std::unique_ptr<>
//for std::make_unique


// forward declarations... this is so pop_front will work as we are using it higher
//this is where we go through and add in the templates of the two we need, pop_forward and one other to allow the program to compile.

// *********************************************************************
// struct LLNode2 - Struct definition
// *********************************************************************


// struct LLNode2
// Singly Linked List node, with client-specified value type
// Invariants:
//     Either _next is nullptr, or _next points to an LLNode2, allocated
//      with new, owned by *this.
// Requirements on Types:
//     ValType must have a copy ctor and a (non-throwing) dctor.
template <typename ValType>
struct LLNode2 {
    ValType    _data;  // Data for this node
    std::unique_ptr<LLNode2>   _next;  // Ptr to next node, or nullptr if none

    // The following simplify creation & destruction

    // 1- & 2-param ctor
    // _data is set to data (given). _next is set to next, if given, or
    // nullptr if not.
    // Pre:
    //     theNext, if passed, is either nullptr, or else it points to
    //      an LLNode2 allocated with new, with ownership transferred to
    //      *this.
    explicit LLNode2(const ValType & data,
                     std::unique_ptr<LLNode2> next = nullptr)// note that we don't want to convert often,but to a nullptr is fine.
        :_data(data),
         _next(next)
    {}

    // dctor
    // Does delete on _next.
    ~LLNode2()
    {
        while (? ? ? )
        {
            //through using this, we can go through and destroy as we walk through the list.
            //this means that 
            pop_front(_next); 
        }
    }

    // No default ctor, no copy/move operations.
    LLNode2() = delete;
    LLNode2(const LLNode2 & other) = delete;
    LLNode2 & operator=(const LLNode2 & other) = delete;
    LLNode2(LLNode2 && other) = delete;
    LLNode2 & operator=(LLNode2 && other) = delete;

};  // End struct LLNode2


// *********************************************************************
// struct LLNode2 - Associated global functions
// *********************************************************************


// size
// Given ptr to Linked List, return its size (number of nodes).
// Pre:
//     head is ptr to nullptr-terminated Linked List, or nullptr for
//      empty Linked List.
// Requirements on Types:
//     ValType must have a copy ctor and a (non-throwing) dctor.
// NOTE: The above are the requirements for LLNode2<ValType>; no member
// functions of ValType are actually used here.
template <typename ValType>
std::size_t size(const std::unique_ptr<LLNode2<ValType>> * head)
{
    //here is where we have a problem...cannot  do this with a unique pointer because its copying here.
    //note that we can add .get() since all we are trying to do is increment through a linked list
    auto p = head.get();            // Iterates through list
    std::size_t counter = 0;  // Number of nodes so far
    while (p != nullptr)
    {
        //note that .get() changes the type so we can get the values of a different pointer type since p here is a unique pointer. Thus no conversions
        p = p->_next.get();
        ++counter;
    }
    return counter;
}

//built in class
template <typename ValType>
void push_front(std::unique_ptr<LLNode2<ValType>>& head,
    const ValType& item)
{
    //this will create a node!
    head = std::make_unique<LLNode2<ValType>> (item, head)
}

//built in class
//Pre:
//      head is not null pointer!
template <typename ValType>
void pop_front(std::unique_ptr<LLNode2<ValType>>&head)
{
    //things that remove things from lists need to have preconditions
    auto savenext = std::move(head -> _next);

}



//notes from class:
// foo x --> std::unique_prt<Foo>


#endif  //#ifndef FILE_LLNODE2_HPP_INCLUDED

