
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
            auto m = find_if(rmatrix.begin(), rmatrix.end(), [&](munits::Metric metric){return metric.unit_resolve_mapping.find(*b) != metric.unit_resolve_mapping.end();});
            if (m != rmatrix.end()) {
                string o = m->unit_resolve_mapping.find(*b)->second;

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
};

