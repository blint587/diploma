
#include <string>
#include "../quantity.h"
#include "../metric.hpp"

// C export helper functions to be called from C#
extern "C" {
    // Constructor which returns a heap pointer
    __declspec(dllexport) munits::Quantity* __cdecl CreateQuantity(int t, double v, const char * u){
        return new munits::Quantity((munits::metrics) t, v, u);
    };
    // Destructor
    __declspec(dllexport) void __cdecl DeleteQuantity(munits::Quantity * q){
        delete q;
    }

    // toString method
    __declspec(dllexport) void __cdecl __toString(munits::Quantity * q, char * buffer, unsigned long  * buffer_size){

        if (buffer_size == nullptr)
        {
            return;
        }

        std::string st = q->toString();
//        TRACEWHAT(st, "C string: ");
        unsigned long size = st.length()  + 1;
//        TRACEWHAT(size, "size: ");
        if ((buffer != nullptr) && (*buffer_size >= size))
        {
            strcpy_s(buffer, size, st.c_str());
        }
        // The string length including the zero terminator
        * buffer_size = size;
    }
    // get value
    __declspec(dllexport) double __cdecl __getValue(munits::Quantity * q){
        return q->getValue();
    }
    __declspec(dllexport) void __cdecl __getUnit(munits::Quantity * q, char * buffer, unsigned long  * buffer_size){
        if (buffer_size == nullptr)
        {
            return;
        }
        std::string st = q->getUnit();
        unsigned long size = st.length()  + 1;
        if ((buffer != nullptr) && (*buffer_size >= size))
        {
            strcpy_s(buffer, size, st.c_str());
        }
        // The string length including the zero terminator
        * buffer_size = size;
    }

    // get type (matrix index)
    __declspec(dllexport) const int __cdecl __getType(munits::Quantity * q){
        return q->getMatrixIndex();
    }

    //add
    __declspec(dllexport) munits::Quantity* __cdecl __add(munits::Quantity * lft, munits::Quantity * rgh){
        munits::Quantity temp = *lft + *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    //substract
    __declspec(dllexport) munits::Quantity* __cdecl __substract(munits::Quantity * lft, munits::Quantity * rgh){
        munits::Quantity temp = *lft - *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    //multiply
    __declspec(dllexport) munits::Quantity* __cdecl __multiply(munits::Quantity * lft, munits::Quantity * rgh){
        munits::Quantity temp = *lft * *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    __declspec(dllexport) munits::Quantity* __cdecl __multiply_rgh_int(munits::Quantity * lft, int rgh){
        munits::Quantity temp = *lft * rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
   __declspec(dllexport) munits::Quantity* __cdecl __multiply_lft_int(int lft, munits::Quantity * rgh){
        munits::Quantity temp = lft * *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    __declspec(dllexport) munits::Quantity* __cdecl __multiply_rgh_double(munits::Quantity * lft, double rgh){
        munits::Quantity temp = *lft * rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
   __declspec(dllexport) munits::Quantity* __cdecl __multiply_lft_double(double lft, munits::Quantity * rgh){
        munits::Quantity temp = lft * *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    //divide
   __declspec(dllexport) munits::Quantity* __cdecl __divide(munits::Quantity * lft, munits::Quantity * rgh){
        munits::Quantity temp = *lft / *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
   __declspec(dllexport) munits::Quantity* __cdecl __divide_int(munits::Quantity * lft, int rgh){
        munits::Quantity temp = *lft / rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }

   __declspec(dllexport) munits::Quantity* __cdecl __divide_double(munits::Quantity * lft, double rgh){
        munits::Quantity temp = *lft / rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }

    //comparison
    __declspec(dllexport) int __cdecl __lt(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft < *rgh;
    }
    __declspec(dllexport) int __cdecl __gt(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft > *rgh;
    }
    __declspec(dllexport) int __cdecl __le(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft <= *rgh;
    }
    __declspec(dllexport) int __cdecl __ge(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft >= *rgh;
    }
    __declspec(dllexport) int __cdecl __eq(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft == *rgh;
    }
    __declspec(dllexport) int __cdecl __ne(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft != *rgh;
    }

    //power function
    __declspec(dllexport) munits::Quantity * __cdecl __pow(munits::Quantity * lft, int rgh){
        munits::Quantity temp = munits::pow(*lft,  rgh);
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    //nt root
    __declspec(dllexport) munits::Quantity* __cdecl __ntrt(munits::Quantity * lft, int rgh){
        munits::Quantity temp = lft->ntrt(rgh);
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    __declspec(dllexport) double __cdecl __get(munits::Quantity * lft, const char* u){
        return lft->operator()(u);
    }

    __declspec(dllexport) double __cdecl __double(munits::Quantity * q){
        return q->toDouble();
    }

}
