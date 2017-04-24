#ifndef MUSYS_UNIT_HPP
#define MUSYS_UNIT_HPP


#include <string>
#include "converter_function.hpp"

namespace munits {

    class Unit : public munits::ConverterFunction {

    public:
        const std::string unit;
        const bool applay_prefix;
        const bool ignor_exponent;
        const double zero_order;

        explicit Unit(double a = 1, double b = 0, const char *s = "Default",  /*std::string Unit,*/
                      bool applay_prefix = true, bool ignor_exponent = false) :
                ConverterFunction(a), /* Unit(Unit),*/ applay_prefix(applay_prefix),
                ignor_exponent(ignor_exponent), unit(s), zero_order(b) {
        }
         double to_base(double, double) const;
         double from_base(double, double) const;

    private:
        // disabling irrelevant function
        double getFirstOrderExponent() const{return 0;};
    };
}

#endif //MUSYS_UNIT_HPP
