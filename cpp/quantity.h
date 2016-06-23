#ifndef MUSYS_QUANTITY_H
#define MUSYS_QUANTITY_H

#include <vector>
#include <set>
#include <string>
#include <map>
#include <math.h>
#include <string>
#include <memory>
#include <iostream>

namespace quantity {

    class ConverterFunction {

    private:
        const double first_order;
        const double zero_order;
    public:
        double to_base(double, double) const;

        double from_bsas(double, double) const;

        ConverterFunction(double, double=0);

    };

    class Converter {

    private:
        const std::map<std::string, const std::shared_ptr<ConverterFunction>> & GetPrefixes() const;
        std::string base_unit;
        std::map<std::string, const std::shared_ptr<ConverterFunction>> units;
    protected:
        const std::map<std::string, const std::shared_ptr<ConverterFunction>> additional_units;
    public:
        Converter(std::string,
                  const std::set<std::string> & = std::set<std::string>(),
                  const std::map<std::string, const std::shared_ptr<ConverterFunction>> = std::map<std::string, const std::shared_ptr<ConverterFunction>>());

//        double operator()(double, std::string, std::string, double=1.) const;
        double Convert(double, std::string, std::string, double=1.) const;

        bool is_valid_unit(const std::string &) const;
        ~Converter(){
#ifdef DEBUG
            std::cout << "Destructing Converter with " << base_unit<< " at "  << this << std::endl;
#endif
        }
    };

    struct Metric{
        const std::vector<int> dim_vector;
        const std::shared_ptr<Converter> converter;

        Metric(std::vector<int>,
               std::string = "",
               std::set<std::string> = std::set<std::string>(),
               const std::map<std::string, const std::shared_ptr<quantity::ConverterFunction>> =
               std::map<std::string, const std::shared_ptr<quantity::ConverterFunction>>());

    };

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
            _Last
        };

    private:
        const std::vector<quantity::Metric> & GetMatrix() const;

        const metrics matrix_index;
        const std::vector<std::string> unit_vector;
        double value;
        const std::string unit;
        std::shared_ptr<quantity::Converter> converter;

        bool is_valid_unit() const;
       // Quantity(int, double, const char*);


    public:


        std::vector<int> GetDimVector() const{return GetMatrix()[matrix_index].dim_vector;}
        Quantity(metrics, double, const std::string);
        ~Quantity(){
            };
            double operator()(std::string) const;
            friend Quantity operator+ (const Quantity & a, const Quantity & b) {return quantity::Quantity(a.matrix_index, a.value + b(a.unit), a.unit);};
            friend Quantity operator- (const Quantity & a, const Quantity & b) {return quantity::Quantity(a.matrix_index, a.value - b(a.unit), a.unit);};
        };

}


#endif //MUSYS_QUANTITY_H
