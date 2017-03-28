
#include "uresolver.hpp"
#include "../lib/Accesories/accessories.hpp"
#include "prefix.hpp"
#include "parsers.hpp"
#include <string>

using namespace std;

bool munits::Resolver::resolve(
        list<std::string>::iterator begin,
        list<std::string>::iterator end,
        list<string> & l) {

        bool replacement_occured = false;
        stack<Prefix> prefixes;


        for(auto b = begin; b != end; b++) {
            auto parsed = munits::rparser(*b);
            if("" != parsed[0]){
                prefixes.push({parsed[0], *GetPrefixes().find(parsed[0])->second});
            }

            auto m = find_if(rmatrix.begin(), rmatrix.end(), [&](munits::Metric metric){return metric.unit_resolve_mapping.find(parsed[1]) != metric.unit_resolve_mapping.end();});
            if (m != rmatrix.end()) {
                string o = m->unit_resolve_mapping.find(parsed[1])->second;

                istringstream iss(o);
                vector<string> tokens;

                // splitting up string representations (by default at " ")
                copy(istream_iterator<std::string>(iss), istream_iterator<std::string>(), back_inserter(tokens));
                for(auto token = tokens.begin(); token != tokens.end(); token++){
                    UnitNotation notation (*token);
                    if(! prefixes.empty()){
                        Prefix prx = prefixes.top();
                        UnitNotation nnotation = prx + notation;
                        if (nnotation != notation) {

                            token = tokens.erase(token);
                            token = tokens.insert(token, (std::string &&)nnotation);
                            prefixes.pop();
                        }
                    }

                }
                TRACEITERABLE(tokens);

                l.insert(b, tokens.begin(), tokens.end());
                b = l.erase(b);
                replacement_occured = true;
            }
        }

    return replacement_occured;
}




