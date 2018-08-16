
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
    __declspec(dllexport) void __toString(munits::Quantity * q,  char * buffer){
        auto temp =  ((std::string) *q).c_str();
        int lenstr = strlen(temp);
        for (int i= 0; i < lenstr  ;i++){
            buffer[i] = temp[i];
        }
    }
    __declspec(dllexport) double __getValue(munits::Quantity * q){
        return q->getValue();
    }
    //add
    __declspec(dllexport) munits::Quantity* __add(munits::Quantity * lft, munits::Quantity * rgh){
        munits::Quantity temp = *lft + *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    //substract
    __declspec(dllexport) munits::Quantity* __substract(munits::Quantity * lft, munits::Quantity * rgh){
        munits::Quantity temp = *lft - *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    //multiply
    __declspec(dllexport) munits::Quantity* __multiply(munits::Quantity * lft, munits::Quantity * rgh){
        munits::Quantity temp = *lft * *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    __declspec(dllexport) munits::Quantity* __multiply_rgh_int(munits::Quantity * lft, int rgh){
        munits::Quantity temp = *lft * rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
   __declspec(dllexport) munits::Quantity* __multiply_lft_int(int lft, munits::Quantity * rgh){
        munits::Quantity temp = lft * *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    __declspec(dllexport) munits::Quantity* __multiply_rgh_double(munits::Quantity * lft, double rgh){
        munits::Quantity temp = *lft * rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
   __declspec(dllexport) munits::Quantity* __multiply_lft_double(double lft, munits::Quantity * rgh){
        munits::Quantity temp = lft * *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    //divide
   __declspec(dllexport) munits::Quantity* __divide(munits::Quantity * lft, munits::Quantity * rgh){
        munits::Quantity temp = *lft / *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
   __declspec(dllexport) munits::Quantity* __divide_int(munits::Quantity * lft, int rgh){
        munits::Quantity temp = *lft / rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }

   __declspec(dllexport) munits::Quantity* __divide_double(munits::Quantity * lft, double rgh){
        munits::Quantity temp = *lft / rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }

    //comparison
    __declspec(dllexport) bool __lt(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft < *rgh;
    }
    __declspec(dllexport) bool __gt(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft > *rgh;
    }
    __declspec(dllexport) bool __le(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft <= *rgh;
    }
    __declspec(dllexport) bool __ge(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft >= *rgh;
    }
    __declspec(dllexport) bool __eq(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft == *rgh;
    }
    __declspec(dllexport) bool __ne(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft != *rgh;
    }

    //power
    __declspec(dllexport) munits::Quantity * __pow(munits::Quantity * lft, int rgh){
        munits::Quantity temp = munits::pow(*lft,  rgh);
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    //nt roth
    __declspec(dllexport) munits::Quantity * __ntrt(munits::Quantity * lft, int rgh){
        munits::Quantity temp = lft->ntrt(rgh);
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    __declspec(dllexport) double __get(munits::Quantity * lft, const char* u){
        return lft->operator()(u);
    }

    __declspec(dllexport) double __double(munits::Quantity * q){
        return q->toDouble();
    }

}

