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

            bool unquantified()const;

            // TODO: include only if used for Cython
#ifdef NOCYTHON
            std::string toString() const {return std::string(
                        (std::basic_string<char, std::char_traits<char>, std::allocator<char>> &&) *this); }
            double toDouble() const {return double(*this);}
            double getValue() const {return value;}
            std::string getUnit() const {return compose_unit(unit_vector);}
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

            friend Quantity ntrt(Quantity unit, int exponent){ if (1 != exponent) {
                    auto dimv = unit.GetDimVector();
                    TRACEVECTOR(dimv);
                    bool rootable = std::accumulate(dimv.begin(), dimv.end(), true, [&](bool first, int second) { return first && 0 == second % exponent; });
                    TRACE("rootabel: " + std::to_string(rootable));

                    if (rootable) {
                        double n_value =  std::pow(unit.value, 1.0 / exponent);
                        std::vector<int> n_dim_vector (7);
                        TRACEVECTOR(n_dim_vector);
                        std::transform(unit.dim_vector.begin(), unit.dim_vector.end(), n_dim_vector.begin(), [&](int exp){return exp / exponent;});

                        std::vector<UnitNotation> n_unit_vector (7);
                        std::transform(unit.unit_vector.begin(), unit.unit_vector.end(), n_unit_vector.begin(), [&](UnitNotation un){return UnitNotation(un.GetPrefix() +
                                                                                                                                                un.GetUnit() +
                                                                                                                                                std::to_string(un.GetExponent()/ exponent ));});

                        return Quantity(GetMatrixIndex(n_dim_vector), n_value, n_unit_vector);
                    }
                    else {
                        throw std::logic_error("Cannot perform " + std::to_string(exponent) + "th root on " + (std::string) unit + "!");
                    }
                }else{
                    return Quantity(unit);
                }};

    };

    Quantity pow(Quantity  a, int e);

}


#endif //MUSYS_QUANTITY_H
