

#ifndef MUSYS_SEARCHERS_HPP
#define MUSYS_SEARCHERS_HPP

#include <vector>
#include <string>
#include "dynamic.hpp"

namespace munits{

    const long long int getMatrixIndex(const std::vector<int> &searched);

    const double  getExponentOfPrefix(const std::string prefix);

    const std::string getPrefixByExponent(int exponent);

    const int getMaxPrefixExponent();

    const int getMinPrefixExponent();

    const metrics getMetric(const std::vector<int> &searched);

}


#endif //MUSYS_SEARCHERS_HPP
