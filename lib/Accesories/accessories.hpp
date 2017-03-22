
#ifndef MUSYS_ACCESORYS_HPP
#define MUSYS_ACCESORYS_HPP

#include <vector>
#include <iostream>

#ifdef DEBUG
    #include <iomanip>
    #define TRACE(x)  std::cerr << std::setprecision(18) << x << std::endl
    #define TRACEVITERABLE(x) accessories::print_iterable(x)
#else
    #define TRACE(x)
    #define TRACEVECTOR(x)

#endif


namespace accessories{

    template<class T>
    bool lt(const T & a, const T & b){return a < b;}

    template<class T>
    bool le(const T & a, const T & b){return a <= b;}

    template<class T>
    bool gt(const T & a, const T & b){return a > b;}

    template<class T>
    bool ge(const T & a, const T & b){return a >= b;}

    template<class T>
    bool eq(const T & a, const T & b){return a == b;}

    template<class T>
    bool ne(const T & a, const T & b){return a != b;}

    template<class C>
    void print_iterable(const C &a){
        std::cerr << "[ ";
        for( auto b = a.begin(); b != a.end(); ++b ){
            std::cerr << *b << ", ";
        }
        std::cerr << "]" << std::endl;

    }


}

#endif //MUSYS_ACCESORYS_HPP
