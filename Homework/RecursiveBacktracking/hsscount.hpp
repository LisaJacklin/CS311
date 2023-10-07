//hsscount.hpp
//Lisa Jacklin
//10/2/2023

#ifndef HSSCOUNT_HPP_INCLUDED
#define HSSCOUNT_HPP_INCLUDED

//when considering a board of n size. Note that we are using this to call 
//hssCoutn_resurse
int hssCount(int dim_x, int dim_y,
    int hole_x, int hole_y,
    int start_x, int start_y,
    int finish_x, int finish_y);

#endif // HSSCOUNT_HPP_INCLUDED
