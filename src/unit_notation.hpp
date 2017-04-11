
#ifndef MUSYS_UNIT_NOTATION_HPP
#define MUSYS_UNIT_NOTATION_HPP


#include <set>
#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include "../lib/Accesories/accessories.hpp"

namespace munits{

    class UnitNotation  {

    private:
        std::string unit = "";
        std::string prefix = "";
        int exponent = 0;

        static int div(const munits::UnitNotation & lfths,  const munits::UnitNotation & rgths);


    public:
        explicit UnitNotation(){};
        explicit UnitNotation(std::string unit);
        UnitNotation(const UnitNotation &) = default;

        operator std::string() const { return prefix + unit + (1 == exponent ? "" : std::to_string(exponent));};

        friend std::ostream& operator<< (std::ostream & str, const UnitNotation & un){
            str << un.prefix << " " << un.unit << " " << un.exponent;
            return str;
        }
        friend bool operator== (const munits::UnitNotation & lfths, const munits::UnitNotation & rgths){return lfths.unit == rgths.unit &&  lfths.prefix == rgths.prefix && lfths.exponent == rgths.exponent;}
        friend bool operator!= (const munits::UnitNotation & lfths, const munits::UnitNotation & rgths){return !(lfths == rgths);}
        const std::string & GetUnit() const { return unit;};

        const std::string & GetPrefix() const { return prefix;};
        const int & GetExponent() const { return exponent;};

        static std::vector<UnitNotation> compose_unit_vector(const std::string &unit);
        static bool divable(const munits::UnitNotation & lfths, const munits::UnitNotation & rgths);
        static std::string compose_unit(const std::vector<UnitNotation> &, const int);

    };


}



#endif //MUSYS_UNIT_NOTATION_HPP
