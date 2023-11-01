// timeofday.cpp
// Glenn G. Chappell
// Started: 2023-09-01
// Updated: 2023-09-06
//
// For CS 311 Fall 2023
// Source for class TimeOfDay
// Time of day: hours, minutes, seconds

#include "timeofday.hpp"
// For class TimeOfDay
#include <ostream>
using std::ostream;
#include <cassert>
// For assert


// *********************************************************************
// class TimeOfDay - Definitions of member functions
// *********************************************************************


// TimeOfDay::getTime
void TimeOfDay::getTime(int & hh,
                        int & mm,
                        int & ss) const
{
    assert(0 <= _secs && _secs < 24*60*60); //this needs to be here because time doesn't go past this value, this is when time continues back from zero again.

    ss = _secs % 60; //consider the % here, this is the modulo sign in cpp. This means that the remainer is what is given! 
    mm = (_secs / 60) % 60;
    hh = _secs / (60*60);
}

// TimeOfDay::setTime
void TimeOfDay::setTime(int hh,
                        int mm,
                        int ss)
{
    assert(0 <= hh && hh < 24); //take a look at how these asserts are used...
    assert(0 <= mm && mm < 60);//each on here goes thorough making sure we get real values for hours, minutes, and seconds
    assert(0 <= ss && ss < 60);//as each is limited between 0 and 24 or 0 and 60.

    _secs = hh*(60*60) + mm*60 + ss;
}


// *********************************************************************
// class TimeOfDay - Definitions of associated global operators
// *********************************************************************


// operator<< (ostream,TimeOfDay)
ostream & operator<<(ostream & str,
                     const TimeOfDay & obj)
{
    assert(0 <= obj._secs && obj._secs < 24*60*60); //notice the obj. This is the constant reference of TimeofDay above
    //that means that each of these pieces are being checked that they are true before getting to pulling the data from the function and 
    //before performing the operation.

    int hh, mm, ss;
    obj.getTime(hh, mm, ss);

    //notice how the code below here is to pad with zeros. This is just like taking a signal and padding it with zeros ie. zeros[1, N]

    if (hh < 10)  // Left-pad with blank
        str << " ";
    str << hh << ":";

    if (mm < 10)  // Left-pad with zero
        str << "0";
    str << mm << ":";

    if (ss < 10)  // Left-pad with zero
        str << "0";
    str << ss;

    return str;
}

