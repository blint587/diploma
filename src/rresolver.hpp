
#ifndef SANDBOX_RRESOLVER_HPP
#define SANDBOX_RRESOLVER_HPP

#include "uresolver.hpp"

namespace munits {

    class RResolver : public Resolver {

    public:
        RResolver(const std::vector <munits::Metric> & matrix = munits::GetMatrix(),
                 const std::map<std::string, const std::shared_ptr<munits::ConverterFunction>> & prefixes = munits::GetPrefixes()): Resolver(matrix, prefixes){};

        std::string resolve(const munits::metrics, const std::vector<UnitNotation>) const;

    };
}


#endif //SANDBOX_RRESOLVER_HPP
