// timeofday.cpp  UNFINISHED
// Glenn G. Chappell
// 2023-09-01
//
// For CS 311 Fall 2023
// Source for class TimeOfDay
// Time of day: hours, minutes, seconds

#include "timeofday.hpp"
// For class TimeOfDay
#include <ostream>
using std::ostream;


// *********************************************************************
// class TimeOfDay - Definitions of associated global operators
// *********************************************************************


// operator<< (ostream,TimeOfDay)
ostream & operator<<(ostream & out,
                     const TimeOfDay & t)
{
    int hh, mm, ss;//first we need to pull the integers
    t.getTime(hh, mm, ss); //now to plug them into the function built in the .hpp file
    //in order to add in an easy blank to the front of, this what you do
    if (hh < 10)
        out << " ";
    out << hh << ":";
    if (mm < 10)
        out << " ";
    out << mm << ":";
    if (ss < 10)
        out << " ";
    out << ss;

    
    return out;
}

