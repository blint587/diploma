#include "mymath.hpp"


unsigned long mymath::gcd(unsigned long u, unsigned long v ){
    while(v != 0){
        unsigned long r = u % v;
        u = v;
        v = r;
    }
    return u;
}

long double mymath::pow(int base, unsigned int exp){ // overflows
    if(exp != 0) {
        unsigned long long int result = 1;
        while (exp) {
            if (exp & 1)
                result *= base;
            exp >>= 1;
            base *= base;
        }
        return (long double) result;
    }else{
        return 1.0;
    }
}

long double mymath::pow(int base, int exp){
    bool sbit = std::signbit(exp);
    return sbit ? mymath::pow(base, (unsigned int) exp): 1./mymath::pow(base, (unsigned int) abs(exp));
}


