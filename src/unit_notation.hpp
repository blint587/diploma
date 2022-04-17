
#ifndef MUSYS_UNIT_NOTATION_HPP
#define MUSYS_UNIT_NOTATION_HPP


#include <set>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <exception>
#include <iterator>
#include "../lib/Accesories/accessories.hpp"

namespace munits{

    class UnitNotation  {
        friend class UnitNotationVector;
        friend class Quantity;

    private:
        std::string unit = "";
        std::string prefix = "";
        int exponent = 0;
        int silent_exponent = 0;

        static int div(const munits::UnitNotation & lfths,  const munits::UnitNotation & rgths);
        static std::list<munits::UnitNotation> tokenise(const std::string &unit);
        static bool divable(const munits::UnitNotation & lfths, const munits::UnitNotation & rgths);

    public:
        explicit UnitNotation(){};
        explicit UnitNotation(std::string unit);
        UnitNotation(const UnitNotation &) = default;

        UnitNotation & operator= (const UnitNotation &)= default;

        operator std::string() const { return prefix + unit + (1 == exponent ? "" : std::to_string(exponent));};

        friend std::ostream& operator<< (std::ostream & str, const UnitNotation & un){
            str << un.prefix << " " << un.unit << " " << un.exponent;
            return str;
        }
        friend bool operator== (const munits::UnitNotation & lfths, const munits::UnitNotation & rgths){return lfths.unit == rgths.unit &&  lfths.prefix == rgths.prefix && lfths.exponent == rgths.exponent;}
        friend bool operator!= (const munits::UnitNotation & lfths, const munits::UnitNotation & rgths){return !(lfths == rgths);}
        const std::string & GetUnit() const { return unit;};

        const std::string & GetPrefix() const { return prefix;};
        const int & GetExponent() const { return 0 == silent_exponent ? exponent : silent_exponent;};


    };

    class UnitNotationVector  {

        private:
            std::vector<munits::UnitNotation> unitnotations {7};
            double mult_factor = 1.0;
            static const UnitNotation & npos ();
        public:
            double getMultiplicationFactor() const {return mult_factor;};
            UnitNotationVector(){};
            UnitNotationVector & operator= (const UnitNotationVector &) = default;
            UnitNotationVector (const UnitNotationVector &) = default;

            std::vector<UnitNotation>::const_iterator begin() const {return unitnotations.begin();};
            std::vector<UnitNotation>::const_iterator end() const {return unitnotations.end();};

            std::vector<UnitNotation>::iterator begin() {return unitnotations.begin();};
            std::vector<UnitNotation>::iterator end() {return unitnotations.end();};

            void set(long long int, const UnitNotation &);

            UnitNotation & operator[](int idx);
            const UnitNotation operator[] (int idx) const;

            unsigned long long int size() const {return unitnotations.size();}

            friend bool operator==(const UnitNotationVector & lfths, const UnitNotationVector & rghts){return lfths.unitnotations == rghts.unitnotations &&  lfths.mult_factor == rghts.mult_factor;}
            friend bool operator!=(const UnitNotationVector & lfths, const UnitNotationVector & rghts){return !(lfths == rghts);}

        static UnitNotationVector compose_unit_vector(const std::string &unit);

        static std::string compose_unit(const UnitNotationVector &, const int);
    };





}



#endif //MUSYS_UNIT_NOTATION_HPP
