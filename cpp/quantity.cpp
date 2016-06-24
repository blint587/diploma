#include <regex>
#include "Quantity.h"

using namespace std;

quantity::ConverterFunction::ConverterFunction(double a, double b=0, const char* s ="Default"): first_order(a), zero_order(b), signature(s){
//#ifdef DEBUG
//    cout << "Cnverter Function has been initialized with signature: " << signature << " " << a << " " << b << endl;
//#endif

}

double quantity::ConverterFunction::to_base(double v, double e=1) const {

    return (v * pow(first_order, e)) + (e==1?zero_order:0);
}

double quantity::ConverterFunction::from_base(double v, double e = 1) const {
    return v * pow(first_order, -e) - (e==1?zero_order:0);
}

double quantity::Converter::Convert(double val, string funit, string tunit, double exponent) const {


    UnitNotation from_unit(funit);
    UnitNotation to_unit(tunit);


    if (!units.count(from_unit.GetUnit()) == 1) {cout << "invalid unit "<< funit << endl; }
    shared_ptr<Unit> to_base_func_unit = units.find(from_unit.GetUnit())->second;
    shared_ptr<ConverterFunction> to_base_func_prefix =  1 == prefixes.count(from_unit.GetPrefix())?prefixes.find(from_unit.GetPrefix())->second:make_shared<ConverterFunction>(ConverterFunction(1., 0, ""));


    shared_ptr<Unit> from_base_func_unit = units.find(to_unit.GetUnit())->second;
    shared_ptr<ConverterFunction> from_base_func_prefix = 1 ==  prefixes.count(to_unit.GetPrefix())? prefixes.find(to_unit.GetPrefix())->second:make_shared<ConverterFunction>(ConverterFunction(1., 0, ""));

    val = to_base_func_prefix->to_base(val, to_base_func_unit->ignor_exponent?1:exponent);
    val = to_base_func_unit->to_base(val, to_base_func_unit->ignor_exponent?1:exponent);

    val = from_base_func_prefix->from_base(val, from_base_func_unit->ignor_exponent?1:exponent);
    val = from_base_func_unit->from_base(val, from_base_func_unit->ignor_exponent?1:exponent);

    return val;
}

const map<string, const shared_ptr<quantity::ConverterFunction>> & quantity::Converter::GetPrefixes() const {

    static const map<string, const shared_ptr<quantity::ConverterFunction>> prefixes  = {
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

quantity::Converter::Converter(string base_unit,
                               const set<string> & remove,
                               const map<string, const shared_ptr<Unit>> additional_units):
        base_unit(base_unit), units(additional_units){



    const map<string, const shared_ptr<quantity::ConverterFunction>> refixes = GetPrefixes();

    for(auto prx = refixes.begin(); prx != refixes.end(); prx++){
        if (remove.find(prx->first) == remove.end()){
            prefixes.insert(pair<string, const shared_ptr<quantity::ConverterFunction>>(prx->first, prx->second));
        }
    }

    units.insert(pair<string, const shared_ptr<quantity::Unit>>(
            base_unit, make_shared<quantity::Unit>(quantity::Unit(1., 0., base_unit.c_str()))));

#ifdef DEBUG
    cout << "Creating converter with " << base_unit << " at " << this<< endl;
#endif
}

bool quantity::Converter::is_valid_unit(const UnitNotation & unit) const {

    bool isv = 1 == units.count(unit.GetUnit()) && (unit.GetPrefix() == ""?true :1 == prefixes.count(unit.GetPrefix()));
    return isv;
}

quantity::Metric::Metric(vector<int> dim_vector,
                          string base_unit,
                          set<string> remove,
                          const map<string, const shared_ptr<quantity::Unit>> additional_units ):
        dim_vector(dim_vector), converter(make_shared<Converter>(base_unit, remove, additional_units)){};

const vector<quantity::Metric> & quantity::GetMatrix() {
    static const vector<quantity::Metric> matrix = {
            {{1, 0, 0, 0, 0, 0, 0}, "m"}, //Length
            {{0, 1, 0, 0, 0, 0, 0}, "g"}, // Mass
            {{0, 0, 1, 0, 0, 0, 0}, "s", {}, //Time
                    {
                             {"min", make_shared<quantity::Unit>(quantity::Unit(60., 0., "min",false))},
                             {"h", make_shared<quantity::Unit>(quantity::Unit(3600., 0., "h",false))},
                             {"d", make_shared<quantity::Unit>(quantity::Unit(86400., 0., "d",false))}
                    }
            },
            {{0, 0, 0, 1, 0, 0, 0}, "A"},  //Electric Currency
            {{0, 0, 0, 0, 1, 0, 0}, "K", {"E", "P", "T", "G", "M", "k", "h", "da", "d", "c", "m", "μ", "n", "p", "f", "a"},//Temperature
                    {
                            {"°C", make_shared<quantity::Unit>(quantity::Unit(1., 273.15, "C" ,false))},
                            {"°F", make_shared<quantity::Unit>(quantity::Unit(1., 273.15, "F",false))},
                    }
            },
            {{0, 0, 0, 0, 0, 1, 0}, "mol"},  //Amount of Substance
            {{0, 0, 0, 0, 0, 0, 1}, "cd"} , //Luminous Intensity
            {{2, 0, 0, 0, 0, 0, 0}, "m"}, //Area
            {{3, 0, 0, 0, 0, 0, 0}, "m", {}, //Volume
                    {
                            {"l", make_shared<quantity::Unit>(quantity::Unit(0.001, 0., "l", true, true))}
                    }

            },
            {{3, 0, -1, 0, 0, 0, 0}, "m"},  //VolumetricFlow
            {{-3, 0, 0, 0, 0, 1, 0}, "mol m"}  //Concentration
    };
    return matrix;
}


vector<string> quantity::Quantity::compose_unit_vector(const string & unit) const {
    vector<string> uv = {"", "","", "", "", "", "" };
    istringstream iss(unit);
    vector<string> tokens;

    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(tokens));

    const vector<quantity::Metric> & rmatrix = quantity::GetMatrix();
    cout << unit << endl;
    for(int ui = 0; ui < 7; ++ui){
        for(auto b = tokens.begin(); b != tokens.end();){
            if (rmatrix[ui].converter->is_valid_unit(*b)){

                uv[ui] = *b;
                tokens.erase(b);
            }
            else{
                ++b;
            }
        }
    }
    for(int uii = 7; uii < _Last; ++uii){
        for(auto b = tokens.begin(); b != tokens.end();){
            if (rmatrix[uii].converter->is_valid_unit(*b)){

                    uv[0] = *b;
                    tokens.erase(b);
                }
                else{
                    ++b;
                }
            }
        }

    return uv;
}


string quantity::Quantity::compose_unit(const vector<string> & uv) const {
    stringstream tmp;
    for(int idx = 0; idx < 7; idx++){
        if (uv[idx] != "") {
            tmp << uv[idx];
        }
        if (idx != 6 && uv[idx+1] != ""){
            tmp << " ";
        }
    };
    return tmp.str();
};


double quantity::Quantity::operator()(const string tunit) const {

    UnitNotation unit(tunit);
    vector<string> tmp_unit_vector = quantity::Quantity::compose_unit_vector(unit.GetUnit());

    const vector<Metric> & rmatrix = GetMatrix();

    double tmp = value;

    for(int pos = 0; pos < _Last; ++pos){
        for(int unitpos = 0; unitpos < 7 ; ++unitpos){
#ifdef DEBUG

#endif
            if(rmatrix[pos].converter->is_valid_unit(tmp_unit_vector[unitpos]) && rmatrix[pos].dim_vector[unitpos] == abs(unit.GetExponent())){

                std::string funit = unit_vector[unitpos];
                std::string tunit_ = tmp_unit_vector[unitpos];
                int exp = GetDimVector()[unitpos];

                tmp = rmatrix[pos].converter->Convert(tmp, funit, tunit_, exp);
                tmp_unit_vector[unitpos] = "";
            }

        }

    }
    return tmp;

}

bool quantity::Quantity::is_valid_unit() const {
    return converter->is_valid_unit(unit);
}


quantity::Quantity quantity::Quantity::mathop(const Quantity &a, const Quantity &b, int p) {
    const vector<Metric> & rmatrix = GetMatrix();
    vector<string> nunit_vector = {"", "", "", "", "", "", ""};

    vector<int> ndim_vector = {0, 0, 0, 0, 0, 0, 0};

    int nmindex = 0;
    double tmp = b.value;

    for(int i = 0; i < 7; ++i){
        ndim_vector[i] = a.GetDimVector()[i] + p * b.GetDimVector()[i];
        if (a.GetDimVector()[i] != 0 && b.GetDimVector()[i] !=0){
            tmp = rmatrix[i].converter->Convert(tmp, b.unit_vector[i], a.unit_vector[i]);
        }
        nunit_vector[i] = a.GetDimVector()[i] != 0?a.unit_vector[i]:b.unit_vector[i];

    }
    while(nmindex < _Last && ndim_vector != rmatrix[nmindex].dim_vector){
        ++nmindex;
    }

    return Quantity(nmindex, a.value * pow(tmp, p), nunit_vector);
};


quantity::Quantity::Quantity(quantity::Quantity::metrics m, double value, const string unit):
        matrix_index(m), value(value), unit(unit){
    converter = quantity::GetMatrix()[m].converter;

    unit_vector = this->compose_unit_vector(unit);

    if(!is_valid_unit()){
        cout << "invalid unit: " << unit << endl;
    }

}


quantity::Quantity::Quantity(int i, double value, vector<string> uv):
        matrix_index(i), value(value), unit_vector(uv), unit(quantity::Quantity::compose_unit(uv)) {
    converter = quantity::GetMatrix()[i].converter;




}


vector<string> quantity::UnitNotation::parser(string unit) {
    const vector<quantity::Metric> & rmatrix = quantity::GetMatrix();
    vector<string> parsed = {"", "", ""};

    bool no_matc = true;

    for(int u = 0; u < Quantity::_Last && no_matc; ++u) {
        stringstream rp;
        rp << "^(" ;
        const map<string, const shared_ptr<ConverterFunction>> & prefixes = rmatrix[u].converter->Prefixes();
        int c1 = 0;
        for(auto prx = prefixes.begin(); prx != prefixes.end(); ++prx){
            rp << prx->first << (c1 != prefixes.size()-1?"|": "");
            ++c1;
        }

        rp << ")?(";
        c1 = 0;
        const map<string, const shared_ptr<Unit>> & units = rmatrix[u].converter->Units();
        for(auto unt = units.begin(); unt != units.end(); ++unt){
            rp << unt->first << (c1 != units.size()-1?"|": "");
            ++c1;
        }

        rp << ")(\\-?[0-9])?";


        try {
            regex re(rp.str());
            sregex_iterator next(unit.begin(), unit.end(), re);
            sregex_iterator end;
            while (next != end) {
                no_matc = false;
                smatch match = *next;

                for (auto e = match.begin() + 1; e != match.end(); ++e) {

                    if(1 == units.count(*e) && "" == parsed[1]){
                        parsed[1] = *e;
                    }else if(1 == prefixes.count(*e)){
                        parsed[0] = *e;
                    }else{
                        parsed[2] = *e;
                    }
                }
                next++;
            }

        }
        catch (regex_error &e) {
        }


    }

    return parsed;
}


quantity::UnitNotation::UnitNotation(string u) {

    vector<string> parsed = parser(u);

    prefix = parsed[0];
    unit = parsed[1];
    int exp = atoi(parsed[2].c_str());
    exponent = exp != 0 ? exp : 1; //if atoi fails then the returned value is 0

}




