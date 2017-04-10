/*
##########################################################################
DO NOT EDIT THIS FILE DIRECTLY! IT IS GENERATED FROM DATABASE INFORMATION.
##########################################################################
 */

#include "converter.hpp"
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "dynamic.hpp"
#include "unit.hpp"
#include "converter_function.hpp"
#include "searchers.hpp"


const std::vector<munits::Metric> & munits::GetMatrix(){
    static const std::vector<munits::Metric> matrix = {
            {{1,  0, 0,  0, 0, 0, 0}, "m", {}, //Length
                    {
                            {"inc", std::make_shared<munits::Unit>(munits::Unit(0.0254, 0., "inc"))},
                            {"ft",  std::make_shared<munits::Unit>(munits::Unit(0.3048, 0., "ft"))},
                            {"mi", std::make_shared<munits::Unit>(munits::Unit(1609.344, 0., "mi"))},
                            {"yd", std::make_shared<munits::Unit>(munits::Unit(0.914, 0., "yd"))}
                    }

            },
            {{0,  1, 0,  0, 0, 0, 0}, "g", {}, // Mass
                    {
                            {"oz",  std::make_shared<munits::Unit>(munits::Unit(28.3495, 0., "oz"))},
                            {"lb",  std::make_shared<munits::Unit>(munits::Unit(453.592, 0., "lb"))},
                            {"t",  std::make_shared<munits::Unit>(munits::Unit(1e6, 0., "t"))},

                    }
            },
            {{0,  0, 1,  0, 0, 0, 0}, "s", {}, //Time
                    {
                            {"min", std::make_shared<munits::Unit>(munits::Unit(60., 0., "min", false))},
                            {"h",   std::make_shared<munits::Unit>(munits::Unit(3600., 0., "h", false))},
                            {"d",  std::make_shared<munits::Unit>(munits::Unit(86400., 0., "d", false))}
                    }
            },
            {{0,  0, 0,  1, 0, 0, 0}, "A"},  //Electric Currency
            {{0,  0, 0,  0, 1, 0, 0}, "K",  //Temperature
                                           {"E", "P", "T", "G", "M", "k", "h", "da", "d", "c", "m", "μ", "n", "p", "f", "a"},
                    {
                            {"°C",  std::make_shared<munits::Unit>(munits::Unit(1., 273.15, "C", false))},
                            {"°F",  std::make_shared<munits::Unit>(munits::Unit(5. / 9., 459.67, "F", false))}
                    }
            },
            {{0,  0, 0,  0, 0, 1, 0}, "mol"},  //Amount of Substance
            {{0,  0, 0,  0, 0, 0, 1}, "cd"}, //Luminous Intensity
            {{2,  0, 0,  0, 0, 0, 0}, "m"}, //Area
            {{3,  0, 0,  0, 0, 0, 0}, "m", {}, //Volume
                    {
                            {"l",   std::make_shared<munits::Unit>(munits::Unit(0.001, 0., "l", true, true))},
                            {"gal", std::make_shared<munits::Unit>(munits::Unit(0.00378541178, 0., "gal", true, true))},
    //                            {"oz", make_shared<munits::Unit>(munits::Unit(2.957e-5, 0., "oz", true, true))},
                    }

            },
            {{ 3,  0, -1,  0,  0,  0,  0}, "m3 s-1"},  //VolumetricFlow
            {{-3,  0,  0,  0,  0,  1,  0}, "mol m-3"},  //MolarConcentration
            {{ 1,  0, -2,  0,  0,  0,  0}, "m s-2"},  //Acceleration
            {{ 1,  1, -2,  0,  0,  0,  0}, "kg m s-2", /*N*/{}, {}, {{"N", "kg m s-2"}}},  //Force
            {{ 1,  0, -1,  0,  0,  0,  0}, "kg m s-2"},  //Velocity
            {{-3,  1,  0,  0,  0,  0,  0}, "kg m-3"},  //Concentration or Density
            {{ 0,  1, -1,  0,  0,  0,  0}, "g s-1"},  //MassFlow
            {{-1,  1, -2,  0,  0,  0,  0}, "kg m-1 s-2", /*Pa*/{}, {}, {{"Pa", "N m-2"}, {"bar", "kN dm-2"}}},  //Pressure
            {{-1,  1, -1,  0,  0,  0,  0}, "kg m-1 s-1"},  //DynamicViscosity
            {{ 2,  0, -1,  0,  0,  0,  0}, "m2 s-1"},  //KinematicViscosity
            {{ 2,  1, -3,  0,  0,  0,  0}, "kg m2 s-3" /*W*/, {}, {}, {{"W", "kg m2 s-3"}}}, //Power
            {{ 2,  1, -2,  0,  0,  0,  0}, "kg m2 s-2" /*J or Nm*/, {}, {}, {{"J", "kg m2 s-2"}}}, //Energy
            {{ 2,  1, -2, -1,  0,  0,  0}, "kg m2 s-3 A-1" /*V*/, {}, {}, {{"V", "kg m2 s-3 A-1"}}}, //Voltage
            {{ 0,  0, -1,  0,  0,  0,  0}, "s-1" /*Hz or Bq*/, {}, {}, {{"Hz", "s-1"}, {"Bq", "s-1"}}}, //Frequency or Radioactivity
            {{ 0,  0,  1,  1,  0,  0,  0}, "A s" /*C*/, {}, {}, {{"C", "A s"}}}, //ElectricCharge
            {{-2, -1,  4,  2,  0,  0,  0}, "kg−1 m−2 s4 A2" /*F*/, {}, {}, {{"F", "kg−1 m−2 s4 A2"}}}, //ElectricCapacitance
            {{ 2,  1, -3, -2,  0,  0,  0}, "kg m2 s−3 A−2" /*Ω*/, {}, {}, {{"Ω", "kg m2 s−3 A−2"}}}, //ElectricResistance
            {{-2, -1,  3,  2,  0,  0,  0}, "kg−1 m−2 s3 A2" /*S*/, {}, {}, {{"S", "kg−1 m−2 s3 A2"}}}, //ElectricalConductance
            {{ 2,  1, -2, -1,  0,  0,  0}, "kg m2 s−2 A−1" /*Wb*/, {}, {}, {{"Wb", "kg m2 s−2 A−1"}}}, //MagneticFlux
            {{ 0,  1, -2, -1,  0,  0,  0}, "kg s−2 A−1" /*T*/, {}, {}, {{"T", "kg s−2 A−1"}}}, //MagneticFlux
            {{ 2,  1, -2, -2,  0,  0,  0}, "kg m2 s−2 A−2"}, //Inductance
            {{-2,  0,  0,  0,  0,  0,  1}, "m−2 cd"}, //Illuminance
            {{ 2,  0, -2,  0,  0,  0,  0}, "m2 s−2" /*Gy or Sv*/}, //AbsorbedDose or EquivalentDose
            {{ 0,  0, -1,  0,  0,  1,  0}, "mol s-1" /*kat*/}, //CatalyticActivity
            {{ 0,  0,  0,  0,  0,  0,  0}, ""}, //_Last

    };
    return matrix;
}

const std::map<std::string, const std::shared_ptr<munits::ConverterFunction>> & munits::GetPrefixes() {

    static const std::map<std::string, const std::shared_ptr<ConverterFunction>> prefixes  = {
            // todo: store only the exponents
            {"E", std::make_shared<ConverterFunction>(ConverterFunction(1e18, 0, "E"))}, //exa
            {"P", std::make_shared<ConverterFunction>(ConverterFunction(1e15, 0, "P"))},  // peta
            {"T", std::make_shared<ConverterFunction>(ConverterFunction(1e12, 0, "T"))},  // tera
            {"G", std::make_shared<ConverterFunction>(ConverterFunction(1e9, 0, "G"))}, // giga
            {"M", std::make_shared<ConverterFunction>(ConverterFunction(1e6, 0, "M"))},  // mega
            {"k", std::make_shared<ConverterFunction>(ConverterFunction(1e3, 0, "k"))},  // kilo
            {"h", std::make_shared<ConverterFunction>(ConverterFunction(1e2, 0, "h"))},  // hecto
            {"da", std::make_shared<ConverterFunction>(ConverterFunction(1e1, 0, "da"))},  // deca
            {"", std::make_shared<ConverterFunction>(ConverterFunction(1., 0, ""))},
            {"d", std::make_shared<ConverterFunction>(ConverterFunction(1e-1, 0, "d"))},   // deci
            {"c", std::make_shared<ConverterFunction>(ConverterFunction(1e-2, 0, "c"))},  // centi
            {"m", std::make_shared<ConverterFunction>(ConverterFunction(1e-3, 0, "m"))},  // milli
            {"μ", std::make_shared<ConverterFunction>(ConverterFunction(1e-6, 0, "mikro"))},  // micro
            {"n", std::make_shared<ConverterFunction>(ConverterFunction(1e-9, 0, "n"))},  // nano
            {"p", std::make_shared<ConverterFunction>(ConverterFunction(1e-12, 0, "p"))},  // pico
            {"f", std::make_shared<ConverterFunction>(ConverterFunction(1e-15, 0, "f"))},  // femto
            {"a", std::make_shared<ConverterFunction>(ConverterFunction(1e-18, 0, "a"))}  // atto
    };

    return prefixes;
}

