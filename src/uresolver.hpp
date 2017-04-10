
#ifndef SANDBOX_RESOLVER_HPP
#define SANDBOX_RESOLVER_HPP

#include <list>
#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
#include "dynamic.hpp"
#include "metric.hpp"

namespace munits {

    class Resolver {
        protected:
            const std::vector <munits::Metric> & rmatrix;
            const std::map<std::string, const std::shared_ptr<munits::ConverterFunction>> & rprefixes;
        public:
            Resolver(const std::vector <munits::Metric> & matrix = munits::GetMatrix(),
                     const std::map<std::string, const std::shared_ptr<munits::ConverterFunction>> & prefixes = munits::GetPrefixes()): rmatrix(matrix), rprefixes(prefixes){};
            bool resolve(std::list<std::string> &l);




    };
}


#endif //SANDBOX_RESOLVER_HPP
