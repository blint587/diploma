
#include <string>
#include "../quantity.h"
#include "../metric.hpp"

// C export helper functions to be called from C#
extern "C" {
    // Constructor which returns a heap pointer
    __declspec(dllexport) munits::Quantity* CreateQuantity(int t, double v, const char* u){
        return new munits::Quantity((munits::metrics) t, v, u);
    };
    // Destructor
    __declspec(dllexport) void DeleteQuantity(munits::Quantity * q){
        delete q;
    }

    // toString method
    __declspec(dllexport) void toCSString(munits::Quantity * q,  char * buffer, int buffersize){
        auto temp = (std::string) *q;

         std::copy(temp.begin(), temp.end(), buffer);
    }
    __declspec(dllexport) double GetValueForCS(munits::Quantity * q){
        return q->getValue();
    }
    __declspec(dllexport) munits::Quantity* AddForCS(munits::Quantity * lft, munits::Quantity * rgh){
        munits::Quantity temp = *lft + *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }


}

