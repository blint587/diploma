#include "Quantity.h"


quantity::Quantity::Quantity(quantity::metrics m, double value, const char *unit):matrix_index(m),
                                                                                  value(value),
                                                                                  unit(unit),
                                                                                  converter(quantity::matrix[m].base_unit,
                                                                                            quantity::matrix[m].remove,
                                                                                  quantity::matrix[m].additional_units) {

}

double quantity::Quantity::operator()(const std::string tunit) const {
    if (converter.is_valid_unit(tunit)) {
        return converter(value, unit, tunit);
    }
    else{
        throw "invalid Unit";
    }

}

bool quantity::Quantity::is_valid_unit() const {
    return converter.is_valid_unit(unit);
}







