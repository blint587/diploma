#include <regex>
#include <iostream>
#include <queue>
#include <algorithm>
#include <list>
#include "quantity.h"


using namespace std;



// TODO: search only those units which are related to the Unit type (based on dim vector)
vector<munits::UnitNotation> munits::Quantity::compose_unit_vector(const string &unit)  {

    istringstream iss(unit);
    vector<string> tokens;
    list<UnitNotation> unTokens;

    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens)); // splitting up string representations (by default at " ")

    for(auto unt = tokens.begin(); unt != tokens.end(); ++unt){ // composing UnitNotation objects from string representations
        unTokens.push_back(UnitNotation(*unt));
    }

    const vector<munits::Metric> & rmatrix = munits::GetMatrix();

    vector<UnitNotation> uv(7); // creating default 7 element long Unit vector

    for(int ui = 0; ui < 7; ++ui){ // checking if any of the tokens is a base Unit

        auto b = find_if(unTokens.begin(), unTokens.end(), [&rmatrix, &ui](UnitNotation t){return rmatrix[ui].converter->is_valid_unit(t);});
        if (b != unTokens.end()){
            uv[ui] = *b;
            unTokens.erase(b);
        }
    }
    if (unTokens.size() != 0){ // if no tokens left no point checking for none base units
        for(int uii = 7; uii < munits::metrics::_Last; ++uii){  // checking if any of the tokens is a none base Unit
            auto b = find_if(unTokens.begin(), unTokens.end(), [&rmatrix, &uii](UnitNotation t){return rmatrix[uii].converter->is_valid_unit(t);});
            if (b != unTokens.end()){
                // searching the position where the dim_vector is not 0
                int position = find_if(rmatrix[uii].dim_vector.begin(), rmatrix[uii].dim_vector.end(), [](int x){return x != 0;}) - rmatrix[uii].dim_vector.begin();
                uv[position] = UnitNotation(*b);
                unTokens.erase(b);
            }
        }
    }
    if (unTokens.size() != 0){ // if any tokens left it means that what was left is invalid.
        throw std::logic_error("Incorrect Unit: " + unit);
    };
    return uv;
}


string munits::Quantity::compose_unit(const vector<UnitNotation> & uv){
    stringstream tmp;
    // TODO: exponents are ignored in cases when Unit is composed during math operations
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


    const vector<Metric> & rmatrix = munits::GetMatrix();
    const vector<int> & dim_vector = GetDimVector(); // dime vector of current munits
    queue<vector<int>> dim_matrix; // the search matrix composed by tearing down the dim_vector

    vector<UnitNotation> tunit_vector = compose_unit_vector(tunit);

    for(int i = 0; i < 7; ++i){
        if(dim_vector[i] !=0){
            vector<int> tmp_dim_vector (7);
            tmp_dim_vector[i] = abs(dim_vector[i]);
            dim_matrix.push(tmp_dim_vector);
        }
    }


    double tmp = value;

    while(!dim_matrix.empty()){
        vector<int> dmv = dim_matrix.front();
        int position = find_if(dmv.begin(), dmv.end(), [](int x){return x != 0;}) - dmv.begin();

        vector<int> normalized_dim(7);
        normalized_dim[position] = 1;

        for(auto q = rmatrix.begin(); q != rmatrix.end(); ++q){

            if((q->dim_vector == dmv || q->dim_vector == normalized_dim) &&(q->converter->is_valid_unit(unit_vector[position]) && q->converter->is_valid_unit(tunit_vector[position]))){
                tmp = q->converter->Convert(tmp, unit_vector[position], tunit_vector[position], dim_vector[position]);
                dim_matrix.pop();
                break; // TODO: could integrate condition into loop criteria.
            }
        }
        if(!dim_matrix.empty() && dmv == dim_matrix.front()){
            throw logic_error("Invalid Unit: " + tunit);
        }
    }

    return tmp;

}


munits::Quantity munits::Quantity::mathop(const Quantity &a, const Quantity &b, int p) {

    const vector<Metric> & rmatrix = munits::GetMatrix();
    vector<UnitNotation> nunit_vector(7);
    vector<int> ndim_vector (7);
    double tmp = b.value;


    // TODO: use std::copy
    for(int i = 0; i < ndim_vector.size(); ++i){
        ndim_vector[i] = a.GetDimVector()[i] + p * b.GetDimVector()[i]; // composing the new dimension vector (exponents)
        if (a.GetDimVector()[i] != 0 && b.GetDimVector()[i] !=0){ // checking if there is a common dimension
            tmp = rmatrix[i].converter->Convert(tmp, b.unit_vector[i], a.unit_vector[i]); // converting if there is a common dimension in both units
        }
        nunit_vector[i] = a.GetDimVector()[i] != 0?a.unit_vector[i]:b.unit_vector[i]; // composing the new Unit vector (units)
    }

    // determining the Unit type by searching the matching dimension vector
    int nmindex = find_if(rmatrix.begin(), rmatrix.end(),
                          [&](Metric q){return ndim_vector == q.dim_vector;}) - rmatrix.begin() ;

    nmindex = std::min(nmindex, static_cast<int>(munits::_Last));

    return Quantity(nmindex, a.value * std::pow(tmp, p), nunit_vector, ndim_vector);
};

munits::Quantity::Quantity(int m, double value, vector<munits::UnitNotation> unit_v, std::vector<int> dim_v) :
        matrix_index(m),
        value(value),
        converter(munits::GetMatrix()[m].converter),
        unit_vector(unit_v),
        dim_vector(dim_v) {

    if (matrix_index > _Last){
            throw logic_error("Invalid Unit type");
        }

}


munits::Quantity::Quantity(munits::metrics m, double value, const string unit):
        munits::Quantity::Quantity(m, value, this->compose_unit_vector(unit), munits::GetMatrix()[m].dim_vector ) {
}


munits::Quantity::Quantity(int i,  double value, vector<UnitNotation> uv):
        munits::Quantity::Quantity(i, value, uv, munits::GetMatrix()[i].dim_vector){
}

bool munits::Quantity::compop(const munits::Quantity &a, const munits::Quantity &b, bool (*f)(const double &, const double &)) {
    if (a.matrix_index == b.matrix_index) { // if the matrix indexes do not match they are not the same types and comparison is not possible
        return f(a.value, b(Quantity::compose_unit(a.unit_vector))); // converting 'b' to the same Unit as 'a' and comparing there value
    }
    else{
        throw logic_error("Comparison cannot be done! Measurement Unit types do not match. ( '" + Quantity::compose_unit(a.unit_vector) + "', '" + Quantity::compose_unit(b.unit_vector) +"' )" );
    }
}


munits::Quantity munits::pow(munits::Quantity a, int e) {
    Quantity temp(a);
    for (int i = 1; i < e; ++i) {
        temp = temp * a;
    }
    return temp;
};







