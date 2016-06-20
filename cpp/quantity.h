//
// Created by bmolnar on 2016. 06. 17..
//

#ifndef MUSYS_QUANTITY_H
#define MUSYS_QUANTITY_H

#include <vector>
#include <string>
#include <map>
#include "ConverterFunction.h"

namespace quantity {

    enum metrics{
        Length = 0,
        Mass = 1,
        Time = 2,

    };

    static std::vector<std::pair<std::vector<int>, std::string>> matrix = {
            {{1, 0, 0, 0, 0, 0, 0}, "m"}, //Length
            {{0, 1, 0, 0, 0, 0, 0}, "g" }, // Mass
            {{0, 0, 1, 0, 0, 0, 0}, "s"}  //Time
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
        std::vector<int> getDimVector() const{return matrix[matrix_index].first;}
        Quantity(metrics, double, const char*);
        double operator()(std::string) const;

        };

}


#endif //MUSYS_QUANTITY_H
