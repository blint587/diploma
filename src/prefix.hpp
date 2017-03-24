
#ifndef SANDBOX_PREFIX_HPP
#define SANDBOX_PREFIX_HPP

#include <string>
#include "converter_function.hpp"

namespace munits {
    class Prefix {

    private:
        const std::string notation;
        const munits::ConverterFunction converter;
        const int exponent;

    public:
        Prefix(std::string n, munits::ConverterFunction cf, int exp = 1): notation(n), converter(cf), exponent(exp){}

        friend Prefix operator+ (Prefix a, Prefix b){}
        friend std::ostream& operator<< (std::ostream& str, const Prefix & a){str << a.notation << std::string(" ") <<  std::to_string(a.exponent); return str;};

    };
}


#endif //SANDBOX_PREFIX_HPP
