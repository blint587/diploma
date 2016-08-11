#ifndef MUSYS_QUANTITY_H
#define MUSYS_QUANTITY_H

#include <vector>
#include <set>
#include <string>
#include <map>
#include <math.h>
#include <string>
#include <memory>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <regex>
#include "lib/Accesories/accessories.hpp"
#include "converter_function.hpp"
#include "unit.hpp"

#ifdef DEBUG
    #include <iostream>
#endif

namespace munits {


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

    class Converter {

    private:
        const std::map<std::string, const std::shared_ptr<ConverterFunction>> & GetPrefixes() const;
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
         double Convert( double, UnitNotation, UnitNotation,  double=1.) const;
        bool is_valid_unit(const UnitNotation &) const;
    };

    struct Metric{
        const std::vector<int> dim_vector;
        const std::shared_ptr<Converter> converter;

        Metric(std::vector<int>, // cannot be explicit due to use of initializer list in GetMatrix
               std::string = "",
               std::set<std::string> = std::set<std::string>(),
               const std::map<std::string, const std::shared_ptr<munits::Unit>> =
               std::map<std::string, const std::shared_ptr<munits::Unit>>());

    };

    enum metrics{
        Length = 0,
        Mass = 1,
        Time = 2,
        ElectricCurrency = 3,
        Temperature = 4,
        AmountOfSubstance = 5,
        LuminousIntensity = 6,
        Area = 7,
        Volume = 8,
        VolumetricFlow = 9,
        MolarConcentration = 10,
        Acceleration = 11,
        Force = 12,
        Velocity = 13,
        Concentration = 14,
        _Last

    };
    const std::vector<munits::Metric> & GetMatrix();

    class Quantity {

    private:

        int matrix_index;
        std::vector<UnitNotation> unit_vector {7};
        double value;
        std::shared_ptr<munits::Converter> converter;
        std::vector<int> dim_vector;

        explicit Quantity(int,  double, std::vector<UnitNotation>);
        explicit Quantity(int, double, std::vector<UnitNotation>, std::vector<int>);

        static std::vector<UnitNotation> compose_unit_vector(const std::string &unit);
        static std::string compose_unit(const std::vector<UnitNotation> &);
        static Quantity mathop(const Quantity &a, const Quantity &b, int p=1);
        static bool compop(const Quantity &a, const Quantity &b, bool (*f)(const double &, const double &));

    public:

        explicit Quantity(metrics,  double, const std::string);
//        Quantity(Quantity &);
        Quantity(const Quantity &) = default;
        Quantity & operator=(const Quantity &) = default;
        // TODO: implement move semantics
        ~Quantity(){};

        const std::vector<int> GetDimVector() const{return dim_vector;};
        const int getMatrixIndex()const {return matrix_index;};

        double operator()(const std::string) const;
        operator std::string() const {std::stringstream ss; ss << value << " " << compose_unit(unit_vector); return ss.str();}

        // TODO: include only if used for Cython
        std::string toString() const {return std::string(*this); }

        friend std::ostream& operator<< (std::ostream& str, const Quantity & a){str << a.value << " " <<  munits::Quantity::compose_unit(a.unit_vector);return str;};

        friend Quantity operator+ (const Quantity & a, const Quantity & b) {return munits::Quantity(a.matrix_index, a.value + b(munits::Quantity::compose_unit(a.unit_vector)), a.unit_vector);};
        friend Quantity operator- (const Quantity & a, const Quantity & b) {return munits::Quantity(a.matrix_index, a.value - b(munits::Quantity::compose_unit(a.unit_vector)), a.unit_vector);};
        friend Quantity operator* (const Quantity & a, const Quantity & b) {return mathop(a, b, 1);};
        friend Quantity operator/ (const Quantity & a, const Quantity & b) {return mathop(a, b, -1);};

        friend bool operator < (const Quantity & a, const Quantity & b) {return munits::Quantity::compop(a, b, accessories::lt<const double>);};
        friend bool operator <= (const Quantity & a, const Quantity & b) {return munits::Quantity::compop(a, b, accessories::le<const double>);};
        friend bool operator > (const Quantity & a, const Quantity & b) {return munits::Quantity::compop(a, b, accessories::gt<const double>);};
        friend bool operator >= (const Quantity & a, const Quantity & b) {return munits::Quantity::compop(a, b, accessories::ge<const double>);};
        friend bool operator == (const Quantity & a, const Quantity & b) {return munits::Quantity::compop(a, b, accessories::eq<const double>);};
        friend bool operator != (const Quantity & a, const Quantity & b) {return munits::Quantity::compop(a, b, accessories::ne<const double>);};

    };

    Quantity pow(Quantity  a, int e);

}


#endif //MUSYS_QUANTITY_H
