
#include <regex>
#include "unit_notation.hpp"
#include "converter_function.hpp"
#include "unit.hpp"
#include "metric.hpp"
#include "dynamic.hpp"

using namespace std;

vector<string> munits::UnitNotation::parser(string unit) {
    const vector<munits::Metric> & rmatrix = munits::GetMatrix();
    vector<string> parsed = {"", "", ""};

    bool no_matc = true;

    for(int u = 0; u < munits::_Last && no_matc; ++u) {
        stringstream rp;
        { // composing the regex for each Unit type
            rp << "^(";
            const map<string, const shared_ptr<ConverterFunction>> &prefixes = rmatrix[u].converter->Prefixes();
            int c1 = 0;
            for (auto prx = prefixes.begin(); prx != prefixes.end(); ++prx) {
                rp << prx->first << (c1 != prefixes.size() - 1 ? "|" : "");
                ++c1;
            }

            rp << ")?(";
            c1 = 0;
            const map<string, const shared_ptr<munits::Unit>> &units = rmatrix[u].converter->Units();
            for (auto unt = units.begin(); unt != units.end(); ++unt) {
                rp << unt->first << (c1 != units.size() - 1 ? "|" : "");
                ++c1;
            }

            rp << ")(\\-?[0-9])?$";
        }
        try {
            regex re(rp.str());
            sregex_iterator next(unit.begin(), unit.end(), re);
            sregex_iterator end;
            while (next != end) {
                smatch match = *next;

                if(string(match[1])+string(match[2])+string(match[3]) == unit){
                    no_matc = false;
                    parsed[0] = match[1];
                    parsed[1] = match[2];
                    parsed[2] = match[3];
                }
                next++;
            }
        }
        catch (regex_error &e) {

        }
    }

    return parsed;
}


munits::UnitNotation::UnitNotation(string u) {

    vector<string> parsed = parser(u);

    prefix = parsed[0];
    unit = parsed[1];
    int exp = atoi(parsed[2].c_str());
    exponent = exp != 0 ? exp : 1; //if atoi fails then the returned value is 0

}