#include <regex>
#include <iostream>
#include <queue>
#include <algorithm>
#include <list>
#include <math.h>
#include <string>
#include "quantity.h"
#include "dynamic.hpp"
#include "uresolver.hpp"
#include "../lib/Accesories/accessories.hpp"
#include "searchers.hpp"

using namespace std;


// TODO: search only those units which are related to the Unit type (based on dim vector)
vector<munits::UnitNotation> munits::Quantity::compose_unit_vector(const string &unit) {

    istringstream iss(unit);
    list<string> tokens;

    copy(istream_iterator<string>(iss), istream_iterator<string>(),
         back_inserter(tokens)); // splitting up string representations (by default at " ")

    const vector<munits::Metric> &rmatrix = munits::GetMatrix();

    munits::Resolver r (rmatrix);

    r.resolve(tokens.begin(), tokens.end(), tokens);


    list <UnitNotation> unTokens (tokens.size()); // resizing to match

    // composing UnitNotation objects from string representations
    transform(tokens.begin(), tokens.end(), unTokens.begin(), [](string unt){return UnitNotation(unt);});


    vector<UnitNotation> uv(7); // creating default 7 element long Unit vector

    for (int ui = 0; ui < 7; ++ui) { // checking if any of the tokens is a base Unit

        auto b = find_if(unTokens.begin(), unTokens.end(), [&rmatrix, &ui](UnitNotation t) { return rmatrix[ui].converter->is_valid_unit(t);});
        if (b != unTokens.end()) {
            uv[ui] = *b;
            unTokens.erase(b);
        }
    }
    if (unTokens.size() != 0) { // if no tokens left no point checking for none base units
        for (int uii = 7; uii < munits::metrics::_Last; ++uii) {  // checking if any of the tokens is a none base Unit
            auto b = find_if(unTokens.begin(), unTokens.end(),
                             [&rmatrix, &uii](UnitNotation t) { return rmatrix[uii].converter->is_valid_unit(t); });
            if (b != unTokens.end()) {
                // searching the position where the dim_vector is not 0
                long long position = find_if(rmatrix[uii].dim_vector.begin(), rmatrix[uii].dim_vector.end(),
                                       [](int x) { return x != 0; }) - rmatrix[uii].dim_vector.begin();
                uv[position] = UnitNotation(*b);
                unTokens.erase(b);
            }
        }
    }
    if (unTokens.size() != 0) { // if any tokens left it means that what was left is invalid.
        throw std::logic_error("Incorrect Unit: " + unit);
    };
    return uv;
}


string munits::Quantity::compose_unit(const vector<UnitNotation> &uv) {
    stringstream tmp;

    for_each(uv.begin(), uv.end(), [&](const UnitNotation & unit){
            if (unit.GetUnit() != "") {
                tmp << unit.GetPrefix() << unit.GetUnit()
                    << (unit.GetExponent() != 1 ? to_string(unit.GetExponent()) : "") << " ";
            }
        }
    );

    string s = tmp.str();
    s.erase(s.find_last_not_of(" ")+1); // right triming the string
    return s;
};


double munits::Quantity::operator()(const string tunit) const {


    const vector<Metric> &rmatrix = munits::GetMatrix();
    const vector<int> & dim_vector = GetDimVector(); // dime vector of current munits
    queue<vector<int>> dim_matrix; // the search matrix composed by tearing down the dim_vector

    vector<UnitNotation> tunit_vector = compose_unit_vector(tunit);

    for (int i = 0; i < 7; ++i) {
        if (dim_vector[i] != 0) {
            vector<int> tmp_dim_vector(7);
            tmp_dim_vector[i] = abs(dim_vector[i]);
            dim_matrix.push(tmp_dim_vector);
        }
    }


    double tmp = value;

    while (!dim_matrix.empty()) {
        vector<int> dmv = (vector<int> &&) dim_matrix.front();
        long long position = find_if(dmv.begin(), dmv.end(), [](int x) { return x != 0; }) - dmv.begin();

        vector<int> normalized_dim(7);
        normalized_dim[position] = 1;

        for (auto q = rmatrix.begin(); q != rmatrix.end(); ++q) {

            if ((q->dim_vector == dmv || q->dim_vector == normalized_dim) &&
                (q->converter->is_valid_unit(unit_vector[position]) &&
                 q->converter->is_valid_unit(tunit_vector[position]))) {
                tmp = q->converter->Convert(tmp, unit_vector[position], tunit_vector[position], dim_vector[position]);
                dim_matrix.pop();
                break; // TODO: could integrate condition into loop criteria.
            }
        }
        if (!dim_matrix.empty() && dmv == dim_matrix.front()) {
            throw logic_error("Invalid Unit: " + tunit);
        }
    }

    return tmp;

}


munits::Quantity munits::Quantity::mathop(const Quantity &lfths, const Quantity &rgths, int p) {

    const vector<Metric> &rmatrix = munits::GetMatrix();
    vector<UnitNotation> nunit_vector(7);
    vector<int> ndim_vector(7);
    double tmp_rgh = rgths.value;
    double tmp_lft = lfths.value;


    for (int i = 0; i < ndim_vector.size(); ++i) {
        ndim_vector[i] = lfths.GetDimVector()[i] + p * rgths.GetDimVector()[i]; // composing the new dimension vector (exponents)
        const int lft_exponent = lfths.GetDimVector()[i];
        const int rgt_exponent = rgths.GetDimVector()[i];
        if (lft_exponent != 0 && rgt_exponent != 0) { // checking if there is a common dimension

            std::vector<int> base_line_dim_vector(7);

            base_line_dim_vector[i] = abs(rgt_exponent);
            long long rgh_converter_index = munits::getMatrixIndex(base_line_dim_vector);

            auto rgh_converter = rmatrix[rgh_converter_index].converter;

            tmp_rgh = rmatrix[rgh_converter_index].converter->Convert(tmp_rgh,
                                                                      rgths.unit_vector[i],
                                                                      UnitNotation(rgh_converter->GetBaseUnit()),
                                                                      rgt_exponent);

            base_line_dim_vector[i] = abs(lft_exponent);
            long long lft_converter_index = munits::getMatrixIndex(base_line_dim_vector);

            auto lft_converter = rmatrix[lft_converter_index].converter;

            tmp_lft = rmatrix[lft_converter_index].converter->Convert(tmp_lft,
                                                                      lfths.unit_vector[i],
                                                                      UnitNotation(lft_converter->GetBaseUnit()),
                                                                      lft_exponent);
        }

        if (lft_exponent != 0 && rgt_exponent == 0){
            nunit_vector[i] = UnitNotation(lfths.unit_vector[i].GetPrefix() + lfths.unit_vector[i].GetUnit() + std::to_string(ndim_vector[i]));

        } else if (lft_exponent == 0 && rgt_exponent != 0) {
            nunit_vector[i] = UnitNotation(rgths.unit_vector[i].GetPrefix() + rgths.unit_vector[i].GetUnit() + std::to_string(ndim_vector[i]));

        }else if (lft_exponent != 0 && (lft_exponent + (p * rgt_exponent)) != 0 /*&& rgt_exponent != 0  - always true */){
            std::vector<int> base_dim(7);
            base_dim[i] = 1;
            long long idx = munits::getMatrixIndex(base_dim);

            nunit_vector[i] = UnitNotation(rmatrix[idx].converter->GetBaseUnit() + std::to_string(ndim_vector[i]));
        }

    }

    long long nmindex = munits::getMatrixIndex(ndim_vector);

    nmindex = std::min((int)nmindex, static_cast<int>(munits::_Last));

    return Quantity((int)nmindex, tmp_lft * std::pow(tmp_rgh, p), nunit_vector, ndim_vector);
};

munits::Quantity::Quantity(int m, double value, vector<munits::UnitNotation> unit_v, std::vector<int> dim_v) :
        matrix_index(m),
        value(value),
        converter(munits::GetMatrix()[m].converter),
        unit_vector(unit_v),
        dim_vector(dim_v) {


    if (matrix_index > _Last) {
        throw logic_error("Invalid Unit type");
    }
    else if(matrix_index == _Last){
        for(unsigned int idx = 0; idx < dim_vector.size(); ++idx ){
            dim_vector[idx] = unit_vector[idx].GetExponent();
        }
    }
}


munits::Quantity::Quantity(munits::metrics m, double value, const string unit) :
        munits::Quantity::Quantity(m, value, this->compose_unit_vector(unit), munits::GetMatrix()[m].dim_vector) {
}


munits::Quantity::Quantity(int i, double value, vector<UnitNotation> uv) :
        munits::Quantity::Quantity(i, value, uv, munits::GetMatrix()[i].dim_vector) {
}


bool munits::Quantity::compop(const munits::Quantity &lfths, const munits::Quantity &rgths,
                              bool (*f)(const double &, const double &)) {

    // if the matrix indexes do not match they are not the same types and comparison is not possible
    if (lfths.matrix_index == rgths.matrix_index) {
        //applying a rounding with a precision of 6
        static const double precision = 10e4;
        auto lfhs = round(lfths.value * precision) / precision;
        // converting 'b' to the same Unit as 'a' and comparing there value
        auto rths = round(rgths(Quantity::compose_unit(lfths.unit_vector)) * precision) / precision;

        auto r = f(lfhs, rths );

        return r;
    } else {
        throw logic_error("Comparison cannot be done! Measurement Unit types do not match. ( '" +
                          Quantity::compose_unit(lfths.unit_vector) + "', '" + Quantity::compose_unit(rgths.unit_vector) + "' )");
    }
}


munits::Quantity::operator double() const {
    if (unquantified()) {
        return value;
    } else {
        throw std::logic_error("Unit cannot be converted to double!");
    }
}

bool munits::Quantity::unquantified() const {
    return all_of(dim_vector.begin(), dim_vector.end(), [](int i) { return 0 == i; });
}

munits::Quantity munits::pow(const Quantity &a, int e) {
    Quantity temp(a);
    for (int i = 1; i < e; ++i) {
        temp = temp * a;
    }
    return temp;
}


munits::Quantity munits::Quantity::ntrt (const int exponent) const {
    if (1 != exponent) {
        auto dimv = GetDimVector();
        TRACEITERABLE(dimv);
        bool rootable = std::accumulate(dimv.begin(), dimv.end(), true, [&](bool first, int second) { return first && 0 == second % exponent; });
        TRACE("rootabel: " + std::to_string(rootable));

        if (rootable) {
            double n_value =  std::pow(value, 1.0 / exponent);
            std::vector<int> n_dim_vector (7);
            std::transform(dim_vector.begin(), dim_vector.end(), n_dim_vector.begin(), [&](int exp){return exp / exponent;});

            std::vector<UnitNotation> n_unit_vector (7);
            std::transform(unit_vector.begin(), unit_vector.end(), n_unit_vector.begin(), [&](UnitNotation un){return UnitNotation(un.GetPrefix() +
            un.GetUnit() +
            std::to_string(un.GetExponent()/ exponent ));});

            return Quantity((int) munits::getMatrixIndex(n_dim_vector), n_value, n_unit_vector);
        }
        else {
            throw std::logic_error("Cannot perform " + std::to_string(exponent) + "th root on " + (std::string) *this + "!");
        }
    }
    else{
        return Quantity(*this);
    }
};

