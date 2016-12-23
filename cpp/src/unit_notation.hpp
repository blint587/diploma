
#ifndef MUSYS_UNIT_NOTATION_HPP
#define MUSYS_UNIT_NOTATION_HPP


#include <set>
#include <regex>
#include <iostream>
#include <vector>
#include <string>


namespace munits{

    class UnitNotation  {
    private:

        std::string unit = "";
        std::string prefix = "";
        int exponent = 0;
    protected:
        std::vector<std::string> parser(std::string);
    public:
        explicit UnitNotation(){};
        explicit UnitNotation(std::string unit);
        operator std::string() const { return prefix + " " + unit + " " + std::to_string(exponent);};
        friend std::ostream& operator<< (std::ostream & str, const UnitNotation & un){
            str << un.prefix << " " << un.unit << " " << un.exponent;
            return str;
        }
        const std::string & GetUnit() const { return unit;};
        const std::string & GetPrefix() const { return prefix;};
        const int & GetExponent() const { return exponent;};
    };
}



#endif //MUSYS_UNIT_NOTATION_HPP
