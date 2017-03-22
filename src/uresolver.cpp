
#include "uresolver.hpp"
#include "../lib/Accesories/accessories.hpp"
#include <sstream>

using namespace std;

bool munits::Resolver::resolve(
        list<string>::iterator begin,
        list<string>::iterator end,
        list<string> & l) {

        bool replacement_occured = false;

        for(auto b = begin; b != end; b++) {
            auto parsed = this->parser(*b);
            TRACEVITERABLE(parsed);
            auto m = find_if(rmatrix.begin(), rmatrix.end(), [&](munits::Metric metric){return metric.unit_resolve_mapping.find(parsed[1]) != metric.unit_resolve_mapping.end();});
            if (m != rmatrix.end()) {
                string o = m->unit_resolve_mapping.find(parsed[1])->second;

                istringstream iss(o);
                list<string> tokens;

                // splitting up string representations (by default at " ")
                copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));

                l.insert(b, tokens.begin(), tokens.end());
                b = l.erase(b);
                replacement_occured = true;

            }
        }

    return replacement_occured;
}

std::vector<std::string> munits::Resolver::parser(const string & token) {
    const vector<munits::Metric> & rmatrix = munits::GetMatrix();
    vector<string> parsed = {"", "", ""};

    bool no_match = true;

    for(int u = 0; u < munits::_Last && no_match; ++u) {
        if (!rmatrix[u].unit_resolve_mapping.empty()) {
            std::stringstream rp;
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

                for (auto unt = rmatrix[u].unit_resolve_mapping.begin();
                     unt != rmatrix[u].unit_resolve_mapping.end(); ++unt) {
                    rp << unt->first << (c1 != rmatrix[u].unit_resolve_mapping.size() - 1 ? "|" : "");
                    ++c1;
                }

                rp << ")(\\-?[0-9])?$";
            }
            try {
                regex re(rp.str());
                sregex_iterator next(token.begin(), token.end(), re);
                sregex_iterator end;
                while (next != end) {
                    smatch match = *next;

                    if (string((basic_string<char, char_traits<char>, allocator<char>> &&) match[1]) + string(
                            (basic_string<char, char_traits<char>, allocator<char>> &&) match[2]) + string(
                            (basic_string<char, char_traits<char>, allocator<char>> &&) match[3]) == token) {
                        no_match = false;
                        parsed[0] = match[1];
                        parsed[1] = match[2];
                        parsed[2] = match[3];
                    }
                    next++;
                }
            }catch (regex_error &e) {}
        }
    }

    return parsed;
}



