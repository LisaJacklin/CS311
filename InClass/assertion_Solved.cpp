// assertion.cpp  Finished
//Adjusted and Finished by Lisa Jacklin
// Glenn G. Chappell
// 2023-08-30
// Demo of assert in C++

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;

#include <cassert> //required to use assert

// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// sumTwo
// Takes a vector of ints and two indices. Returns the sum of the items
// with those indices.
int sumTwo(const vector<int> & v,
           size_t idx1,
           size_t idx2)
{
    //this needs to be adjusted because what currently becomes the output is 
    // undefined behavior

    //these two are here to make sure that a bug is caught! if either of these values are false this don't work!
    assert(idx1 < v.size()); 
    assert(idx2 < v.size());

    return v[idx1] + v[idx2];
}


// Main program
// Call function sumTwo a couple of times.
int main()
{
    // Data to use for sumTwo calls
    vector<int> data { 4, 5, 9, 2, 8, 3, 11 };

    // Try sumTwo calls - one with an index out of range
    cout << "Sum #1: " << sumTwo(data, 0, 2) << endl;    // Okay
    cout << "Sum #2: " << sumTwo(data, 0, 999) << endl;  // BAD!!!
    //the 999 is what causes idx2 to crash!
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    userPause();
}
