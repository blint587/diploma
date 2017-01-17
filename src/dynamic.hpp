/*
##########################################################################
DO NOT EDIT THIS FILE DIRECTLY! IT IS GENERATED FROM DATABASE INFORMATION.
##########################################################################
 */



#ifndef MUSYS_DYNAMIC_HPP
#define MUSYS_DYNAMIC_HPP

#include <vector>
#include <memory>
#include "metric.hpp"


namespace munits {

    enum metrics {
        Length = 0,
        Mass = 1,
        Time = 2,
        ElectricCurrency = 3,
        Temperature = 4,
        AmountOfSubstance = 5,
        LuminousIntensity = 6,
        Area = 7,
        Volume = 8,
        VolumetricFlow = 9,
        MolarConcentration = 10,
        Acceleration = 11,
        Force = 12,
        Velocity = 13,
        Concentration = 14,
        Density = 14,
        MassFlow = 15,
        Pressure = 16,
        DynamicViscosity = 17,
        KinematicViscosity = 18,
        Power = 19,
        Energy = 20,
        Voltage = 21,
        Frequency = 22,
        ElectricCharge = 23,
        ElectricCapacitance = 24,
        ElectricResistance = 25,
        ElectricalConductance = 26,
        MagneticFlux = 27,
        MagneticFluxDensity = 28,
        Inductance = 29,
        Illuminance = 30,
//        Radioactivity = 22,
        AbsorbedDose = 31,
//        EquivalentDose = 31,
        CatalyticActivity = 32,
//        Torque = 20,
        _Last

    };


    const std::vector<munits::Metric> & GetMatrix();
    const int GetMatrixIndex(std::vector<int> & searched);


}
#endif //MUSYS_DYNAMIC_HPP
