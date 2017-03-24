
#ifndef MUSYS_CONVERTER_FUNCTION_HPP
#define MUSYS_CONVERTER_FUNCTION_HPP

#include <math.h>


namespace munits {

    class ConverterFunction {

        const double first_order;
        const double zero_order;
        const char *signature;
    public:
        explicit ConverterFunction(double, double, const char *);
//        explicit ConverterFunction(int, double, const char *);

        double to_base(double, double) const;

        double from_base(double, double) const;

        double getFirstOrderExponent(){
            return log10(first_order);
        }
    };
}

#endif //MUSYS_CONVERTER_FUNCTION_HPP
