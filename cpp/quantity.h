//
// Created by bmolnar on 2016. 06. 17..
//

#ifndef MUSYS_QUANTITY_H
#define MUSYS_QUANTITY_H

#include <vector>
#include <string>

namespace quantity {

    enum metrics{
        Length = 0,
        Mass = 1,
        Time = 2,

    };

    static std::vector<std::vector<int>> matrix = {
            {1, 0, 0, 0, 0, 0, 0}, //Length
            {0, 1, 0, 0, 0, 0, 0}, // Mass
            {0, 0, 1, 0, 0, 0, 0}  //Time
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
    public:
        const std::string unit;
        Quantity(metrics, double, const char*);
        std::vector<int> getDimVector() const{return matrix[matrix_index];}
        };

}


#endif //MUSYS_QUANTITY_H
