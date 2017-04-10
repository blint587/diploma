
#include "quantity.h"
#include <regex>
#include <list>
#include <cmath>
#include "parsers.hpp"
#include "unit_notation.hpp"
#include "uresolver.hpp"
#include "searchers.hpp"


using namespace std;


munits::UnitNotation::UnitNotation(string u) {

    vector<string> parsed = munits::unparser(u);

    prefix = parsed[0];
    unit = parsed[1];
    int exp = atoi(parsed[2].c_str());
    exponent = exp != 0 ? exp : 1; //if atoi fails then the returned value is 0

}

// TODO: search only those units which are related to the Unit type (based on dim vector)
vector<munits::UnitNotation> munits::UnitNotation::compose_unit_vector(const string &unit) {

    istringstream iss(unit);
    list<string> tokens;

    copy(istream_iterator<string>(iss), istream_iterator<string>(),
         back_inserter(tokens)); // splitting up string representations (by default at " ")

    const vector<munits::Metric> &rmatrix = GetMatrix();

    munits::Resolver r (rmatrix);

    r.resolve(tokens);


    list <munits::UnitNotation> unTokens (tokens.size()); // resizing to match

    // composing UnitNotation objects from string representations
    transform(tokens.begin(), tokens.end(), unTokens.begin(), [](string unt){return UnitNotation(unt);});


    vector<munits::UnitNotation> uv(7); // creating default 7 element long Unit vector

    for (int ui = 0; ui < 7; ++ui) { // checking if any of the tokens is a base Unit

        auto b = find_if(unTokens.begin(), unTokens.end(), [&rmatrix, &ui](munits::UnitNotation t)->bool { return rmatrix[ui].converter->is_valid_unit(t);});
        if (b != unTokens.end()) {
            uv[ui] = *b;
            unTokens.erase(b);
        }
    }
    if (unTokens.size() != 0) { // if no tokens left no point checking for none base units
        for (int uii = 7; uii < _Last; ++uii) {  // checking if any of the tokens is a none base Unit
            auto b = find_if(unTokens.begin(), unTokens.end(),
                             [&rmatrix, &uii](munits::UnitNotation t)->bool { return rmatrix[uii].converter->is_valid_unit(t); });
            if (b != unTokens.end()) {
                // searching the position where the dim_vector is not 0
                long long position = find_if(rmatrix[uii].dim_vector.begin(), rmatrix[uii].dim_vector.end(),
                                       [](int x) { return x != 0; }) - rmatrix[uii].dim_vector.begin();
                uv[position] = munits::UnitNotation(*b);
                unTokens.erase(b);
            }
        }
    }
    if (unTokens.size() != 0) { // if any tokens left it means that what was left is invalid.
        throw logic_error("Incorrect Unit: " + unit);
    };
    return uv;
}

bool munits::UnitNotation::divable(const munits::UnitNotation & lfths, const munits::UnitNotation & rgths) {
    return lfths.unit == rgths.unit && lfths.exponent == rgths.exponent;
}

double operator/ (const munits::UnitNotation & lfths, const munits::UnitNotation & rgths)
{
    if(munits::UnitNotation::divable(lfths, rgths)){
        double prx_lfths = munits::getExponentOfPrefix(lfths.GetPrefix());
        double prx_rgths = munits::getExponentOfPrefix(rgths.GetPrefix());
        return (prx_lfths - prx_rgths) * lfths.GetExponent();

    }else{
        throw std::logic_error("Unit notations cannot be dividedd!");
    }
}
