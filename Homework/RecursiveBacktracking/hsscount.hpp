//hsscount.hpp
//Lisa Jacklin
//10/2/2023

#ifndef HSSCOUNT_HPP_INCLUDED
#define HSSCOUNT_HPP_INCLUDED

//when considering a board of n size. Note that we are using this to call 
//hssCount_resurse
int hssCount(int dim_x, int dim_y,
             int hole_x, int hole_y,
             int start_x, int start_y,
             int finish_x, int finish_y);

/*
dim_x, dim_y:  dimensions of the board in x and y
hole_x, hole_y: cordinates of the hole
*/

#endif // HSSCOUNT_HPP_INCLUDED
