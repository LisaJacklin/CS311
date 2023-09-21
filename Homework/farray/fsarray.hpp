//farray.hpp
//Lisa Jacklin
//2023/09/14

#ifndef FILE_FSARRAY_HPP_INCLUDED
#define FILE_FSARRAY_HPP_INCLUDED

template<typename data_T> //this is what will change the class below
class FSArray {
public:
	//----------------------------------------------------
	//public member types! used for variables later
	using value_type = data_T;
	using size_type = std::size_t;

	//----------------------------------------------------
	//Class Constructors
	FSArray():_size(8), _data(new value_type[_size]) {} 
	//this needs object of size 8.


	//----------------------------------------------------
	//parameter constructors

	//1 parameter non negative int for values in array
	FSArray(int & arraySize) 
	:_size(size), _data(new value_type[_size]) {}

	//2 parameter, nonnegav int items in array, item of value type.
	//all items in array set to this value
	FSArray(int& arraySize, const value_type& value) 
	:size(_size), _data(new value_type[_size]) {} //need to include data type!


	//----------------------------------------------------
	// Class Member Functions
	//returns number of items in array
	size_type size() const {
		return _size;
		}; 
	
	data_T* begin() {
		return _data;
		}; //return address of item 0 (think iterator)

	//need to remember to add in begin() const!
	const data_T* begin() const {
		return _data;
	};
	// returns address of item one past end of array 
	data_T* end() {
		return _data + _size;
	}; 

	//end const required!
	const data_T* end() const {
		return _data + _size;
	};


	//deconstructor
	~FSArray() {
		delete[] _data;
	}; //frees any dynamically allocated memory

	//----------------------------------------------------
	//Class operators
	FSArray operator==();
	
	FSArray operator!=();

	FSArray operator<();

	FSArray operator<=(const FSArray& other) const {
		return (*this < other) || (*this == other);
	}

	FSArray operator>(const FSArray& other) const {
		return !(*this <= other);
	}

	FSArray operator>=(const FSArray& other) const {
		return !(*this < other);
	}
	//----------------------------------------------------
	//Class Member Types
private:

	size_type _size;//size_type

	data_T* _data;//size_type

}; //end of class FSArray


#endif