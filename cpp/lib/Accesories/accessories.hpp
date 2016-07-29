
#ifndef MUSYS_ACCESORYS_HPP
#define MUSYS_ACCESORYS_HPP

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

}

#endif //MUSYS_ACCESORYS_HPP
