#include "da3.hpp"

void didItThrow(const std::function<void()>& ff, bool& threw) {
    threw = false;
    try {
        ff();
    } catch (...) {
        threw = true;
        throw;
    }
}

namespace {
    int gcdRecursive(int a, int b) {
        if (b == 0) return a;
        return gcdRecursive(b, a % b);
    }
}

int gcd(int a, int b) {
    return gcdRecursive(a, b);
}
