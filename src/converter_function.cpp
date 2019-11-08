#include <algorithm>
#include "converter_function.hpp"
#include "../lib/Accesories/accessories.hpp"
#include <math.h>

munits::ConverterFunction::ConverterFunction(double a): first_order(a){}

double  munits::ConverterFunction::to_base(double v, double e=1) const {
//    return (v * std::mpow(first_order, e)) + (e==1?(zero_order * first_order):0);
    return (v * std::pow(first_order, e));
}

double munits::ConverterFunction::from_base(double v, double e = 1) const {
//    return (v * std::mpow(first_order, -e)) - (e==1?(zero_order):0);
    return (v * std::pow(first_order, -e));
}

