

#ifndef MUSYS_CONVERTER_H
#define MUSYS_CONVERTER_H

#include <math.h>
#include <string>
#include <map>

namespace quantity {

    class ConverterFunction {

    private:
        double first_order;
        double zero_order;
    public:
        double to_base(double, double) const;

        double from_bsas(double, double) const;

        ConverterFunction(double, double=0);

    };

    class Converter {

    private:
        const std::map<std::string, ConverterFunction> & GetPrefixes() const;
        std::string base_unit;
        std::map<std::string, const ConverterFunction*> units;
    protected:
        std::map<std::string, const ConverterFunction*> additional_units;
    public:
        Converter(std::string);
        double operator()(double, std::string, std::string, double=1) const;
    };

}
#endif //MUSYS_CONVERTER_H
