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
        friend  UnitNotationVector;

        private:

            int matrix_index;
//            std::vector<UnitNotation> unit_vector;
            UnitNotationVector unit_vector;
            double value;
            std::shared_ptr<munits::Converter> converter;
            std::vector<int> dim_vector;
            std::string init_unit;

//            explicit Quantity(int,  double, std::vector<UnitNotation>);
//            explicit Quantity(int, double, std::vector<UnitNotation>, std::vector<int>);

            explicit Quantity(int,  double, UnitNotationVector);
            explicit Quantity(int, double, const UnitNotationVector&, std::vector<int>);

            static Quantity mathop(const Quantity & lfths, const Quantity & rgths, int p=1);
            static bool compop(const Quantity & lfths, const Quantity & rgths, bool (*f)(const double &, const double &));
            double operator()(const UnitNotationVector& tunit ) const;
        public:
            const munits::UnitNotationVector getUnitVector() const {return unit_vector;};


            explicit Quantity(metrics,  double, const std::string&);

        //        Quantity(Quantity &);
            Quantity(const Quantity &) = default;
            Quantity & operator=(const Quantity &) = default;
            // TODO: implement move semantics
            ~Quantity(){};

            const std::vector<int> GetDimVector() const{return dim_vector;};
            const int getMatrixIndex()const {return matrix_index;};

            double operator()(const std::string&) const;

            operator std::string() const { // explicit will brake Cython
//                TRACE(unit_vector.getMultiplicationFactor());
                std::stringstream ss;
                std::string composed = UnitNotationVector::compose_unit(unit_vector, matrix_index);
                if (init_unit.empty() || composed.length() < init_unit.length()) {
                    ss << value << " " << composed;
                }
                else{
                    ss << this->operator()(init_unit) << " " << init_unit;
                }
                return ss.str();}
            explicit operator double() const;

            bool unquantified() const;

            //#ifndef NOCYTHON
            // helper functions for interfaceing
            std::string toString() const {return (std::string) *this; }
            double toDouble() const {return double(*this);}
            double getValue() const {return value;}
            std::string getUnit() const {return UnitNotationVector::compose_unit(unit_vector, matrix_index);}
            std::string getInitUnit() const {return init_unit;}
            Quantity(){};
           // #endif
            friend std::ostream& operator<< (std::ostream& str, const Quantity & a){str << a.toString() ;return str;};

            friend Quantity operator+ (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity(lfths.matrix_index, lfths.value + rgths( UnitNotationVector::compose_unit(lfths.unit_vector, lfths.matrix_index)), lfths.unit_vector);};
            friend Quantity operator- (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity(lfths.matrix_index, lfths.value - rgths( UnitNotationVector::compose_unit(lfths.unit_vector, lfths.matrix_index)), lfths.unit_vector);};

            friend Quantity operator* (const Quantity & lfths, const Quantity & rgths) {return mathop(lfths, rgths, 1);};
            friend Quantity operator* (const Quantity & lfths, const int rgths) {Quantity n (lfths); n.value *= rgths; return n;};
            friend Quantity operator* (const int lfths, const Quantity & rgths) {Quantity n (rgths); n.value *= lfths; return n;};
            friend Quantity operator* (const Quantity & lfths, const double rgths) {Quantity n (lfths); n.value *= rgths; return n;};
            friend Quantity operator* (const double lfths, const Quantity & rgths) {Quantity n (rgths); n.value *= lfths; return n;};

            friend Quantity operator/ (const Quantity & lfths, const Quantity & rgths) {return mathop(lfths, rgths, -1);};
            friend Quantity operator/ (const Quantity & lfths, const int rgths) {Quantity n (lfths);  n.value /= (rgths == 0)?throw std::overflow_error("Divide by zero!"): rgths; return n;};
            friend Quantity operator/ (const Quantity & lfths, const double rgths) {Quantity n (lfths); n.value /= (rgths == 0)?throw std::overflow_error("Divide by zero!"): rgths; return n;};


            friend bool operator < (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop(lfths, rgths, accessories::lt<const double>);};
            friend bool operator <= (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop(lfths, rgths, accessories::le<const double>);};
            friend bool operator > (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop(lfths, rgths, accessories::gt<const double>);};
            friend bool operator >= (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop(lfths, rgths, accessories::ge<const double>);};
            friend bool operator == (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop(lfths, rgths, accessories::eq<const double>);};
            friend bool operator != (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop(lfths, rgths, accessories::ne<const double>);};

            Quantity ntrt (int exponent) const; // Todo: implement as free function

    };

    Quantity mpow(const Quantity &a, int e);

}



#endif //MUSYS_QUANTITY_H
