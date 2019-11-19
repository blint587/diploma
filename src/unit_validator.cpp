//
// Created by bmolnar on 2019. 11. 19..
//

#include <algorithm>
#include "unit_validator.hpp"

bool munits::validate_unit(const munits::UnitNotationVector & un, munits::metrics m){

    static const std::vector<munits::Metric> * matrix =  &munits::GetMatrix();

    std::vector<int> dim_vector_from_un (7);

    //converting the Unit notation vector to a simple dimensional vector
    //eg.: [0, m m 1, 0, 0, 0, 0, 0] -> [0, 1, 0, 0, 0, 0, 0]
    // so it can be compared with the intended dimensional vector
    //the vector size is always 7 (SI) so don't fuss about it
    for(int idx = 0; idx < 7; ++idx){
        dim_vector_from_un[idx] = un[idx].GetExponent();
    }
    std::vector<int> dim_vector_from_metric = matrix->operator[](m).dim_vector;

    return dim_vector_from_un == dim_vector_from_metric;

}

int munits::extrapolate_metric_from_unit(const munits::UnitNotationVector & un){
    std::vector<int> dim_vector_from_un (7);
    //converting the Unit notation vector to a simple dimensional vector
    //eg.: [0, m m 1, 0, 0, 0, 0, 0] -> [0, 1, 0, 0, 0, 0, 0]
    //the vector size is always 7 (SI) so don't fuss about it
    for(int idx = 0; idx < 7; ++idx){
        dim_vector_from_un[idx] = un[idx].GetExponent();
    }

    static const std::vector<munits::Metric> * matrix =  &munits::GetMatrix();

    //searching for a matching dimensional vector in the matrix
    //its index will be the result
    int idx = -1;
    for(idx = 0; idx <= (int) metrics::_Last &&
            (matrix->operator[](idx).dim_vector != dim_vector_from_un); ++idx){}
    return idx;
}