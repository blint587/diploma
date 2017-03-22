
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
        private:
            const std::vector <munits::Metric> & rmatrix;
        public:
            Resolver(const std::vector <munits::Metric> & matrix = munits::GetMatrix()): rmatrix(matrix){};
            bool resolve(std::list<std::string>::iterator begin,
                         std::list<std::string>::iterator end,
                         std::list<std::string> & l);

            std::vector<std::string> parser(const std::string &token);



    };
}


#endif //SANDBOX_RESOLVER_HPP
