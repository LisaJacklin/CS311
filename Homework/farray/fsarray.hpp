//farray.hpp
//Lisa Jacklin
//2023/09/14

#ifndef FILE_FSARRAY_HPP_INCLUDED
#define FILE_FSARRAY_HPP_INCLUDED

template<>; //this is what will change the class below
class FSArray {

	//----------------------------------------------------
	//Class Constructors
	FSArray() {}; //this needs object of size 8.

	~FSArray() {}; //frees any dynamically allocated memory

	//copy operators create entirely new copy of data, 
	//modifying the copy doesn't change the original!

	//view invisible functions II for all member functions...


	//----------------------------------------------------
	//parameter constructors

	//1 parameter non negative int for values in array
	FSArray(int & arraySize) {};

	//2 parameter, nonnegav int items in array, item of value type.
	//all items in array set to this value
	FSArray(int& arraySize) {}; //need to include data type!


	//----------------------------------------------------
	// Class Member Functions

	void size() {}; //returns number of items in array
	
	void begin() {}; //return address of item 0 (think iterator)

	void end() {}; // returns address of item one past end of array (think iterator)


	//----------------------------------------------------
	//Class operators
	FSArray operator==();
	
	FSArray operator!=();

	FSArray operator<();

	FSArray operator<=();

	FSArray operator>();

	FSArray operator>=();

	//----------------------------------------------------
	//Class Member Types

	//value_type

	//size_type

}; //end of class FSArray


#endif