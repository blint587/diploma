#ifndef MUSYS_UNIT_HPP
#define MUSYS_UNIT_HPP


#include "converter_function.hpp"
namespace munits {

    class Unit : public munits::ConverterFunction {

    public:
        //        const std::string Unit;
        const bool applay_prefix;
        const bool ignor_exponent;

        explicit Unit(double a = 1, double b = 0, const char *s = "Default",  /*std::string Unit,*/
                      bool applay_prefix = true, bool ignor_exponent = false) :
                ConverterFunction(a, b, s), /* Unit(Unit),*/ applay_prefix(applay_prefix),
                ignor_exponent(ignor_exponent) {
        }
    };
}

#endif //MUSYS_UNIT_HPP
