#include <regex>
#include <iostream>
#include <queue>
#include "Quantity.h"

using namespace std;

munits::ConverterFunction::ConverterFunction( double a,  double b=0, const char* s ="Default"): first_order(a), zero_order(b),signature(s){}

 double munits::ConverterFunction::to_base( double v,  double e=1) const {
    return (v * pow(first_order, e)) + (e==1?zero_order:0);
}

 double munits::ConverterFunction::from_base( double v,  double e = 1) const {
    return v * pow(first_order, -e) - (e==1?zero_order:0);
}

 double munits::Converter::Convert( double val, munits::UnitNotation funit, munits::UnitNotation tunit,  double exponent) const {


    if (!units.count(funit.GetUnit()) == 1) {
        throw logic_error("Invalid funit: " + string(funit));
    }
    else {
        shared_ptr<Unit> to_base_func_unit = units.find(funit.GetUnit())->second;
        shared_ptr<ConverterFunction> to_base_func_prefix =1 == prefixes.count(funit.GetPrefix()) ? prefixes.find(funit.GetPrefix())->second: make_shared<ConverterFunction>(ConverterFunction(1., 0, ""));

        val = to_base_func_prefix->to_base(val, to_base_func_unit->ignor_exponent?1:exponent);
        val = to_base_func_unit->to_base(val, to_base_func_unit->ignor_exponent?1:exponent);

    }
    if (!units.count(tunit.GetUnit()) == 1) {
        throw logic_error("Invalid tunit: " + string(tunit));
    }
    else {
        shared_ptr<Unit> from_base_func_unit = units.find(tunit.GetUnit())->second;
        shared_ptr<ConverterFunction> from_base_func_prefix =1 == prefixes.count(tunit.GetPrefix()) ? prefixes.find(tunit.GetPrefix())->second: make_shared<ConverterFunction>(ConverterFunction(1., 0, ""));

        val = from_base_func_prefix->from_base(val, from_base_func_unit->ignor_exponent?1:exponent);
        val = from_base_func_unit->from_base(val, from_base_func_unit->ignor_exponent?1:exponent);

    }



    return val;
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

munits::Converter::Converter(string base_unit, const set<string> & remove, const map<string, const shared_ptr<Unit>> additional_units):
                             base_unit(base_unit), units(additional_units){

    const map<string, const shared_ptr<munits::ConverterFunction>> refixes = GetPrefixes();

    for(auto prx = refixes.begin(); prx != refixes.end(); prx++){
        if (remove.find(prx->first) == remove.end()){ // removing prefixes which are not usable in the given unit type
            prefixes.insert(pair<string, const shared_ptr<munits::ConverterFunction>>(prx->first, prx->second));
        }
    }
    units.insert(pair<string, const shared_ptr<munits::Unit>>(base_unit, make_shared<munits::Unit>(munits::Unit(1., 0., base_unit.c_str()))));
}

bool munits::Converter::is_valid_unit(const UnitNotation & unit) const {

    bool isv = (1 == units.count(unit.GetUnit()) && (unit.GetPrefix() == ""?true :1 == prefixes.count(unit.GetPrefix())));
    return isv;
}

munits::Metric::Metric(vector<int> dim_vector, string base_unit, set<string> remove, const map<string, const shared_ptr<munits::Unit>> additional_units ):
                       dim_vector(dim_vector), converter(make_shared<Converter>(base_unit, remove, additional_units)){};

const vector<munits::Metric> & munits::GetMatrix() {
    static const vector<munits::Metric> matrix = {
            {{1, 0, 0, 0, 0, 0, 0}, "m", {},
                    {
                            {"inc", make_shared<munits::Unit>(munits::Unit(0.0254, 0., "inc"))},
                            {"ft", make_shared<munits::Unit>(munits::Unit(0.3048, 0., "ft"))},
                            {"mi", make_shared<munits::Unit>(munits::Unit(1609.344, 0., "mi"))},
                            {"yd", make_shared<munits::Unit>(munits::Unit(0.914, 0., "yd"))}
                    }

            }, //Length
            {{0, 1, 0, 0, 0, 0, 0}, "g", {}, // Mass
                    {
                        {"oz", make_shared<munits::Unit>(munits::Unit(28.3495, 0., "oz"))},
                        {"lb", make_shared<munits::Unit>(munits::Unit(453.592, 0., "lb"))},
                        {"t", make_shared<munits::Unit>(munits::Unit(1e6, 0., "t"))},

                    }
            },
            {{0, 0, 1, 0, 0, 0, 0}, "s", {}, //Time
                    {
                             {"min", make_shared<munits::Unit>(munits::Unit(60., 0., "min", false))},
                             {"h", make_shared<munits::Unit>(munits::Unit(3600., 0., "h", false))},
                             {"d", make_shared<munits::Unit>(munits::Unit(86400., 0., "d", false))}
                    }
            },
            {{0, 0, 0, 1, 0, 0, 0}, "A"},  //Electric Currency
            {{0, 0, 0, 0, 1, 0, 0}, "K",  //Temperature
                    {"E", "P", "T", "G", "M", "k", "h", "da", "d", "c", "m", "μ", "n", "p", "f", "a"},
                    {
                            {"°C", make_shared<munits::Unit>(munits::Unit(1., 273.15, "C" , false))},
                            {"°F", make_shared<munits::Unit>(munits::Unit(1., 273.15, "F", false))} // TODO: correct parameters
                    }
            },
            {{0, 0, 0, 0, 0, 1, 0}, "mol"},  //Amount of Substance
            {{0, 0, 0, 0, 0, 0, 1}, "cd"} , //Luminous Intensity
            {{2, 0, 0, 0, 0, 0, 0}, "m"}, //Area
            {{3, 0, 0, 0, 0, 0, 0}, "m", {}, //Volume
                    {
                            {"l", make_shared<munits::Unit>(munits::Unit(0.001, 0., "l", true, true))},
                            {"gal", make_shared<munits::Unit>(munits::Unit(0.15584912791, 0., "gal", true, true))},
                            {"oz", make_shared<munits::Unit>(munits::Unit(2.957e-5, 0., "oz", true, true))}
                    }

            },
            {{3, 0, -1, 0, 0, 0, 0}, "m3 s-1"},  //VolumetricFlow
            {{-3, 0, 0, 0, 0, 1, 0}, "mol m-3"}  //MolarConcentration
    };
    return matrix;
}


vector<munits::UnitNotation> munits::Quantity::compose_unit_vector(const string &unit) const {

    istringstream iss(unit);
    vector<string> tokens;
    vector<UnitNotation> unTokens;

    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens)); // splitting up string representations (by default at " ")

    for(auto unt = tokens.begin(); unt != tokens.end(); ++unt){ // composing UnitNotation objects from string representations
        unTokens.push_back(UnitNotation(*unt));
    }

    const vector<munits::Metric> & rmatrix = munits::GetMatrix();

    vector<UnitNotation> uv = {UnitNotation(), UnitNotation(), UnitNotation(), UnitNotation(), UnitNotation(), UnitNotation(), UnitNotation() }; // creating default 7 element long unit vector

    for(int ui = 0; ui < 7; ++ui){ // checking if any of the tokens is a base unit
        for(auto b = unTokens.begin(); b != unTokens.end();){
            if (rmatrix[ui].converter->is_valid_unit(*b)){
                uv[ui] = *b;
                unTokens.erase(b);
            }
            else{
                ++b;
            }
        }
    }
    if (unTokens.size() != 0){ // if no tokens left no point checking for none base units
        for(int uii = 7; uii < _Last; ++uii){  // checking if any of the tokens is a none base unit
            for(auto b = unTokens.begin(); b != unTokens.end();){
                if (rmatrix[uii].converter->is_valid_unit(*b)){
                    int position = 0;
                    while(rmatrix[uii].dim_vector[position] == 0 && position < 6){ // searching the position where the dim_vector is not 0
                        ++position;
                    };
                        uv[position] = UnitNotation(*b);
                        unTokens.erase(b);
                }
                else{
                    ++b;
                }
            }
        }
    }
    if (unTokens.size() != 0){ // if any tokens left it means that what was left is invalid.
        throw std::logic_error("Incorrect unit: " + unit);
    };
    return uv;
}


string munits::Quantity::compose_unit(const vector<UnitNotation> & uv){
    stringstream tmp;
    for(auto unit = uv.begin(); unit != uv.end(); ++unit){
        if (unit->GetUnit() != "") {
            tmp << unit->GetPrefix() << unit->GetUnit() << (unit->GetExponent()!=1?to_string(unit->GetExponent()):"");
        }
        if (unit != uv.end()-1 && (unit+1)->GetUnit() != ""){
            tmp << " ";
        }
    };
    return tmp.str();
};


 double munits::Quantity::operator()(const string tunit) const {


    const vector<Metric> & rmatrix = GetMatrix();
    const vector<int> & dim_vector = GetDimVector(); // dime vector of current munits
    queue<vector<int>> dim_matrix; // the search matrix composed by tearing down the dim_vector

    vector<UnitNotation> tunit_vector = compose_unit_vector(tunit);

    for(int i = 0; i < 7; ++i){
        if(dim_vector[i] !=0){
            vector<int> tmp_dim_vector = {0,0,0,0,0,0,0};
            tmp_dim_vector[i] = abs(dim_vector[i]);
            dim_matrix.push(tmp_dim_vector);
        }
    }

    double tmp = value;

    while(!dim_matrix.empty()){
        vector<int> dmv = dim_matrix.front();
        int position = 0;
        while((dmv)[position] == 0 && position < 6){ // searching the position where the dim_vector is not 0
            ++position;
        };

        for(auto q = rmatrix.begin(); q != rmatrix.end(); ++q){
            vector<int> normalized_dim = {0,0,0,0,0,0,0};
            normalized_dim[position] = 1;

            if((q->dim_vector == dmv || q->dim_vector == normalized_dim) &&(q->converter->is_valid_unit(unit_vector[position]) && q->converter->is_valid_unit(tunit_vector[position]))){
                tmp = q->converter->Convert(tmp, unit_vector[position], tunit_vector[position], dim_vector[position]);
                dim_matrix.pop();
                break; // TODO: could integrate condition into loop criteria.
            }
        }
        if(dmv == dim_matrix.front()){
            throw logic_error("Invalid unit: " + tunit);
        }
    }

    return tmp;

}


munits::Quantity munits::Quantity::mathop(const Quantity &a, const Quantity &b, int p) {

    const vector<Metric> & rmatrix = GetMatrix();
    vector<UnitNotation> nunit_vector(7);
    vector<int> ndim_vector = {0, 0, 0, 0, 0, 0, 0};
    double tmp = b.value;

    for(int i = 0; i < ndim_vector.size(); ++i){
        ndim_vector[i] = a.GetDimVector()[i] + p * b.GetDimVector()[i]; // composing the new dimension vector (exponents)
        if (a.GetDimVector()[i] != 0 && b.GetDimVector()[i] !=0){ // checking if there is a common dimension
            tmp = rmatrix[i].converter->Convert(tmp, b.unit_vector[i], a.unit_vector[i]); // converting if there is a common dimension in both units
        }
        nunit_vector[i] = a.GetDimVector()[i] != 0?a.unit_vector[i]:b.unit_vector[i]; // composing the new unit vector (units)
    }

    int nmindex = 0;
    while(nmindex < _Last && ndim_vector != rmatrix[nmindex].dim_vector){ // determining the unit type by searching a the matching dimension vector
        ++nmindex;
    }

    return Quantity(nmindex, a.value * pow(tmp, p), nunit_vector);
};


munits::Quantity::Quantity(munits::Quantity::metrics m,  double value, const string unit):
        matrix_index(m), value(value), converter(munits::GetMatrix()[m].converter), unit_vector(this->compose_unit_vector(unit)){
}


munits::Quantity::Quantity(int i,  double value, vector<UnitNotation> uv):matrix_index(i), value(value),
                                                                            unit_vector(uv), converter(munits::GetMatrix()[i].converter) {
}

bool munits::Quantity::compop(const munits::Quantity &a, const munits::Quantity &b, bool (*f)(const double &, const double &)) {
    if (a.matrix_index == b.matrix_index) { // if the matrix indexes do not match they are not the same types and comparison is not possible
        return f(a.value, b(Quantity::compose_unit(a.unit_vector))); // converting 'b' to the same unit as 'a' and comparing there value
    }
    else{
        throw logic_error("Comparison cannot be done! Measurement unit types do not match. ( '" + Quantity::compose_unit(a.unit_vector) + "', '" + Quantity::compose_unit(b.unit_vector) +"' )" );
    }
}


vector<string> munits::UnitNotation::parser(string unit) {
    const vector<munits::Metric> & rmatrix = munits::GetMatrix();
    vector<string> parsed = {"", "", ""};

    bool no_matc = true;

    for(int u = 0; u < Quantity::_Last && no_matc; ++u) {
        stringstream rp;
        { // composing the regex for each unit type
            rp << "^(";
            const map<string, const shared_ptr<ConverterFunction>> &prefixes = rmatrix[u].converter->Prefixes();
            int c1 = 0;
            for (auto prx = prefixes.begin(); prx != prefixes.end(); ++prx) {
                rp << prx->first << (c1 != prefixes.size() - 1 ? "|" : "");
                ++c1;
            }

            rp << ")?(";
            c1 = 0;
            const map<string, const shared_ptr<Unit>> &units = rmatrix[u].converter->Units();
            for (auto unt = units.begin(); unt != units.end(); ++unt) {
                rp << unt->first << (c1 != units.size() - 1 ? "|" : "");
                ++c1;
            }

            rp << ")(\\-?[0-9])?$";
        }
        try {
            regex re(rp.str());
            sregex_iterator next(unit.begin(), unit.end(), re);
            sregex_iterator end;
            while (next != end) {
                smatch match = *next;

                if(string(match[1])+string(match[2])+string(match[3]) == unit){
                    no_matc = false;
                    parsed[0] = match[1];
                    parsed[1] = match[2];
                    parsed[2] = match[3];
                }
                next++;
            }
        }
        catch (regex_error &e) {

        }
    }

    return parsed;
}


munits::UnitNotation::UnitNotation(string u) {

    vector<string> parsed = parser(u);

    prefix = parsed[0];
    unit = parsed[1];
    int exp = atoi(parsed[2].c_str());
    exponent = exp != 0 ? exp : 1; //if atoi fails then the returned value is 0

}




