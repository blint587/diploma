
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
                            //if not MSVC
                              //token = tokens.erase(token);
                            //else
                            long long int pos_token = std::distance(tokens.begin(), token);
                            tokens.erase(token);
                            token = tokens.begin();
                            advance(token, pos_token);
                            //end
                            token = tokens.insert(token, (std::string) nnotation);
                            prefixes.pop();
                        }if(0 != overflow){
                            std::string prefix_notation = getPrefixByExponent(overflow);
                            prefixes.push(Prefix(prefix_notation, *GetPrefixes().find(prefix_notation)->second));
                        }
                    }

                }

                // if not MSVC
                //l.insert(b, tokens.begin(), tokens.end());
                //b = l.erase(b);
                //else
                unsigned long long int nb = std::distance(l.begin(), b);
                l.insert(b, tokens.begin(), tokens.end());
                l.erase(b);
				b = l.begin();
				advance(b, nb);
				//end
                replacement_occured = true;
            }
        }

    return replacement_occured;
}




