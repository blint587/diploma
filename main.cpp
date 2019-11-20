#include <iostream>
#include <set>
#ifdef DEBUG
//    #include <conio.h>
#endif
#include "src/quantity.h"
#include "src/unit_notation.hpp"
#include "src/unit_validator.hpp"

using namespace std;
using namespace munits;
//using namespace math;


int main() {

//	Quantity l (munits::MassFlow, 19.2, "kg h-1");
//	Quantity d (munits::Density, 1.22, "kg l-1");
//    Quantity q = l/d;
//    int i = extrapolate_metric_from_unit(UnitNotationVector::compose_unit_vector("Pa"));

    Quantity v (munits::Volume, 1, "l");
    Quantity m (munits::Mass, 1, "kg");

    Quantity de =  m / v;

	TRACE(de.toString());




#ifdef DEBUG
    cerr << "Press a key to close..." << endl;
//    getch();
#endif


    return 0;
}


