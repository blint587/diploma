

#ifndef MUSYS_CONVERTER_HPP
#define MUSYS_CONVERTER_HPP

#include <string>
#include <memory>
#include <set>
#include <map>
#include "unit.hpp"
#include "unit_notation.hpp"

namespace munits{
    class Converter {

        private:

            std::string base_unit;

            std::map<std::string, const std::shared_ptr<ConverterFunction>> prefixes;
            std::map<std::string, const std::shared_ptr<Unit>> units;
        protected:
    //        const std::map<std::string, const std::shared_ptr<ConverterFunction>> additional_units;
        public:
            const std::map<std::string, const std::shared_ptr<ConverterFunction>> & Prefixes() const{return prefixes;};
            const std::map<std::string, const std::shared_ptr<Unit>> & Units() const{return units;};
            explicit Converter(std::string,
                               const std::set<std::string> & = std::set<std::string>(),
                               const std::map<std::string, const std::shared_ptr<Unit>> = std::map<std::string, const std::shared_ptr<Unit>>());

            ~Converter(){}
            double Convert( double, UnitNotation, UnitNotation,  int=1) const;
            bool is_valid_unit(const UnitNotation &) const;
            const std::string GetBaseUnit() const {return base_unit;};

        };
}

#endif //MUSYS_CONVERTER_HPP
