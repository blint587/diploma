#include <string>
#include "converter.hpp"

using namespace std;

double munits::Converter::Convert( double val, munits::UnitNotation funit, munits::UnitNotation tunit,  double exponent) const {


    if (!units.count(funit.GetUnit()) == 1) {
        throw logic_error("Invalid funit: " + string(funit));
    }
    else {
        shared_ptr<Unit> to_base_func_unit = units.find(funit.GetUnit())->second;
        shared_ptr<ConverterFunction> to_base_func_prefix = (1 == prefixes.count(funit.GetPrefix()) ? prefixes.find(funit.GetPrefix())->second: make_shared<ConverterFunction>(ConverterFunction(1., 0, "")));

        val = to_base_func_prefix->to_base(val, to_base_func_unit->ignor_exponent?(exponent > 0?1:-1):exponent);
        val = to_base_func_unit->to_base(val, to_base_func_unit->ignor_exponent?(exponent > 0?1:-1):exponent);

    }
    if (!units.count(tunit.GetUnit()) == 1) {
        throw logic_error("Invalid tunit: " + string(tunit));
    }
    else {
        shared_ptr<Unit> from_base_func_unit = units.find(tunit.GetUnit())->second;
        shared_ptr<ConverterFunction> from_base_func_prefix =(1 == prefixes.count(tunit.GetPrefix()) ? prefixes.find(tunit.GetPrefix())->second: make_shared<ConverterFunction>(ConverterFunction(1., 0, "")));

        val = from_base_func_prefix->from_base(val, from_base_func_unit->ignor_exponent?(exponent > 0?1:-1):exponent);
        val = from_base_func_unit->from_base(val, from_base_func_unit->ignor_exponent?(exponent > 0?1:-1):exponent);

    }



    return val;
}

bool munits::Converter::is_valid_unit(const UnitNotation & unit) const {

    bool isv = (1 == units.count(unit.GetUnit()) && (unit.GetPrefix() == ""?true :1 == prefixes.count(unit.GetPrefix())));
    return isv;
}

munits::Converter::Converter(string base_unit, const set<string> & remove, const map<string, const shared_ptr<Unit>> additional_units):
        base_unit(base_unit), units(additional_units){

    const map<string, const shared_ptr<munits::ConverterFunction>> refixes = GetPrefixes();

    for(auto prx = refixes.begin(); prx != refixes.end(); prx++){
        if (remove.find(prx->first) == remove.end()){ // removing prefixes which are not usable in the given Unit type
            prefixes.insert(pair<string, const shared_ptr<munits::ConverterFunction>>(prx->first, prx->second));
        }
    }
    units.insert(pair<string, const shared_ptr<munits::Unit>>(base_unit, make_shared<munits::Unit>(Unit(1., 0., base_unit.c_str()))));
}

const map<string, const shared_ptr<munits::ConverterFunction>> & munits::Converter::GetPrefixes() const {

    static const map<string, const shared_ptr<munits::ConverterFunction>> prefixes  = {
            {"E", make_shared<ConverterFunction>(ConverterFunction(1e18, 0,"E"))}, //exa
            {"P", make_shared<ConverterFunction>(ConverterFunction(1e15, 0,"P"))},  // peta
            {"T", make_shared<ConverterFunction>(ConverterFunction(1e12, 0,"I"))},  // tera
            {"G", make_shared<ConverterFunction>(ConverterFunction(1e9, 0,"G"))}, // giga
            {"M", make_shared<ConverterFunction>(ConverterFunction(1e6, 0,"M"))},  // mega
            {"k", make_shared<ConverterFunction>(ConverterFunction(1e3, 0,"k"))},  // kilo
            {"h", make_shared<ConverterFunction>(ConverterFunction(1e2, 0, "h"))},  // hecto
            {"da", make_shared<ConverterFunction>(ConverterFunction(1e1, 0, "da"))},  // deca
//            {"", make_shared<ConverterFunction>(ConverterFunction(1., 0, ""))},
            {"d", make_shared<ConverterFunction>(ConverterFunction(0.1, 0, "d"))},   // deci
            {"c", make_shared<ConverterFunction>(ConverterFunction(0.01, 0, "c"))},  // centi
            {"m", make_shared<ConverterFunction>(ConverterFunction(0.001, 0, "m"))},  // milli
            {"μ", make_shared<ConverterFunction>(ConverterFunction(0.000001, 0, "mikro"))},  // micro
            {"n", make_shared<ConverterFunction>(ConverterFunction(0.000000001, 0, "n"))},  // nano
            {"p", make_shared<ConverterFunction>(ConverterFunction(0.000000000001, 0, "p"))},  // pico
            {"f", make_shared<ConverterFunction>(ConverterFunction(0.000000000000001, 0, "f"))},  // femto
            {"a", make_shared<ConverterFunction>(ConverterFunction(0.000000000000000001, 0, "a"))}  // atto
    };

    return prefixes;
}