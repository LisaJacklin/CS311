// rpneval.hpp  UNFINISHED
// Glenn G. Chappell
// 2023-10-31
//
// For CS 311 Fall 2023
// Header for rpnEval: Reverse Polish Notation evaluation
// Example application of a Stack
// There is no associated source file.

#ifndef FILE_RPNEVAL_HPP_INCLUDED
#define FILE_RPNEVAL_HPP_INCLUDED

#include <string>
// For std::string
#include <stack>
// For std::stack
#include <cctype>
// For std::isdigit
#include <stdexcept>
//for std::domain_error


// Note on "inline"
//
// Marking a function "inline" makes it unavailable to the linker. Thus,
// defining the function in multiple source files does not violate the
// One Definition Rule. As a result, we may define the function in a
// header. If all functions in a header-source pair are inline, then no
// source file is needed.
//
// Member functions defined inside a class definition are implicitly
// inline. Global functions must be explicitly marked.


// isInteger
// Given a string, returns true if it represents an integer, that is, if
// it consists of one or more ASCII digits preceded by an optional sign
// ('+', '-').
// No-Throw Guarantee
inline
bool isInteger(const std::string & str) noexcept
{
    if (str.empty())
        return false;
    char c = str.front();
    if (!std::isdigit(c) && c != '+' && c != '-')
        return false;

    for (size_t i = 1; i < str.size(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }

    // Now either we have an integer, or we have "+" or "-"
    return std::isdigit(str.back());
}


// isBinop
// Given a string, returns true if it consists of a single arithmetic
// binary-operation character ('+', '-', '*', '/').
// No-Throw Guarantee
inline
bool isBinop(const std::string & str) noexcept
{
    if (str.size() != 1)
        return false;
    char c = str.front();
    return c == '+' || c == '-' || c == '*' || c == '/';
}


// rpnEval
// Do a single step in RPN expression evaluation.
// Given a stack<int> and a string, interpret the string as a command,
// and use it to operate on the stack.
//   c, C: clear stack.
//   <integer>: push value on stack.
//   +, -, *, /: binary arithmetic operator.
//     Operands taken from top 2 stack items; stack underflow throws.
//     "/" is integer division; x/0 throws.
//     Result is left in top item on stack.
//   Unknown command: throws.
// Basic Guarantee
inline
void rpnEval(std::stack<int> & s,
             const std::string & token)
{
    if (token == "c" || token == "C") {

        std::stack<int>().swap(s); //clears the value of s
        return;
    }

    if (isInteger(token)) {
        s.push(std::stoi(token));
        return;
    }

    //since we still need to write out the binary operators, this is a way to check beforewe get there
    if (!isBinop(token))
    {
        throw std::domain_error("unknown command: \"" + token + "\"");
    }

    //now for building the binary operators required for this!
    if (s.size() < 2)
    {
        //we have to have a size of atleast two to do any true operation within the stack
        throw std::out_of_range("Stack overflow in \"" + token + "\" operation");
    }

    //first we need to initialize two characters onto the stack that way we don't get a stack overflow error shown directly above
    int a = s.top();
    s.pop();
    int b = s.top();
    s.pop();

    if (token == "+")
        s.push(a + b);
    else if (token == "-")
        s.push(b - a);
    else if (token = "*")
        s.push(a * b);
    else //token == "\"
    {
        if (b == 0)
            throw std::overflow_error("Division by zero");
        else
            s.push(a / b);
    }
       
}


#endif  //#ifndef FILE_RPNEVAL_HPP_INCLUDED

