#include <stdexcept>
#include <regex>
#include <iostream>
#include <queue>
#include <algorithm>
#include <list>
#include <cmath>
#include <cstdlib>
#include <string>
#include <utility>
#include "functional"
#include "quantity.h"
#include "dynamic.hpp"
#include "uresolver.hpp"
#include "searchers.hpp"
#include "unit_notation.hpp"
#include "../lib/Accesories/accessories.hpp"
#include "../lib/Accesories/mymath.hpp"
#include "unit_validator.hpp"

using namespace std;


double munits::Quantity::operator()(const string& tunit) const {

    UnitNotationVector tunit_vector = UnitNotationVector::compose_unit_vector(tunit);

    return this->operator()(tunit_vector);

}

munits::Quantity munits::Quantity::mathop(const Quantity &lfths, const Quantity &rgths, int p) {

    const vector<Metric> &rmatrix = munits::GetMatrix();
    UnitNotationVector nunit_vector;
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

            if(rgh_converter_index > _Last || (1 != rmatrix[rgh_converter_index].converter->Units().count(rgths.unit_vector[i].GetUnit()))){
                base_line_dim_vector[i] = 1;
                rgh_converter_index = munits::getMatrixIndex(base_line_dim_vector);
            }

            auto rgh_converter = rmatrix[rgh_converter_index].converter;

            tmp_rgh = rmatrix[rgh_converter_index].converter->Convert(tmp_rgh,
                                                                      rgths.unit_vector[i],
                                                                      UnitNotation(rgh_converter->GetBaseUnit()),
                                                                      rgt_exponent);

            base_line_dim_vector[i] = abs(lft_exponent);
            long long lft_converter_index = munits::getMatrixIndex(base_line_dim_vector);

            if(lft_converter_index > _Last || (1 != rmatrix[lft_converter_index].converter->Units().count(lfths.unit_vector[i].GetUnit()))){
                base_line_dim_vector[i] = 1;
                lft_converter_index = munits::getMatrixIndex(base_line_dim_vector);
            }

            auto lft_converter = rmatrix[lft_converter_index].converter;

            tmp_lft = rmatrix[lft_converter_index].converter->Convert(tmp_lft,
                                                                      lfths.unit_vector[i],
                                                                      UnitNotation(lft_converter->GetBaseUnit()),
                                                                      lft_exponent);
        }

        if (lft_exponent != 0 && rgt_exponent == 0){
            const UnitNotation  un =  lfths.unit_vector[i];
            int new_exponent = un.silent_exponent ? ndim_vector[i] / abs(un.silent_exponent) : ndim_vector[i];

            nunit_vector[i] = UnitNotation(un.GetPrefix() + un.GetUnit() + std::to_string(new_exponent));


            nunit_vector[i].silent_exponent =
                    mymath::sgn<int>(un.silent_exponent) == mymath::sgn<int>(ndim_vector[i]) ?
                            un.silent_exponent : -1 * un.silent_exponent;

        } else if (lft_exponent == 0 && rgt_exponent != 0) {
            const UnitNotation un = rgths.unit_vector[i];
            int new_exponent = un.silent_exponent ? ndim_vector[i] / abs(un.silent_exponent) : ndim_vector[i];

            nunit_vector[i] = UnitNotation(un.GetPrefix() + un.GetUnit() + std::to_string(new_exponent));
            nunit_vector[i].silent_exponent =
                    mymath::sgn<int>(un.silent_exponent) == mymath::sgn<int>(ndim_vector[i]) ?
                    un.silent_exponent : -1 * un.silent_exponent;

        }else if (lft_exponent != 0 && (lft_exponent + (p * rgt_exponent)) != 0 /*&& rgt_exponent != 0  - always true */){
            std::vector<int> base_dim(7);
            base_dim[i] = 1;
            long long idx = munits::getMatrixIndex(base_dim);

            nunit_vector[i] = UnitNotation(rmatrix[idx].converter->GetBaseUnit() + std::to_string(ndim_vector[i]));
        }

    }

    long long nmindex = munits::getMatrixIndex(ndim_vector);

    nmindex = std::min((int)nmindex, static_cast<int>(munits::_Last));

    if (0 == tmp_rgh && p <= 0){
        throw std::overflow_error("Divide by zero!");
    }

    return Quantity((int)nmindex, tmp_lft * std::pow(tmp_rgh, p), nunit_vector, ndim_vector);
};

munits::Quantity::Quantity(int m, double value, const munits::UnitNotationVector& unit_v, std::vector<int> dim_v) :
        matrix_index(m),
        unit_vector(unit_v),
        value(value * unit_vector.getMultiplicationFactor()),
        converter(munits::GetMatrix()[m].converter),
        dim_vector(std::move(dim_v)) {



    if (matrix_index > _Last) {
        throw std::logic_error("Invalid Unit type");
    }
    else if(matrix_index == _Last){
        for(unsigned int idx = 0; idx < dim_vector.size(); ++idx ){
            dim_vector[idx] = unit_vector[idx].GetExponent();
        }
    }else if (matrix_index < _Last && !(munits::validate_unit(unit_vector, (munits::metrics) matrix_index))){
        throw std::logic_error("Invalid measurement unit!");
    }
}


munits::Quantity::Quantity(munits::metrics m, double value, const string& unit) :
        munits::Quantity::Quantity(m, value, UnitNotationVector::compose_unit_vector(unit), munits::GetMatrix()[m].dim_vector) {
    init_unit = unit;
}


munits::Quantity::Quantity(int i, double value, UnitNotationVector uv) :
        munits::Quantity::Quantity(i, value, uv, munits::GetMatrix()[i].dim_vector) {
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

munits::Quantity munits::mpow(const Quantity &a, int e) {
    Quantity temp(a);
    int abse = abs(e);

    for (int i = 1; i < abse; ++i) {
        temp = temp * a;
    }

    if(e < 0){
        temp = Quantity(munits::_Last, 1, "") / temp;
    }
    return temp;
}


munits::Quantity munits::Quantity::ntrt (const int exponent) const {
    if (1 != exponent) {
        auto dimv = GetDimVector();
        bool rootable = std::accumulate(dimv.begin(), dimv.end(), true, [&](bool first, int second) { return first && 0 == second % exponent; });

        if (rootable) {
            double n_value =  std::pow(value, 1.0 / exponent);
            std::vector<int> n_dim_vector (7);
            std::transform(dim_vector.begin(), dim_vector.end(), n_dim_vector.begin(), [&](int exp){return exp / exponent;});

            UnitNotationVector n_unit_vector;
            std::transform(unit_vector.begin(), unit_vector.end(), n_unit_vector.begin(),
                    [&](UnitNotation un){return !un.GetUnit().empty() ?  UnitNotation(un.GetPrefix() + un.GetUnit() + std::to_string(un.GetExponent()/ exponent )): UnitNotation();});
            return Quantity((int) munits::getMatrixIndex(n_dim_vector), n_value, n_unit_vector);
        }
        else {
            throw std::logic_error(std::string("Cannot perform ") + std::to_string(exponent) + std::string("th root on ") + this->toString() + std::string("!"));
        }
    }
    else{
        return Quantity(*this);
    }
}

double munits::Quantity::operator()(const munits::UnitNotationVector &tunit) const {
    const vector<Metric> &rmatrix = munits::GetMatrix();
    queue<vector<int>> dim_matrix; // the search matrix composed by tearing down the dim_vector

    double tmp = value;

    for (int i = 0; i < 7; ++i) {
        if (dim_vector[i] != 0) {
            vector<int> tmp_dim_vector(7);
            tmp_dim_vector[i] = abs(dim_vector[i]);
            dim_matrix.push(tmp_dim_vector);
        }
    }

    while (!dim_matrix.empty()) {
        vector<int> dmv = (vector<int> &&) dim_matrix.front();
        long long position = find_if(dmv.begin(), dmv.end(), [](int x) { return x != 0; }) - dmv.begin();

        vector<int> normalized_dim(7);
        normalized_dim[position] = 1;

        for (auto q = rmatrix.begin(); q != rmatrix.end(); ++q) {
//            TRACEMAP(q->converter->Units());
//            TRACEITERABLE(q->dim_vector); TRACEITERABLE(dmv);
            if ((q->dim_vector == dmv || q->dim_vector == normalized_dim) &&
                (q->converter->is_valid_unit(this->unit_vector[position]) &&
                 q->converter->is_valid_unit(tunit[position]))) {
                tmp = q->converter->Convert(tmp, unit_vector[position], tunit[position], dim_vector[position]);
                dim_matrix.pop();
                break; // TODO: could integrate condition into loop criteria.
            }
        }
        if (!dim_matrix.empty() && dmv == dim_matrix.front()) {
            throw std::logic_error("Invalid Unit: " /*+ tunit*/);
        }
    }

    if(tunit.getMultiplicationFactor() != 1.) {
        return tmp / tunit.getMultiplicationFactor();
    }else{
        return tmp;
    }
}

