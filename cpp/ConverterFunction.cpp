//
// Created by bmolnar on 2016. 06. 20..
//

#include "ConverterFunction.h"


quantity::ConverterFunction::ConverterFunction(double a, double b): first_order(a), zero_order(b){ }

double quantity::ConverterFunction::to_base(double v, double e=1) const {

    return (v * pow(first_order, e)) + (e==1?zero_order:0);
}

double quantity::ConverterFunction::from_bsas(double v, double e = 1) const {
    return v * pow(first_order, -e) - (e==1?zero_order:0);
}



double quantity::Converter::operator()(double val, std::string funit, std::string tunut, double exponent) const {

    const ConverterFunction * to_base_func;
    const ConverterFunction * from_base_func;

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

        double res = from_base_func->from_bsas(in_base, exponent);
        return res;
    }




const std::map<std::string, quantity::ConverterFunction> & quantity::Converter::GetPrefixes() const {

    static const std::map<std::string, quantity::ConverterFunction> prefixes  = {
            {"E", ConverterFunction(1e18)}, //exa
            {"P", ConverterFunction(1e15)},  // peta
            {"T", ConverterFunction(1e12)},  // tera
            {"G", ConverterFunction(1e9)}, // giga
            {"M", ConverterFunction(1e6)},  // mega
            {"k", ConverterFunction(1e3)},  // kilo
            {"h", ConverterFunction(1e2)},  // hecto
            {"da", ConverterFunction(1e1)},  // deca
            {"", ConverterFunction(1.)},
            {"d", ConverterFunction(0.1)},   // deci
            {"c", ConverterFunction(0.01)},  // centi
            {"m", ConverterFunction(0.001)},  // milli
            {"μ", ConverterFunction(0.000001)},  // micro
            {"n", ConverterFunction(0.000000001)},  // nano
            {"p", ConverterFunction(0.000000000001)},  // pico
            {"f", ConverterFunction(0.000000000000001)},  // femto
            {"a", ConverterFunction(0.000000000000000001)}  // atto
    };

 return prefixes;
}

quantity::Converter::Converter(std::string base_unit): base_unit(base_unit){
    const std::map<std::string, quantity::ConverterFunction> prefixes = GetPrefixes();
    for(auto b = prefixes.begin(); b != prefixes.end(); b++){
        units[b->first + base_unit] = &b->second;
    }

}





