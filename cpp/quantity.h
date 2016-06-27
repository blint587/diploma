#ifndef MUSYS_QUANTITY_H
#define MUSYS_QUANTITY_H

#include <vector>
#include <set>
#include <string>
#include <map>
#include <math.h>
#include <string>
#include <memory>
#ifdef DEBUG
    #include <iostream>
#endif
#include <algorithm>
#include <sstream>
#include <iterator>
#include <regex>

namespace quantity {

    class ConverterFunction {

    private:
        const double first_order;
        const double zero_order;
        const char * signature;

    public:
        double to_base(double, double) const;

        double from_base(double, double) const;

        explicit ConverterFunction(double, double, const char *);

    };

    class Unit: public quantity::ConverterFunction {

    public:
//        const std::string unit;
        const bool applay_prefix;
        const bool ignor_exponent;

        explicit Unit(double a = 1, double b = 0, const char * s="Default",  /*std::string unit,*/ bool applay_prefix = true, bool ignor_exponent = false) :
                ConverterFunction(a, b, s), /* unit(unit),*/ applay_prefix(applay_prefix), ignor_exponent(ignor_exponent) {
        };
    };


    class UnitNotation  {
        private:

            std::string unit = "";
            std::string prefix;
            int exponent;
        protected:
            std::vector<std::string> parser(std::string);
        public:
            explicit UnitNotation(){};
            UnitNotation(std::string unit);
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
        Converter(std::string,
                  const std::set<std::string> & = std::set<std::string>(),
                  const std::map<std::string, const std::shared_ptr<Unit>> = std::map<std::string, const std::shared_ptr<Unit>>());

        ~Converter(){
        #ifdef DEBUG
            std::cout << "Destructing Converter with " << base_unit<< " at "  << this << std::endl;
        #endif
        }
        double Convert(double, UnitNotation, UnitNotation, double=1.) const;
        bool is_valid_unit(const UnitNotation &) const;
    };




    struct Metric{
        const std::vector<int> dim_vector;
        const std::shared_ptr<Converter> converter;

        Metric(std::vector<int>,
               std::string = "",
               std::set<std::string> = std::set<std::string>(),
               const std::map<std::string, const std::shared_ptr<quantity::Unit>> =
               std::map<std::string, const std::shared_ptr<quantity::Unit>>());

    };

    const std::vector<quantity::Metric> & GetMatrix();

    class Quantity {
    public:
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
            Concentration = 10,
            _Last
        };

    private:

        const int matrix_index;
        std::vector<UnitNotation> unit_vector = {UnitNotation(), UnitNotation(), UnitNotation(), UnitNotation(), UnitNotation(), UnitNotation(), UnitNotation()};
        double value;
//        const UnitNotation unit;
        std::shared_ptr<quantity::Converter> converter;

//        bool is_valid_unit() const;
        Quantity(int, double, std::vector<UnitNotation>);
        std::vector<UnitNotation> compose_unit_vector(const std::string &unit) const;
        std::string compose_unit(const std::vector<UnitNotation> &) const;

        static Quantity mathop(const Quantity &a, const Quantity &b, int p=1);

    public:

        std::vector<int> GetDimVector() const{return GetMatrix()[matrix_index].dim_vector;}
        Quantity(metrics, double, const std::string);
        ~Quantity(){
            };
            double operator()(const std::string) const;
            friend std::ostream& operator<< (std::ostream& str, const Quantity & a){
                str << a.value << " " << a.compose_unit(a.unit_vector);
                return str;
            };
            friend Quantity operator+ (const Quantity & a, const Quantity & b) {return quantity::Quantity(a.matrix_index, a.value + b(a.compose_unit(a.unit_vector)), a.unit_vector);};
            friend Quantity operator- (const Quantity & a, const Quantity & b) {return quantity::Quantity(a.matrix_index, a.value - b(a.compose_unit(a.unit_vector)), a.unit_vector);};
            friend Quantity operator* (const Quantity & a, const Quantity & b) {return mathop(a, b, 1);};
            friend Quantity operator/ (const Quantity & a, const Quantity & b) {return mathop(a, b, -1);};

    };



}


#endif //MUSYS_QUANTITY_H
