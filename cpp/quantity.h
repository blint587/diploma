#ifndef MUSYS_QUANTITY_H
#define MUSYS_QUANTITY_H

#include <vector>
#include <set>
#include <string>
#include <map>
#include <math.h>
#include <string>
#include <memory>

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

        double operator()(double, std::string, std::string, double=1.) const;
        bool is_valid_unit(const std::string &) const;
    };


    struct Metric{
        const std::vector<int> dim_vector;
        const Converter converter;

        Metric(std::vector<int>,
               std::string = "",
               std::set<std::string> = std::set<std::string>(),
               const std::map<std::string, const std::shared_ptr<quantity::ConverterFunction>> =
               std::map<std::string, const std::shared_ptr<quantity::ConverterFunction>>());

    };

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

    static const std::vector<quantity::Metric> matrix = {
            {{1, 0, 0, 0, 0, 0, 0}, "m"}, //Length
            {{0, 1, 0, 0, 0, 0, 0}, "g"}, // Mass
            {{0, 0, 1, 0, 0, 0, 0}, "s"},  //Time
            {{0, 0, 0, 1, 0, 0, 0}, "A"},  //Electric Currency
            {{0, 0, 0, 0, 1, 0, 0}, "K", {"E","P","T", "G", "M","k", "h", "da", "d", "c", "m", "μ", "n", "p", "f", "a"},//Temperature
                                          {
                                                  {"°C", std::make_shared<ConverterFunction>(ConverterFunction(1., 273.15))},
                                                  {"°F", std::make_shared<ConverterFunction>(ConverterFunction(1., 273.15))},
                                          }
            },
            {{0, 0, 0, 0, 0, 1, 0}, "mol"},  //Amount of Substance
            {{0, 0, 0, 0, 0, 0, 1}, "cd"}  //Luminous Intensity
    };

    class Quantity {
        /*
        # 1. length
        # 2. mass
        # 3. time
        # 4. electric_current
        # 5. temperature
        # 6. amount_of_substance
        # 7. luminous_intensity
         */
    private:
        const metrics matrix_index;
        const std::vector<std::string> unit_vector;
        double value;
        const std::shared_ptr<const quantity::Converter> converter;
        bool is_valid_unit() const;
    public:
        const std::string unit;
        std::vector<int> getDimVector() const{return matrix[matrix_index].dim_vector;}
        Quantity(metrics, double, const char*);
        double operator()(std::string) const;

        };

}


#endif //MUSYS_QUANTITY_H
