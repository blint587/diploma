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
#include "functional"

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

        template<class T>
            static bool compop(const Quantity & lfths, const Quantity & rgths) {
            // if the matrix indexes do not match they are not the same types and comparison is not possible
            if (lfths.dim_vector == rgths.dim_vector) {
                //applying a rounding with a precision of 6
                static const double precision = 10e4;
                auto lfhs = round(lfths(lfths.unit_vector) * precision) / precision;
                // converting 'b' to the same Unit as 'a' and comparing there value
                auto rths = round(rgths(lfths.unit_vector) * precision) / precision;

                bool r = T()(lfhs, rths );

                return r;
            } else {
                throw std::logic_error("Comparison cannot be done! Measurement Unit types do not match. ( '" +
                                       UnitNotationVector::compose_unit(lfths.unit_vector, lfths.matrix_index) + "', '" +
                                       UnitNotationVector::compose_unit(rgths.unit_vector, rgths.matrix_index) + "' )");
            }
            };
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

            friend Quantity operator+ (const Quantity & lfths, const Quantity & rgths) {
                if (lfths.dim_vector == rgths.dim_vector) {
                    return munits::Quantity(lfths.matrix_index, lfths.value + rgths(UnitNotationVector::compose_unit(
                            lfths.unit_vector, lfths.matrix_index)), lfths.unit_vector);
                }else{
                    throw std::logic_error("Addition cannot be performed on different dimensions!");
                }
            };
            friend Quantity operator- (const Quantity & lfths, const Quantity & rgths) {
                if (lfths.dim_vector == rgths.dim_vector) {
                    return munits::Quantity(lfths.matrix_index, lfths.value - rgths(UnitNotationVector::compose_unit(
                            lfths.unit_vector, lfths.matrix_index)), lfths.unit_vector);
                }else{
                    throw std::logic_error("Subtraction cannot be performed on different dimensions!");
                }
                };


            friend Quantity operator* (const Quantity & lfths, const Quantity & rgths) {return mathop(lfths, rgths, 1);};
            friend Quantity operator* (const Quantity & lfths, const int rgths) {Quantity n (lfths); n.value *= rgths; return n;};
            friend Quantity operator* (const int lfths, const Quantity & rgths) {Quantity n (rgths); n.value *= lfths; return n;};
            friend Quantity operator* (const Quantity & lfths, const double rgths) {Quantity n (lfths); n.value *= rgths; return n;};
            friend Quantity operator* (const double lfths, const Quantity & rgths) {Quantity n (rgths); n.value *= lfths; return n;};

            friend Quantity operator/ (const Quantity & lfths, const Quantity & rgths) {return mathop(lfths, rgths, -1);};
            friend Quantity operator/ (const Quantity & lfths, const int rgths) {Quantity n (lfths);  n.value /= (rgths == 0)?throw std::overflow_error("Divide by zero!"): rgths; return n;};
            friend Quantity operator/ (const Quantity & lfths, const double rgths) {Quantity n (lfths); n.value /= (rgths == 0)?throw std::overflow_error("Divide by zero!"): rgths; return n;};


            friend bool operator < (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop<std::less<double>>(lfths, rgths);};
            friend bool operator <= (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop<std::less_equal<double>>(lfths, rgths);};
            friend bool operator > (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop<std::greater<double>>(lfths, rgths);};
            friend bool operator >= (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop<std::greater_equal<double>>(lfths, rgths);};
            friend bool operator == (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop<std::equal_to<double>>(lfths, rgths);};
            friend bool operator != (const Quantity & lfths, const Quantity & rgths) {return munits::Quantity::compop<std::not_equal_to<double>>(lfths, rgths);};

            Quantity ntrt (int exponent) const; // Todo: implement as free function

    };

    Quantity mpow(const Quantity &a, int e);

}



#endif //MUSYS_QUANTITY_H
