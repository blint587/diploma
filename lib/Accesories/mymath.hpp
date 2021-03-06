
#ifndef SANDBOX_MATH_HPP
#define SANDBOX_MATH_HPP

#include <cmath>
#include <exception>

namespace mymath{

    unsigned long gcd(unsigned long u, unsigned long v);

    long double pow(int base, unsigned int exp);

    long double pow(int base, int exp);

    template <typename T> int sgn(T val) {
        return (T(0) < val) - (val < T(0));
    }

}

#endif //SANDBOX_MATH_HPP
