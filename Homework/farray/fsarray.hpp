//farray.hpp
//Lisa Jacklin
//2023/09/14


#ifndef FILE_FSARRAY_HPP_INCLUDED
#define FILE_FSARRAY_HPP_INCLUDED

#include <algorithm> //for std::copy, std::equal
#include <cstddef> //for std::size_t

template<typename data_T> //this is what will change the class below
class FSArray {
public:
	//----------------------------------------------------
	//public member types! used for variables later
	using value_type = data_T;
	using size_type = std::size_t;

	//----------------------------------------------------
	//Class Constructors
	//this only takes objects of size 8
	FSArray()
		:_data(new data_T[8]), _size(8) {} 

	//now for any value of size n, an explicit constructor is required
	explicit FSArray(size_type n)
		:_data(new data_T[n]()), _size(n) {}

	FSArray(size_type n, const T& val) 
		: _data(new data_T[n]), _size(n) 
		{
			std::fill(_data, _data + _size, val);
		}

	//deconstructor
	~FSArray() {
		delete[] _data;
	}; //frees any dynamically allocated memory


	//----------------------------------------------------
	//parameter constructors

	//1 parameter non negative int for values in array
	FSArray(int & arraySize) 
	:_size(size), _data(new value_type[_size]) {}

	//2 parameter, nonnegav int items in array, item of value type.
	//all items in array set to this value
	FSArray(int& arraySize, const value_type& value) 
	:size(_size), _data(new value_type[_size]) {} //need to include data type!


	//copy constructor
	FSArray(const FSArray& other) 
		:_size(other._size), _data(new data_T[other._size]) 
		{// note that std::copy is required here!
		std::copy(other._data, other._data + other._size, _data);
		}

	//move constructor
	FSArray(FSArray&& other) noexcept 
		:_size(other._size), _data(other._data)
		{
			other._size = 0;
			other._data = nullptr;
		}

	//copy assignment
	FSArray& operator=(const FSArray& other) {
		if (this != &other) {
			delete[] _data;
			_size_ = other._size;
			_data = new value_type[_size];
			copyFrom(other);
		}
		return *this;
	}

	// Move assignment
	FSArray& operator=(FSArray&& other) noexcept {
		if (this != &other) {
			delete[] _data;
			_size = other._size;
			_data = other._data;
			other._size = 0;
			other._data = nullptr;
		}
		return *this;
	}

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

	//----------------------------------------------------
	//Class operators

	// Bracket operators
	value_type& operator[](size_type index) {
		if (index >= _size) {
			throw std::out_of_range("Index out of range");
		}
		return data_[index];
	}

	const value_type& operator[](size_type index) const {
		if (index >= _size) {
			throw std::out_of_range("Index out of range");
		}
		return data_[index];
	}

	// comparison operators for FSArray
	bool operator==(const FSArray& other) const {
		if (_size != other._size) {
			return false;
		}
		for (size_type i = 0; i < _size; ++i) {
			if (data_[i] != other._data[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator!=(const FSArray& other) const {
		return !(*this == other);
	}

	bool operator<(const FSArray& other) const {
		for (size_type i = 0; i < _size; ++i) {
			if (_data[i] < other._data[i]) {
				return true;
			}
			if (_data[i] > other._data[i]) {
				return false;
			}
		}
		return false;
	}

	bool operator<=(const FSArray& other) const {
		return (*this == other) || (*this < other);
	}

	bool operator>(const FSArray& other) const {
		return !(*this <= other);
	}

	bool operator>=(const FSArray& other) const {
		return !(*this < other);
	}
	//----------------------------------------------------
	//Class Member Types
private:

	size_type _size;//size_type

	data_T* _data;//size_type

}; //end of class FSArray


#endif