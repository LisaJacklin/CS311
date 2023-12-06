// squarer.h - Correct version
// A simple class to square numeric values

#ifndef SQUARER_H
#define SQUARER_H

class Squarer {
public:
    // Function call operator to square a numeric value
    template<typename T>
    T operator()(const T & value) const {
        return value * value;
    }
};

#endif // SQUARER_H
