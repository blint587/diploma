from libcpp.string cimport string

cdef extern from "../src/quantity.h" namespace "munits":

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
            _Last = 12

    cdef cppclass Quantity:
        Quantity(metrics, double, const string) except + ValueError
        Quantity(const Quantity)

        int getMatrixIndex()

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
        Quantity operator/(const Quantity)

        string toString() except + RuntimeError

    cdef Quantity pow(Quantity, int)