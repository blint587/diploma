#include "parsers.hpp"
#include "converter_function.hpp"
#include <string>
#include <vector>
#include <regex>
#include "metric.hpp"
#include "dynamic.hpp"

using namespace std;

vector<string> munits::unparser(string unit) {
//    TRACEWHAT(unit, "Unit passed to unpatser:");
    const vector<munits::Metric> &rmatrix = munits::GetMatrix();
    vector<string> parsed = {"", "", ""};

    bool no_match = true;

    for (int u = 0; u < munits::_Last && no_match; ++u) {

        try {
            regex re = munits::GetUnParsRegex()[u];
            sregex_iterator next(unit.begin(), unit.end(), re);
            sregex_iterator end;
            while (next != end) {
                smatch match = *next;
                std::string _recomposed = string((std::string  &&) match[1]) + string((std::string  &&) match[2]) +string((std::string  &&) match[3]);
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
    return parsed;
}

vector<string> munits::rparser(string token) {
    const vector<munits::Metric> &rmatrix = munits::GetMatrix();
    vector<string> parsed = {"", "", ""};

    bool no_match = true;

    for (int u = 0; u < munits::_Last && no_match; ++u) {
        if (!rmatrix[u].unit_resolve_mapping.empty()) {
            try {

                regex re = munits::GetRParsRegex()[u];
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
