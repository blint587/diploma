
#include <regex>
#include "parsers.hpp"
#include "unit_notation.hpp"

using namespace std;


munits::UnitNotation::UnitNotation(string u) {

    vector<string> parsed = munits::unparser(u);

    prefix = parsed[0];
    unit = parsed[1];
    int exp = atoi(parsed[2].c_str());
    exponent = exp != 0 ? exp : 1; //if atoi fails then the returned value is 0

}