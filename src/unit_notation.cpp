
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

list <munits::UnitNotation> munits::UnitNotation::tokenise(const string &unit) {
    istringstream iss(unit);
    list<string> tokens;
    copy(istream_iterator<string>(iss), istream_iterator<string>(),
         back_inserter(tokens)); // splitting up string representations (by default at " ")
    TRACEITERABLE(tokens);

    const vector<munits::Metric> &rmatrix = munits::GetMatrix();

    munits::Resolver r (rmatrix);

    r.resolve(tokens);

    list <munits::UnitNotation> unTokens (tokens.size()); // resizing to match
    // composing UnitNotation objects from string representations
    transform(tokens.begin(), tokens.end(), unTokens.begin(), [](string unt){return munits::UnitNotation(unt);});
    TRACEITERABLE(unTokens);
    return unTokens;
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
        throw std::logic_error("Unit notations cannot be divided!");
    }
}

void munits::UnitNotationVector::set(long long int idx, const munits::UnitNotation & un) {
    if(unitnotations[idx] != munits::UnitNotationVector::npos()){
        vector<int> lft_vector (7);
        lft_vector[idx] = unitnotations[idx].GetExponent();
//        TRACEITERABLE(lft_vector);
        munits::Quantity lft(munits::getMetric(lft_vector) , 1., (std::string) unitnotations[idx]);

//        TRACE("Left side: " + (std::string) lft);

        vector<int> rgt_vector (7);
        rgt_vector[idx] = un.GetExponent();

        munits::Quantity rgt(munits::getMetric(rgt_vector) , 1., (std::string) un);

//        TRACE("Right side: " + (std::string) rgt);

        Quantity res = rgt * lft;

//        TRACE("Result: " + (std::string) res);

        mult_factor *= res.value;
        unitnotations[idx] = res.unit_vector[idx];


    }else{
        unitnotations[idx] = un;
    }

}

munits::UnitNotation & munits::UnitNotationVector::operator[](int idx) {
    return unitnotations[idx];
}

const munits::UnitNotation munits::UnitNotationVector::operator[](int idx)  const{
    return unitnotations[idx];
}

const  munits::UnitNotation & munits::UnitNotationVector::npos() {
    static munits::UnitNotation npos {};
    return npos;
}

// TODO: search only those units which are related to the Unit type (based on dim vector)
munits::UnitNotationVector munits::UnitNotationVector::compose_unit_vector(const string &unit) {

    auto  rmatrix = GetMatrix();
    TRACE(unit);
    list <UnitNotation> unTokens = UnitNotation::tokenise(unit);
    TRACEITERABLE(unTokens);

    UnitNotationVector uv;

    for (int uidx = 0; uidx < 7; ++uidx) { // checking if any of the tokens is a base Unit

        auto b = unTokens.begin();
        do { // pushing all the same dimension type units into uv, even if such type already exists
            b = find_if(b, unTokens.end(), [&rmatrix, &uidx](
                    UnitNotation t) -> bool { return rmatrix[uidx].converter->is_valid_unit(t); });
            if (b != unTokens.end()) {
                uv.set(uidx, *b);
                b = unTokens.erase(b);
            }
        }while(b != unTokens.end());
    }
    if (unTokens.size() != 0) { // if no tokens left no point checking for none base units
        for (int uidx = 7; uidx < _Last; ++uidx) {  // checking if any of the tokens is a none base Unit
            auto b = find_if(unTokens.begin(), unTokens.end(),
                             [&rmatrix, &uidx](UnitNotation t)->bool { return rmatrix[uidx].converter->is_valid_unit(t); });
            if (b != unTokens.end()) {
                // searching the position where the dim_vector is not 0
                long long position = find_if(rmatrix[uidx].dim_vector.begin(), rmatrix[uidx].dim_vector.end(),
                                       [](int x) { return x != 0; }) - rmatrix[uidx].dim_vector.begin();
                uv.set(position, UnitNotation(*b));
                unTokens.erase(b);
            }
        }
    }
    if (unTokens.size() != 0) { // if any tokens left it means that what was left is invalid.
        throw logic_error("Incorrect Unit: " + unit);
    };
    return uv;
}

string munits::UnitNotationVector::compose_unit(const munits::UnitNotationVector & uns, const int midx) {

    auto metric = GetMatrix()[midx];

    for(auto b = metric.unit_resolve_mapping.begin(); b != metric.unit_resolve_mapping.end(); b++){
        string master_unit = b->first;
        UnitNotationVector master_vector = UnitNotationVector::compose_unit_vector(master_unit);
        if(master_vector.getMultiplicationFactor() != 1.0){
            continue;
        }
        bool div = true;

        int prefix_exponent = 0;

        for (int idx = 0; idx < uns.size() && (div = UnitNotation::divable(uns[idx], master_vector[idx])); idx++) {
            prefix_exponent +=  UnitNotation::div(uns[idx], master_vector[idx]);
        }
        if (div) {
            auto prx =  getPrefixByExponent(prefix_exponent);
            if("None" != prx) {
                return prx + master_unit;
            }
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