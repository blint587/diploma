
#include <string>
#include "../quantity.h"
#include "../metric.hpp"

#if defined (_MSC_VER)
    #define DLLEXPORT  __declspec(dllexport)
    #define CALLCONV __stdcall
    #define STRINGCOPY(buffer, size, source) strcpy_s(buffer, size, source)
#elif defined (__GNUC__)
    #include <cstring>
    #define DLLEXPORT
    #define CALLCONV //default is __stdcall
    #define  STRINGCOPY(buffer, size, source) std::strncpy(buffer, source, size)
#else
#endif



// C export helper functions to be called from C#
extern "C" {
    // Constructor which returns a heap pointer
    DLLEXPORT munits::Quantity* CALLCONV CreateQuantity(int t, double v, const char * u){
        return new munits::Quantity((munits::metrics) t, v, u);
    };
    // Destructor
    DLLEXPORT void CALLCONV DeleteQuantity(munits::Quantity * q){
        delete q;
    }

    // toString method
    DLLEXPORT void CALLCONV __toString(munits::Quantity * q, char * buffer, unsigned long  * buffer_size){

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
            STRINGCOPY(buffer, size, st.c_str());
        }
        // The string length including the zero terminator
        * buffer_size = size;
    }
    // get value
    DLLEXPORT double CALLCONV __getValue(munits::Quantity * q){
        return q->getValue();
    }
    DLLEXPORT void CALLCONV __getUnit(munits::Quantity * q, char * buffer, unsigned long  * buffer_size){
        if (buffer_size == nullptr)
        {
            return;
        }
        std::string st = q->getUnit();
        unsigned long size = st.length()  + 1;
        if ((buffer != nullptr) && (*buffer_size >= size))
        {
            STRINGCOPY(buffer, size, st.c_str());
        }
        // The string length including the zero terminator
        * buffer_size = size;
    }

    // get type (matrix index)
    DLLEXPORT const int CALLCONV __getType(munits::Quantity * q){
        return q->getMatrixIndex();
    }

    //add
    DLLEXPORT munits::Quantity* CALLCONV __add(munits::Quantity * lft, munits::Quantity * rgh){
        munits::Quantity temp = *lft + *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    //substract
    DLLEXPORT munits::Quantity* CALLCONV __substract(munits::Quantity * lft, munits::Quantity * rgh){
        munits::Quantity temp = *lft - *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    //multiply
    DLLEXPORT munits::Quantity* CALLCONV __multiply(munits::Quantity * lft, munits::Quantity * rgh){
        munits::Quantity temp = *lft * *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    DLLEXPORT munits::Quantity* CALLCONV __multiply_rgh_int(munits::Quantity * lft, int rgh){
        munits::Quantity temp = *lft * rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
   DLLEXPORT munits::Quantity* CALLCONV __multiply_lft_int(int lft, munits::Quantity * rgh){
        munits::Quantity temp = lft * *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    DLLEXPORT munits::Quantity* CALLCONV __multiply_rgh_double(munits::Quantity * lft, double rgh){
        munits::Quantity temp = *lft * rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
   DLLEXPORT munits::Quantity* CALLCONV __multiply_lft_double(double lft, munits::Quantity * rgh){
        munits::Quantity temp = lft * *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    //divide
   DLLEXPORT munits::Quantity* CALLCONV __divide(munits::Quantity * lft, munits::Quantity * rgh){
        munits::Quantity temp = *lft / *rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
   DLLEXPORT munits::Quantity* CALLCONV __divide_int(munits::Quantity * lft, int rgh){
        munits::Quantity temp = *lft / rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }

   DLLEXPORT munits::Quantity* CALLCONV __divide_double(munits::Quantity * lft, double rgh){
        munits::Quantity temp = *lft / rgh;
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }

    //comparison
    DLLEXPORT int CALLCONV __lt(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft < *rgh;
    }
    DLLEXPORT int CALLCONV __gt(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft > *rgh;
    }
    DLLEXPORT int CALLCONV __le(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft <= *rgh;
    }
    DLLEXPORT int CALLCONV __ge(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft >= *rgh;
    }
    DLLEXPORT int CALLCONV __eq(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft == *rgh;
    }
    DLLEXPORT int CALLCONV __ne(munits::Quantity * lft, munits::Quantity * rgh){
        return *lft != *rgh;
    }

    //power function
    DLLEXPORT munits::Quantity * CALLCONV __power(munits::Quantity * lft, int rgh){
        munits::Quantity temp = lft->mpow(rgh);
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    //nt root
    DLLEXPORT munits::Quantity* CALLCONV __ntrt(munits::Quantity * lft, int rgh){
        munits::Quantity temp = lft->ntrt(rgh);
        return new munits::Quantity((munits::metrics) temp.getMatrixIndex(), temp.getValue(), temp.getUnit());
    }
    DLLEXPORT double CALLCONV __get(munits::Quantity * lft, const char* u){
        return lft->operator()(u);
    }

    DLLEXPORT double CALLCONV __double(munits::Quantity * q){
        return q->toDouble();
    }

}

