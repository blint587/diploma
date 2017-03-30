#include <string>
#include "converter.hpp"
#include "dynamic.hpp"
#include "../lib/Accesories/accessories.hpp"

using namespace std;

double munits::Converter::Convert( double val, munits::UnitNotation funit, munits::UnitNotation tunit,  int exponent) const {

    TRACE("from unit: " + (std::string)funit);
    TRACE("to unit: " + (std::string)tunit);

    if (!units.count(funit.GetUnit()) == 1) {
        throw logic_error("Invalid funit: " + string((std::string  &&) funit));
    }
    else {
        shared_ptr<Unit> to_base_func_unit = units.find(funit.GetUnit())->second;
        shared_ptr<ConverterFunction> to_base_func_prefix = (1 == prefixes.count(funit.GetPrefix()) ? prefixes.find(funit.GetPrefix())->second: make_shared<ConverterFunction>(ConverterFunction(1, 0, "")));

        val = to_base_func_prefix->to_base(val, to_base_func_unit->ignor_exponent?(exponent > 0?1:-1):exponent);
        val = to_base_func_unit->to_base(val, to_base_func_unit->ignor_exponent?(exponent > 0?1:-1):exponent);

    }
    if (!units.count(tunit.GetUnit()) == 1) {
        throw logic_error("Invalid tunit: " + string((std::string &&) tunit));
    }
    else {
        shared_ptr<Unit> from_base_func_unit = units.find(tunit.GetUnit())->second;
        shared_ptr<ConverterFunction> from_base_func_prefix =(1 == prefixes.count(tunit.GetPrefix()) ? prefixes.find(tunit.GetPrefix())->second: make_shared<ConverterFunction>(ConverterFunction(1, 0, "")));

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

    const map<string, const shared_ptr<munits::ConverterFunction>> prefixes = munits::GetPrefixes();

    for(auto prx = prefixes.begin(); prx != prefixes.end(); prx++){
        if (remove.find(prx->first) == remove.end()){ // removing prefixes which are not usable in the given Unit type
            this->prefixes.insert(pair<string, const shared_ptr<munits::ConverterFunction>>(prx->first, prx->second));
        }
    }
    units.insert(pair<string, const shared_ptr<munits::Unit>>(base_unit, make_shared<munits::Unit>(Unit(1., 0., base_unit.c_str()))));
}

