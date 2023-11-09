//chatgpt code help
//2023.19.09


#ifndef FSARRAY_HPP
#define FSARRAY_HPP

template <typename T>
class FSArray {
public:
    // Member types
    using value_type = T;
    using size_type = std::size_t; // You can use std::size_t for size_type

    // Constructors
    FSArray() : size_(8), data_(new T[8]()) {} // Default ctor
    explicit FSArray(size_type size) : size_(size), data_(new T[size]()) {} // 1-parameter ctor
    FSArray(size_type size, const T& value) : size_(size), data_(new T[size]) { // 2-parameter ctor
        for (size_type i = 0; i < size_; ++i) {
            data_[i] = value;
        }
    }

    // Destructor
    ~FSArray() {
        delete[] data_;
    }

    // Copy constructor
    FSArray(const FSArray& other) : size_(other.size_), data_(new T[other.size_]) {
        for (size_type i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    // Copy assignment operator
    FSArray& operator=(const FSArray& other) {
        if (this != &other) {
            FSArray tmp(other);
            swap(tmp);
        }
        return *this;
    }

    // Move constructor
    FSArray(FSArray&& other) noexcept : size_(other.size_), data_(other.data_) {
        other.size_ = 0;
        other.data_ = nullptr;
    }

    // Move assignment operator
    FSArray& operator=(FSArray&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            data_ = other.data_;
            other.size_ = 0;
            other.data_ = nullptr;
        }
        return *this;
    }

    // Bracket operator
    T& operator[](size_type index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index];
    }

    const T& operator[](size_type index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index];
    }

    // Member functions
    size_type size() const {
        return size_;
    }

    T* begin() {
        return data_;
    }

    const T* begin() const {
        return data_;
    }

    T* end() {
        return data_ + size_;
    }

    const T* end() const {
        return data_ + size_;
    }

    // Comparison operators
    bool operator==(const FSArray& other) const {
        if (size_ != other.size_) {
            return false;
        }
        for (size_type i = 0; i < size_; ++i) {
            if (data_[i] != other.data_[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const FSArray& other) const {
        return !(*this == other);
    }

    bool operator<(const FSArray& other) const {
        for (size_type i = 0; i < size_; ++i) {
            if (data_[i] < other.data_[i]) {
                return true;
            } else if (data_[i] > other.data_[i]) {
                return false;
            }
        }
        return false;
    }

    bool operator<=(const FSArray& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>(const FSArray& other) const {
        return !(*this <= other);
    }

    bool operator>=(const FSArray& other) const {
        return !(*this < other);
    }

    // Swap function for use in copy assignment operator and move constructor
    void swap(FSArray& other) {
        std::swap(size_, other.size_);
        std::swap(data_, other.data_);
    }

private:
    size_type size_;
    T* data_;
};

#endif // FSARRAY_HPP
