
#ifndef MUSYS_CONVERTER_FUNCTION_HPP
#define MUSYS_CONVERTER_FUNCTION_HPP



namespace munits {

    class ConverterFunction {

        const int first_order_exponent;
        const double first_order;
        const double zero_order;
        const char *signature;
    public:
        explicit ConverterFunction(double, double, const char *);
        explicit ConverterFunction(int, double, const char *);

        double to_base(double, double) const;

        double from_base(double, double) const;

        int getFirstOrderExponent(){
            return this->first_order_exponent;
        }
    };
}

#endif //MUSYS_CONVERTER_FUNCTION_HPP
