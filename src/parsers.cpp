#include "parsers.hpp"
#include "converter_function.hpp"
#include <string>
#include <vector>
#include <regex>
#include <memory>
#include <map>
#include <sstream>
#include "metric.hpp"
#include "dynamic.hpp"

using namespace std;

vector<string> munits::unparser(string unit) {
//    TRACEWHAT(unit, "Unit passed to unpatser:");
    const vector<munits::Metric> &rmatrix = munits::GetMatrix();
    vector<string> parsed = {"", "", ""};

    bool no_match = true;

    for (int u = 0; u < munits::_Last && no_match; ++u) {
//        stringstream rp;
//        { // composing the regex for each Unit type
//            rp << "^(";
//            const map<string, const shared_ptr<munits::ConverterFunction>> &prefixes = rmatrix[u].converter->Prefixes();
//            int c1 = 0;
//            for (auto prx = prefixes.begin(); prx != prefixes.end(); ++prx) {
//                rp << prx->first << (c1 != prefixes.size() - 1 ? "|" : "");
//                ++c1;
//            }
//
//            rp << ")?(";
//            c1 = 0;
//            const map<string, const shared_ptr<munits::Unit>> &units = rmatrix[u].converter->Units();
//            for (auto unt = units.begin(); unt != units.end(); ++unt) {
//                rp << unt->first << (c1 != units.size() - 1 ? "|" : "");
//                ++c1;
//            }
//
//            rp << ")(\\-?[0-9])?$";
//        }
        try {
//            regex re(rp.str());
            regex re = munits::GetUnParsRegex()[u].first;
//            TRACE(munits::GetUnParsRegex()[u].second);
            sregex_iterator next(unit.begin(), unit.end(), re);
            sregex_iterator end;
            while (next != end) {
                smatch match = *next;

                std::string _recomposed = string((std::string  &&) match[1]) + string((std::string  &&) match[2]) +string((std::string  &&) match[3]);
//                TRACE(_recomposed);
                if (_recomposed  == unit) {
                    no_match = false;
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
//    TRACEITERABLE(parsed);
    return parsed;
}

vector<string> munits::rparser(string token) {
    const vector<munits::Metric> &rmatrix = munits::GetMatrix();
    vector<string> parsed = {"", "", ""};

    bool no_match = true;

    for (int u = 0; u < munits::_Last && no_match; ++u) {
        if (!rmatrix[u].unit_resolve_mapping.empty()) {
//            stringstream rp;
//            { // composing the regex for each Unit type
//                rp << "^(";
//                const map<string, const shared_ptr<munits::ConverterFunction>> &prefixes = rmatrix[u].converter->Prefixes();
//                int c1 = 0;
//                for (auto prx = prefixes.begin(); prx != prefixes.end(); ++prx) {
//                    rp << prx->first << (c1 != prefixes.size() - 1 ? "|" : "");
//                    ++c1;
//                }
//
//                rp << ")?(";
//                c1 = 0;
//
//                for (auto unt = rmatrix[u].unit_resolve_mapping.begin();
//                     unt != rmatrix[u].unit_resolve_mapping.end(); ++unt) {
//                    rp << unt->first << (c1 != rmatrix[u].unit_resolve_mapping.size() - 1 ? "|" : "");
//                    ++c1;
//                }
//
//                rp << ")(\\-?[0-9])?$";
//            }
            try {

//                TRACE(rp.str());
             regex re = munits::GetRParsRegex()[u].first;
//                TRACE(munits::GetRParsRegex()[u].second );

//                regex re(rp.str());
                sregex_iterator next(token.begin(), token.end(), re);
                sregex_iterator end;
                while (next != end) {
                    smatch match = *next;

                    std::string _recomposed = string((std::string  &&) match[1]) + string((std::string  &&) match[2]) + string((std::string  &&) match[3]);

                    if ( _recomposed == token) {
                        no_match = false;
                        parsed[0] = match[1];
                        parsed[1] = match[2];
                        parsed[2] = match[3];
                    }
                    next++;
                }
            } catch (regex_error &e) {}
        }
    }

    return parsed;
}
