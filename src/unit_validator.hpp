//
// Created by bmolnar on 2019. 11. 19..
//

#ifndef MUNITS_UNIT_VALIDATOR_HPP
#define MUNITS_UNIT_VALIDATOR_HPP

#include "unit_notation.hpp"
#include "dynamic.hpp"

namespace munits {

    bool validate_unit(const munits::UnitNotationVector &, munits::metrics);

    int extrapolate_metric_from_unit(const munits::UnitNotationVector &);

    int extrapolate_metric_from_unit(const std::string &);


}

#endif //MUNITS_UNIT_VALIDATOR_HPP
