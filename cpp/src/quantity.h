#ifndef MUSYS_QUANTITY_H
#define MUSYS_QUANTITY_H

#include <vector>
#include <set>
#include <string>
#include <map>
#include <math.h>
#include <string>
#include <memory>
#include <algorithm>
#include <sstream>
#include <iterator>

#include "../lib/Accesories/accessories.hpp"
#include "converter_function.hpp"
#include "unit.hpp"
#include "unit_notation.hpp"
#include "metric.hpp"
#include "converter.hpp"
#include "dynamic.hpp"

#ifdef DEBUG
    #include <iostream>
#endif

namespace munits {

    class Quantity {

        private:

            int matrix_index;
            std::vector<UnitNotation> unit_vector {7};
            double value;
            std::shared_ptr<munits::Converter> converter;
            std::vector<int> dim_vector;

            explicit Quantity(int,  double, std::vector<UnitNotation>);
            explicit Quantity(int, double, std::vector<UnitNotation>, std::vector<int>);

            static std::vector<UnitNotation> compose_unit_vector(const std::string &unit);
            static std::string compose_unit(const std::vector<UnitNotation> &);
            static Quantity mathop(const Quantity &a, const Quantity &b, int p=1);
            static bool compop(const Quantity &a, const Quantity &b, bool (*f)(const double &, const double &));

        public:

            explicit Quantity(metrics,  double, const std::string);
    //        Quantity(Quantity &);
            Quantity(const Quantity &) = default;
            Quantity & operator=(const Quantity &) = default;
            // TODO: implement move semantics
            ~Quantity(){};

            const std::vector<int> GetDimVector() const{return dim_vector;};
            const int getMatrixIndex()const {return matrix_index;};

            double operator()(const std::string) const;
            operator std::string() const {std::stringstream ss; ss << value << " " << compose_unit(unit_vector); return ss.str();}
            explicit operator double() const {

                if (all_of(dim_vector.begin(), dim_vector.end(),[](int i){return 0 == i;})) {
                    return value;
                } else {
                    throw std::logic_error("Unit cannot be converted to double!");
                }

            }

            // TODO: include only if used for Cython
            std::string toString() const {return std::string(*this); }
            double toDouble() const {return double(*this);}

            friend std::ostream& operator<< (std::ostream& str, const Quantity & a){str << a.value << " " <<  munits::Quantity::compose_unit(a.unit_vector);return str;};

            friend Quantity operator+ (const Quantity & a, const Quantity & b) {return munits::Quantity(a.matrix_index, a.value + b(munits::Quantity::compose_unit(a.unit_vector)), a.unit_vector);};
            friend Quantity operator- (const Quantity & a, const Quantity & b) {return munits::Quantity(a.matrix_index, a.value - b(munits::Quantity::compose_unit(a.unit_vector)), a.unit_vector);};

            friend Quantity operator* (const Quantity & a, const Quantity & b) {return mathop(a, b, 1);};
            friend Quantity operator* (const Quantity & a, const int b) {Quantity n (a); n.value *= b; return n;};
            friend Quantity operator* (const int b, const Quantity & a) {Quantity n (a); n.value *= b; return n;};
            friend Quantity operator* (const Quantity & a, const double b) {Quantity n (a); n.value *= b; return n;};
            friend Quantity operator* (const double b, const Quantity & a) {Quantity n (a); n.value *= b; return n;};

            friend Quantity operator/ (const Quantity & a, const Quantity & b) {return mathop(a, b, -1);};
            friend Quantity operator/ (const Quantity & a, const int b) {Quantity n (a); n.value /= b; return n;};
            friend Quantity operator/ (const Quantity & a, const double b) {Quantity n (a); n.value /= b; return n;};


            friend bool operator < (const Quantity & a, const Quantity & b) {return munits::Quantity::compop(a, b, accessories::lt<const double>);};
            friend bool operator <= (const Quantity & a, const Quantity & b) {return munits::Quantity::compop(a, b, accessories::le<const double>);};
            friend bool operator > (const Quantity & a, const Quantity & b) {return munits::Quantity::compop(a, b, accessories::gt<const double>);};
            friend bool operator >= (const Quantity & a, const Quantity & b) {return munits::Quantity::compop(a, b, accessories::ge<const double>);};
            friend bool operator == (const Quantity & a, const Quantity & b) {return munits::Quantity::compop(a, b, accessories::eq<const double>);};
            friend bool operator != (const Quantity & a, const Quantity & b) {return munits::Quantity::compop(a, b, accessories::ne<const double>);};

        };

    Quantity pow(Quantity  a, int e);

}


#endif //MUSYS_QUANTITY_H
