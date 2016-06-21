

#ifndef MUSYS_CONVERTER_H
#define MUSYS_CONVERTER_H

#include <math.h>
#include <string>
#include <map>
#include <set>
#include <string>
#include <memory>

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

}
#endif //MUSYS_CONVERTER_H
