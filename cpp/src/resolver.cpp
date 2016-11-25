#include "resolver.hpp"
#include "../lib/Accesories/accessories.hpp"


bool munits::Resolver::resolve(
        std::list<std::string, std::allocator<std::string>>::iterator begin,
        std::list<std::string, std::allocator<std::string>>::iterator end,
        std::list<std::string> & l) {

        for(auto b = begin; b != end; b++) {
            auto m = std::find_if(rmatrix.begin(), rmatrix.end(), [&](munits::Metric metric){return metric.unit_resolve_mapping.find(*b) != metric.unit_resolve_mapping.end();});
            if (m != rmatrix.end()) {
                std::string o = m->unit_resolve_mapping.find(*b)->second;
                TRACE(o);
            }
        }
    return false;

};

