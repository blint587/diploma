#include "rresolver.hpp"
#include <string>
#include <vector>
#include "unit_notation.hpp"

using namespace std;


string munits::RResolver::resolve(const munits::metrics midx, const vector<munits::UnitNotation> uns) const {

    // function expects that the unit notation matches the matrix index

    std::string master_unit = munits::GetMatrix()[midx].unit_resolve_mapping.begin()->second;
    auto master_vector = munits::UnitNotation::compose_unit_vector(master_unit);
    bool div = true;

    int prefix_exponent = 0;

//    for(int idx = 0; idx < uns.size() && div; idx++){
//         uns[idx] / master_vector[idx]
//
//
//
//
//    }






    return string("");
}
