
#ifndef MUSYS_ACCESORYS_HPP
#define MUSYS_ACCESORYS_HPP

#include <vector>
#include <iostream>

#ifdef DEBUG
    #include <iomanip>
    #define TRACE(x)  std::cerr << std::setprecision(18) << x << std::endl
#else
    #define TRACE(x)
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

    template<typename T>
    void print_vector(const std::vector<T> & a){
        for( auto b = a.begin(); b != a.end(); ++b ){
            std::cout << *b << std::endl;
        }

    }

}

#endif //MUSYS_ACCESORYS_HPP
