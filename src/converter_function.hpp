
#ifndef MUSYS_CONVERTER_FUNCTION_HPP
#define MUSYS_CONVERTER_FUNCTION_HPP

#include <math.h>


namespace munits {

    class ConverterFunction {

    protected:
        const double first_order;

    public:
        /**
         * Constructor for converter function
         * @param a: first order parameter
         * @param b: zero order parameter
         * @param signature of the converter function (e.g. k)
         *
         * y = ax + b
         */
        explicit ConverterFunction(double);

        /**
         * @param v: value to be converted to base
         * @param e: exponent
         *
         *  (v * first_order^e) + (e==1?(zero_order * first_order):0)
         *
         * @return value converted to base function
         */
        virtual double to_base(double, double) const;

        /**
         * @param v: value in base to target
         * @param e: exponent
         *
         *  (v * std::pow(first_order, -e)) - (e==1?(zero_order):0)
         *
         * @return value converted to base function
         */
        virtual double from_base(double, double) const;

        virtual double getFirstOrderExponent() const{
            return log10(first_order);
        }
        ~ConverterFunction(){};
    };
}

#endif //MUSYS_CONVERTER_FUNCTION_HPP
