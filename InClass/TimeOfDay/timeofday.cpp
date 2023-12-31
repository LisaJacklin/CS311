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
#include <cassert>
//for assert

// getTime
 // Return hours, minutes, seconds in reference parameters.
 //note that this sort of definition should really be in the source file.
 //once again, this is the judgement call.
void TimeOfDay::getTime(int& hh, int& mm,  int& ss) const
{

    //to make sure that seconds cannot go past 24 hours in a day...only up to 23:59:59
    assert(0 <= _secs && _secs < 24 * 60 * 60);

    //this is where time is computed
    hh = _secs / (60 * 60); //if it fits within minutes and seconds
    mm = (_secs - hh * (60 * 60)) / 60; //seconds - total seconds in the hours in hh, divided by total seconds in minute
    ss = _secs % (24 * 60) - mm * (60); //the remainder is seconds from hours and minutes

}


// *********************************************************************
// class TimeOfDay - Definitions of associated global operators
// *********************************************************************


// operator<< (ostream,TimeOfDay)
ostream & operator<<(ostream & out,
                     const TimeOfDay & t)
{
    //to make sure that functions can't fix to much...
    assert(0 <= t._secs && t._secs < 24 * 60 * 60);

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

