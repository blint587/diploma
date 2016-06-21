//
// Created by bmolnar on 2016. 06. 17..
//

#ifndef MUSYS_QUANTITY_H
#define MUSYS_QUANTITY_H

#include <vector>
#include <set>
#include <string>
#include <map>
#include "ConverterFunction.h"

namespace quantity {

    struct Metric{
        const std::vector<int> dim_vector;
        const std::string base_unit;
        const std::set<std::string> remove;
        const std::map<std::string, const std::shared_ptr<quantity::ConverterFunction>> additional_units;

        Metric(std::vector<int> dim_vector,
               std::string base_unit = "",
               std::set<std::string> remove = std::set<std::string>(),
               const std::map<std::string, const std::shared_ptr<quantity::ConverterFunction>> additional_units = std::map<std::string, const std::shared_ptr<quantity::ConverterFunction>>()
        )
                :dim_vector(dim_vector), base_unit(base_unit),remove(remove), additional_units(additional_units){};

    };

    enum metrics{
        Length = 0,
        Mass = 1,
        Time = 2,
        ElectricCurrency = 3,
        Temperature = 4,
        AmountOfSubstance = 5,
        LuminousIntensity = 6

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
        const quantity::Converter converter;
        bool is_valid_unit() const;
    public:
        const std::string unit;
        std::vector<int> getDimVector() const{return matrix[matrix_index].dim_vector;}
        Quantity(metrics, double, const char*);
        double operator()(std::string) const;

        };

}


#endif //MUSYS_QUANTITY_H
