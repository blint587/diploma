#include "Quantity.h"

quantity::ConverterFunction::ConverterFunction(double a, double b): first_order(a), zero_order(b){ }

double quantity::ConverterFunction::to_base(double v, double e=1) const {

    return (v * pow(first_order, e)) + (e==1?zero_order:0);
}

double quantity::ConverterFunction::from_bsas(double v, double e = 1) const {
    return v * pow(first_order, -e) - (e==1?zero_order:0);
}

double quantity::Converter::Convert(double val, std::string funit, std::string tunut, double exponent) const {

    std::shared_ptr<ConverterFunction> to_base_func;
    std::shared_ptr<ConverterFunction> from_base_func;

    if (1 == units.count(funit)){
        to_base_func = units.find(funit)->second;
    }
    else if (1 == additional_units.count(funit)) {
        to_base_func = additional_units.find(funit)->second;
    }
    else{
        throw "Invalid unit"; // TODO: Throw proper exception
    }
    if (1 == units.count(tunut)){
        from_base_func = units.find(tunut)->second;
    }
    else if (1 == additional_units.count(tunut)){
        from_base_func = additional_units.find(tunut)->second;

    }
    else{
        throw "Invalid unit"; // TODO: Throw proper exception
    }


    double in_base = to_base_func->to_base(val, exponent);

    return from_base_func->from_bsas(in_base, exponent);

}

const std::map<std::string, const std::shared_ptr<quantity::ConverterFunction>> & quantity::Converter::GetPrefixes() const {

    static const std::map<std::string, const std::shared_ptr<quantity::ConverterFunction>> prefixes  = {
            {"E", std::make_shared<ConverterFunction>(ConverterFunction(1e18))}, //exa
            {"P", std::make_shared<ConverterFunction>(ConverterFunction(1e15))},  // peta
            {"T", std::make_shared<ConverterFunction>(ConverterFunction(1e12))},  // tera
            {"G", std::make_shared<ConverterFunction>(ConverterFunction(1e9))}, // giga
            {"M", std::make_shared<ConverterFunction>(ConverterFunction(1e6))},  // mega
            {"k", std::make_shared<ConverterFunction>(ConverterFunction(1e3))},  // kilo
            {"h", std::make_shared<ConverterFunction>(ConverterFunction(1e2))},  // hecto
            {"da", std::make_shared<ConverterFunction>(ConverterFunction(1e1))},  // deca
            {"", std::make_shared<ConverterFunction>(ConverterFunction(1.))},
            {"d", std::make_shared<ConverterFunction>(ConverterFunction(0.1))},   // deci
            {"c", std::make_shared<ConverterFunction>(ConverterFunction(0.01))},  // centi
            {"m", std::make_shared<ConverterFunction>(ConverterFunction(0.001))},  // milli
            {"μ", std::make_shared<ConverterFunction>(ConverterFunction(0.000001))},  // micro
            {"n", std::make_shared<ConverterFunction>(ConverterFunction(0.000000001))},  // nano
            {"p", std::make_shared<ConverterFunction>(ConverterFunction(0.000000000001))},  // pico
            {"f", std::make_shared<ConverterFunction>(ConverterFunction(0.000000000000001))},  // femto
            {"a", std::make_shared<ConverterFunction>(ConverterFunction(0.000000000000000001))}  // atto
    };

    return prefixes;
}

quantity::Converter::Converter(std::string base_unit,
                               const std::set<std::string> & remove,
                               const std::map<std::string, const std::shared_ptr<ConverterFunction>> additional_units):
        base_unit(base_unit), additional_units(additional_units){



    const std::map<std::string, const std::shared_ptr<quantity::ConverterFunction>> prefixes = GetPrefixes();

    for(auto b = prefixes.begin(); b != prefixes.end(); b++){
        std::string prefix = b->first;
        if (remove.find(prefix) == remove.end()){
            units.insert(std::pair<std::string, const std::shared_ptr<quantity::ConverterFunction>>(b->first + base_unit, b->second));
        }
    }
#ifdef DEBUG
    std::cout << "Creating converter with " << base_unit << " at " << this<< std::endl;
#endif
}

bool quantity::Converter::is_valid_unit(const std::string & unit) const {
    return 1 == units.count(unit) ||  1 == additional_units.count(unit);
}

quantity::Metric:: Metric(std::vector<int> dim_vector,
                          std::string base_unit,
                          std::set<std::string> remove,
                          const std::map<std::string, const std::shared_ptr<quantity::ConverterFunction>> additional_units ):
        dim_vector(dim_vector), converter(std::make_shared<Converter>(base_unit, remove, additional_units)){};

const std::vector<quantity::Metric> & quantity::Quantity::GetMatrix() const {
    static const std::vector<quantity::Metric> matrix = {
            {{1, 0, 0, 0, 0, 0, 0}, "m"}, //Length
            {{0, 1, 0, 0, 0, 0, 0}, "g"}, // Mass
            {{0, 0, 1, 0, 0, 0, 0}, "s"},  //Time
            {{0, 0, 0, 1, 0, 0, 0}, "A"},  //Electric Currency
            {{0, 0, 0, 0, 1, 0, 0}, "K", {"E", "P", "T", "G", "M", "k", "h", "da", "d", "c", "m", "μ", "n", "p", "f", "a"},//Temperature
                    {
                            {"°C", std::make_shared<quantity::ConverterFunction>(quantity::ConverterFunction(1., 273.15))},
                            {"°F", std::make_shared<quantity::ConverterFunction>(quantity::ConverterFunction(1., 273.15))},
                    }
            },
            {{0, 0, 0, 0, 0, 1, 0}, "mol"},  //Amount of Substance
            {{0, 0, 0, 0, 0, 0, 1}, "cd"}  //Luminous Intensity
    };
    return matrix;
}


quantity::Quantity::Quantity(quantity::Quantity::metrics m, double value, const std::string unit):
        matrix_index(m), value(value), unit(unit){
    converter = quantity::Quantity::GetMatrix()[m].converter;
}

double quantity::Quantity::operator()(const std::string tunit) const {
    if (converter->is_valid_unit(tunit)) {

        return this->converter->Convert(value, unit, tunit);

    }
    else{
        throw "invalid Unit";
    }
}

bool quantity::Quantity::is_valid_unit() const {
    return converter->is_valid_unit(unit);
}



