
#include <queue>
#include <iostream>
#include "quantity.h"
#include <regex>
#include <list>
#include <cmath>
#include "unit_notation.hpp"
#include "parsers.hpp"
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

int munits::UnitNotation::div (const munits::UnitNotation & lfths, const munits::UnitNotation & rgths)
{
    if(munits::UnitNotation::divable(lfths, rgths)){
        double prx_lfths = munits::getExponentOfPrefix(lfths.GetPrefix());
        double prx_rgths = munits::getExponentOfPrefix(rgths.GetPrefix());
        return (int) ((prx_lfths - prx_rgths) * lfths.GetExponent());

    }else{
        throw std::logic_error("Unit notations cannot be dividedd!");
    }
}

string munits::UnitNotation::compose_unit(const vector<UnitNotation> & uns, const int midx) {
    
    auto metric = munits::GetMatrix()[midx];
    
    for(auto b = metric.unit_resolve_mapping.begin(); b != metric.unit_resolve_mapping.end(); b++){
        std::string master_unit = b->first;
        const auto master_vector = munits::UnitNotation::compose_unit_vector(master_unit);
        bool div = true;
    
        int prefix_exponent = 0;
    
        for (int idx = 0; idx < uns.size() && (div = munits::UnitNotation::divable(uns[idx], master_vector[idx])); idx++) {
            prefix_exponent +=  munits::UnitNotation::div(uns[idx], master_vector[idx]);
        }
        if (div) {
            auto prx =  getPrefixByExponent(prefix_exponent);
            return prx + master_unit;
        }
    }     
    stringstream tmp;
    for_each(uns.begin(), uns.end(), [&](const UnitNotation &unit) {
                 if (unit.GetUnit() != "") {
                     tmp << unit.GetPrefix() << unit.GetUnit()
                         << (unit.GetExponent() != 1 ? to_string(unit.GetExponent()) : "") << " ";
                 }
             }
    );

    string s = tmp.str();
    s.erase(s.find_last_not_of(" ") + 1); // right triming the string
    return s;
}