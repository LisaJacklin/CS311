// timeofday.hpp  UNFINISHED
// Glenn G. Chappell adjusted by Lisa Jacklin
// 2023-09-01
//
// For CS 311 Fall 2023
// Header for class TimeOfDay
// Time of day: hours, minutes, seconds

#ifndef FILE_TIMEOFDAY_HPP_INCLUDED
#define FILE_TIMEOFDAY_HPP_INCLUDED

#include <ostream>
// For std::ostream


// *********************************************************************
// class TimeOfDay - Class definition
// *********************************************************************


// class TimeOfDay
// Time of day: hours, minutes, seconds.
class TimeOfDay {

// ***** TimeOfDay: Ctors, dctor, op= *****
public:

    // Default ctor
    // Set time to midnight.
    TimeOfDay()
       // :_secs(0)
    {
        setTime(0, 0, 0): //this is a jugement call where you use this, or :_secs(0)....
        //although there is no real difference between these two, :_secs(0) means all other operations are reliant on this single value
        //which is the case in setTime but why not use it since we built it.
    }

    // Ctor from hours, minutes, seconds
    // Set time to given # of hours, minutes, seconds past midnight.
    TimeOfDay(int hh,
              int mm,
              int ss)
    {
        setTime(hh, mm, ss);

    }

// ***** TimeOfDay: General public operators *****
public:

    // op++ [pre]
    // Move time one second forward.
    TimeOfDay & operator++()
    {
        ++_secs;
        _secs %= 24*60*60; //this gives the number of seconds in a day
        return *this;
    }

    // op++ [post]
    // Move time one second forward.
    //within two sets or brackets is an attribute
    //the point of this double bracket attribute is to avoid warnings
    TimeOfDay operator++([[maybe_unused]] int dummy)
    {
        auto save = *this;
        ++(*this);
        return save;
    }

    // op-- [pre]
    // Move time one second backward.
    TimeOfDay & operator--()
    {
        --_secs;
        if (_secs == -1)
            _secs = 24*60*60-1;
        return *this;
    }

    // op-- [post]
    // Move time one second backward.
    TimeOfDay operator--([[maybe_unused]] int dummy)
    {
        auto save = *this;
        --(*this);
        return save;
    }

// ***** TimeOfDay: General public functions *****
public:

 

    // setTime
    // Set time to given # of hours, minutes, seconds past midnight.
    void setTime(int hh,
                 int mm,
                 int ss)
    {
        _secs = 60 * 60 * hh + 60 * mm + ss;
        //note this will work so long as values are within range, thus we need to make sure we add asserts to 
        //make sure that this will not happen.

    }

// ***** TimeOfDay: Data members *****
private:

    int _secs;  // Seconds past midnight (range 0 .. 24*60*60-1)

};  // End class TimeOfDay


// *********************************************************************
// class TimeOfDay - Declarations of associated global operators
// *********************************************************************


// operator<< (ostream,TimeOfDay)
// Prints given TimeOfDay object as "hh:mm:ss", with hh padded on the
// left with blanks, and mm, ss padded on the left with zeroes.
// Function defined in source file.
std::ostream & operator<<(std::ostream & out,
                          const TimeOfDay & t);


#endif  //#ifndef FILE_TIMEOFDAY_HPP_INCLUDED

