#include <algorithm>
#include "converter_function.hpp"

munits::ConverterFunction::ConverterFunction(double a, double b=0, const char* s ="Default"): first_order(a), zero_order(b), signature(s){}

double  munits::ConverterFunction::to_base(double v, double e=1) const {
    return (v * std::pow(first_order, e)) + (e==1?(zero_order * first_order):0);
}

double munits::ConverterFunction::from_base(double v, double e = 1) const {
    return (v * std::pow(first_order, -e)) - (e==1?(zero_order):0);
}