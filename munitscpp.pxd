from libcpp.string cimport string

cdef extern from "src/quantity.h" namespace "munits":

    cdef enum metrics:
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
            AbsorbedDose = 31,
            CatalyticActivity = 32,
            MolarWeight = 33,
            EnergyFlux = 34,
            EnergyPerArea = 35,
            MassFlux = 36,
            AeraDensity = 37,
            _Last = 38

    cdef cppclass Quantity:
        Quantity(metrics, double, const string) except + ValueError
        Quantity(const Quantity)

        int getMatrixIndex()
        double getValue()
        string getUnit()
        string getInitUnit()

        bint operator< (const Quantity) except + ValueError
        bint operator<= (const Quantity) except + ValueError
        bint operator> (const Quantity) except + ValueError
        bint operator>= (const Quantity) except + ValueError
        bint operator== (const Quantity) except + ValueError
        bint operator!= (const Quantity) except + ValueError

        double operator()(string) except + ValueError

        Quantity operator+(const Quantity)
        Quantity operator-(const Quantity)
        Quantity operator*(const Quantity)
        Quantity operator*(const float)
        Quantity operator*(const int)
        Quantity operator/(const Quantity) except + OverflowError
        Quantity operator/(const float) except + OverflowError
        Quantity operator/(const int) except + OverflowError
        Quantity ntrt(const int) except + ValueError


        string toString() except + RuntimeError
        double toDouble() except + RuntimeError
        bint unquantified()

    cdef Quantity pow(Quantity, int)
