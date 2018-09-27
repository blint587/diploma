
#include <string>
#include <stack>
#include "uresolver.hpp"
#include "prefix.hpp"
#include "parsers.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "../lib/Accesories/accessories.hpp"

using namespace std;

bool munits::Resolver::resolve(std::list<std::string> &l) {

        bool replacement_occured = false;
        stack<Prefix> prefixes;
        int overflow = 0;


        for(auto b = l.begin(); b != l.end(); b++) {
            auto parsed = munits::rparser(*b);
            if("" != parsed[0]){
                prefixes.push({parsed[0], *GetPrefixes().find(parsed[0])->second});
            }

            auto m = find_if(rmatrix.begin(), rmatrix.end(), [&](munits::Metric metric)->bool {return metric.unit_resolve_mapping.end() != metric.unit_resolve_mapping.find(parsed[1]);});

            if (m != rmatrix.end()) {
                string o = m->unit_resolve_mapping.find(parsed[1])->second;
                istringstream iss(o);
                list<string> tokens;

                // splitting up string representations (by default at " ")
                copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), std::back_inserter(tokens));
                for(auto token = tokens.begin(); token != tokens.end(); token++){
                    UnitNotation notation (*token);
                    if(! prefixes.empty()){
                        Prefix prx = prefixes.top();

                        UnitNotation nnotation = mergePrefixWithNotation(prx, notation, overflow);
                        if (nnotation != notation) {
                            token = tokens.erase(token);
                            token = tokens.insert(token, (std::string) nnotation);
                            prefixes.pop();
                        }if(0 != overflow){
                            std::string prefix_notation = getPrefixByExponent(overflow);
                            prefixes.push(Prefix(prefix_notation, *GetPrefixes().find(prefix_notation)->second));
                        }
                    }

                }

                l.insert(b, tokens.begin(), tokens.end());
                b = l.erase(b);
                replacement_occured = true;
            }
        }

    return replacement_occured;
}




