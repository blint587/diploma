#ifndef MUSYS_UNIT_HPP
#define MUSYS_UNIT_HPP


#include <string>
#include "converter_function.hpp"

namespace munits {

    class Unit : public munits::ConverterFunction {

    public:
        const bool applay_prefix;
        const int ignor_exponent;
        const double zero_order;

        explicit Unit(double a = 1, double b = 0, bool applay_prefix = true, int ignor_exponent = 0) :
                ConverterFunction(a), applay_prefix(applay_prefix),
                ignor_exponent(ignor_exponent), zero_order(b) {
        }
         double to_base(double, double) const;
         double from_base(double, double) const;

    private:
        // disabling irrelevant function
        double getFirstOrderExponent() const{return 0;};
    };
}

#endif //MUSYS_UNIT_HPP
