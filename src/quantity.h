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
#include <numeric>
#include <sstream>
#include <iterator>
#include <stdexcept>

#include "../lib/Accesories/accessories.hpp"
#include "converter_function.hpp"
#include "unit.hpp"
#include "unit_notation.hpp"
#include "metric.hpp"
#include "converter.hpp"
#include "dynamic.hpp"



namespace munits {

    class Quantity {

        private:

            int matrix_index;
            std::vector<UnitNotation> unit_vector;
            double value;
            std::shared_ptr<munits::Converter> converter;
            std::vector<int> dim_vector;

            explicit Quantity(int,  double, std::vector<UnitNotation>);
            explicit Quantity(int, double, std::vector<UnitNotation>, std::vector<int>);

            static std::vector<UnitNotation> compose_unit_vector(const std::string &unit);
            static std::string compose_unit(const std::vector<UnitNotation> &);
            static Quantity mathop(const Quantity & lfths, const Quantity & rgths, int p=1);
            static bool compop(const Quantity & lfths, const Quantity & rgths, bool (*f)(const double &, const double &));

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
            operator std::string() const {std::stringstream ss; ss << value  << " " << compose_unit(unit_vector); return ss.str();}
            explicit operator double() const;

            bool unquantified() const;


            #ifndef NOCYTHON
            // helper functions for interfaceing
            std::string toString() const {return std::string((std::basic_string<char, std::char_traits<char>, std::allocator<char>> &&) *this); }
            double toDouble() const {return double(*this);}
            double getValue() const {return value;}
            std::string getUnit() const {return compose_unit(unit_vector);}
            Quantity(){};
            #endif
            friend std::ostream& operator<< (std::ostream& str, const Quantity & a){str << a.value << " " <<  munits::Quantity::compose_unit(a.unit_vector);return str;};

            friend Quantity operator+ (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity(lfths.matrix_index, lfths.value + rgths(munits::Quantity::compose_unit(lfths.unit_vector)), lfths.unit_vector);};
            friend Quantity operator- (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity(lfths.matrix_index, lfths.value - rgths(munits::Quantity::compose_unit(lfths.unit_vector)), lfths.unit_vector);};

            friend Quantity operator* (const Quantity & lfths, const Quantity & rgths) {return mathop(lfths, rgths, 1);};
            friend Quantity operator* (const Quantity & lfths, const int rgths) {Quantity n (lfths); n.value *= rgths; return n;};
            friend Quantity operator* (const int lfths, const Quantity & rgths) {Quantity n (rgths); n.value *= lfths; return n;};
            friend Quantity operator* (const Quantity & lfths, const double rgths) {Quantity n (lfths); n.value *= rgths; return n;};
            friend Quantity operator* (const double lfths, const Quantity & rgths) {Quantity n (rgths); n.value *= lfths; return n;};

            friend Quantity operator/ (const Quantity & lfths, const Quantity & rgths) {return mathop(lfths, rgths, -1);};
            friend Quantity operator/ (const Quantity & lfths, const int rgths) {Quantity n (lfths); n.value /= rgths; return n;};
            friend Quantity operator/ (const Quantity & lfths, const double rgths) {Quantity n (lfths); n.value /= rgths; return n;};


            friend bool operator < (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop(lfths, rgths, accessories::lt<const double>);};
            friend bool operator <= (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop(lfths, rgths, accessories::le<const double>);};
            friend bool operator > (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop(lfths, rgths, accessories::gt<const double>);};
            friend bool operator >= (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop(lfths, rgths, accessories::ge<const double>);};
            friend bool operator == (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop(lfths, rgths, accessories::eq<const double>);};
            friend bool operator != (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop(lfths, rgths, accessories::ne<const double>);};

            Quantity ntrt (const int exponent) const; // Todo: implement as free function

    };

    Quantity pow(const Quantity &a, int e);

}


#endif //MUSYS_QUANTITY_H
