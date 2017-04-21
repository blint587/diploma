#ifndef MUSYS_METRIC_HPP
#define MUSYS_METRIC_HPP

#include <vector>
#include <string>
#include <memory>
#include <set>
#include <map>

#include "unit.hpp"
#include "converter.hpp"

namespace munits {

    struct Metric {
        const std::vector<int> dim_vector;
        const std::shared_ptr <munits::Converter> converter;
        const std::map<const std::string, const std::string> unit_resolve_mapping;

        Metric(std::vector<int>, // cannot be explicit due to use of initializer list in GetMatrix
               std::string = "",
               std::set <std::string> = std::set<std::string>(),
               const std::map<std::string, const std::shared_ptr <munits::Unit>> = std::map<std::string, const std::shared_ptr <munits::Unit>>(),
               const std::map<const std::string, const std::string> = std::map<const std::string, const std::string>());

    };
}

#endif //MUSYS_METRIC_HPP
