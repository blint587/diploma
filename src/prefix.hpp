
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

        friend munits::UnitNotation mergePrefixWithNotation (const Prefix & prx,  const munits::UnitNotation & un, int & overflow){

            int prefix_exponent = (int) getExponentOfPrefix(prx.notation);

            int unit_exponent = un.GetExponent();

            int mod = prefix_exponent % unit_exponent;
            if (0 == mod) {
                int un_exponent = (int) (GetPrefixes().find(un.GetPrefix())->second->getFirstOrderExponent() /
                        unit_exponent);

                int nexponent = (prefix_exponent + un_exponent) / unit_exponent;

                if (nexponent > getMaxPrefixExponent()) {
                    overflow = (nexponent - getMaxPrefixExponent()) * unit_exponent;
                    nexponent -= (overflow / un.GetExponent());
                } else if (nexponent < getMinPrefixExponent()) {
                    overflow = (nexponent - getMinPrefixExponent()) * unit_exponent;
                    nexponent -= (overflow / un.GetExponent());
                } else {
                    overflow = 0;
                }

                std::string new_prx = munits::getPrefixByExponent(nexponent);
                if (munits::npos_prefix == new_prx){
                    return UnitNotation(un);
                }

                return UnitNotation(
                        new_prx + un.GetUnit() + (un.GetExponent() == 1 ? "" : std::to_string(un.GetExponent())));
            }else{
                overflow = prefix_exponent;
                return UnitNotation(un);
            }



        }


    };


}


#endif //MUSYS_PREFIX_HPP
