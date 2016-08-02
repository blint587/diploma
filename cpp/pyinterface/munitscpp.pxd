from libcpp.string cimport string

cdef extern from "../quantity.h" namespace "munits":

    cdef  enum metrics:
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
            _Last = 12

    cdef cppclass Quantity:
        Quantity(metrics, double, const string)
        Quantity(const Quantity)

        bint operator< (const Quantity)
        double operator()(string)

        Quantity operator+(const Quantity)

