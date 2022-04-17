#include "unit.hpp"


double munits::Unit::to_base(double v, double e=1) const {
    return ConverterFunction::to_base(v, e) + (e==1?(zero_order * first_order):0);
}

double munits::Unit::from_base(double v, double e = 1) const {
    return ConverterFunction::from_base(v, e) - (e==1?(zero_order):0);
}

