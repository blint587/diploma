
#ifndef MUSYS_PREFIX_HPP
#define MUSYS_PREFIX_HPP

#include <string>
#include "converter_function.hpp"
#include "unit_notation.hpp"
#include "dynamic.hpp"
#include "searchers.hpp"
#include "../lib/Accesories/accessories.hpp"

namespace munits {
    class Prefix {

    private:
        const std::string notation;
        const munits::ConverterFunction & converter;
        const int exponent;

    public:
        Prefix(const std::string n, const munits::ConverterFunction & cf, int exp = 1): notation(n), converter(cf), exponent(exp){}
        std::string getNotation(){ return notation;} const

        friend std::ostream& operator<< (std::ostream& str, const Prefix & a){str << a.notation << std::string(" ") <<  std::to_string(a.exponent); return str;};
        friend munits::UnitNotation operator+ (const Prefix & prx,  const munits::UnitNotation & un){
            int prefix_exponent = (int) getExponentOfPrefix(prx.notation);
            int un_exponent =  (int) (GetPrefixes().find(un.GetPrefix())->second->getFirstOrderExponent() / un.GetExponent());
            std::string new_prx = munits::getPrefixByExponent(prefix_exponent + un_exponent);
            TRACE(new_prx);

            return UnitNotation(new_prx + un.GetUnit() + (un.GetExponent()==1 ? "": std::to_string(un.GetExponent())));



        }


    };


}


#endif //MUSYS_PREFIX_HPP
