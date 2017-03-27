
#include <algorithm>
#include <stdexcept>
#include "searchers.hpp"
#include "dynamic.hpp"
#include "metric.hpp"

const long long int  munits::getMatrixIndex(const std::vector<int> &searched){

    auto rmatrix = munits::GetMatrix();
    return std::find_if(rmatrix.begin(), rmatrix.end(), [&](munits::Metric x) { return x.dim_vector == searched; }) - rmatrix.begin();

}

const double munits::getExponentOfPrefix(const std::string prefix) {
    auto prefixes = munits::GetPrefixes();
    auto prx = prefixes.find(prefix);
    if(prx != prefixes.end()) {
        return prx->second->getFirstOrderExponent();
    }else{
        throw std::logic_error(std::string("No such prefix as ") + prefix);
    }

}

const std::string munits::getPrefixByExponent(const int exponent) {
    auto prefixes = munits::GetPrefixes();
    std::string prx = "None";
    for(auto conf :  prefixes){
        if(exponent == conf.second->getFirstOrderExponent()){
            prx = conf.first;
        }
    }
    return prx;
    
}
