//intarray.hpp
//Lisa Jacklin
//2023-09-08
//header for class intarray

//this is a very bear bones way to write a RAII class

#ifndef FILE_INTARRAY_HPP_INCLUDED
#define FILE_INTARRAY_HPP_INCLUDED

#inlcude <csddef>
//for std:::size_t

class IntArray {
public:
	//these are to make it so only one item needs to be changed; DRY
	using size_type = std::size_t;
	using value_type = int;

	//note that the rule of 5 says to do something to the other 4 operators!
	intArray(std::size_t size)
	:_arrayptr = (new value_type[size])
	{	//_arrayptr = new int[size]; this is another way to write it as well}
	
	value_type & operator[] (size_type index)
		{ return _arrayptr[index]; }

	const value_type & operator[] (size_type index) const
		{ return _arrayptr[index]; }

	~IntArray()
	{	
		delete [] _arrayptr;;
	}

	IntArray(IntArray && other) = delete;
	IntArray(const IntArray & other) = delete;
	IntArray & operator = (const IntArray & other) = delete;
	IntArray & operator = (IntArray && other) = delete;
private:

	int * _arrayptr;//pointer ot our dynamic array of int


}; //end of class IntArray

#endif