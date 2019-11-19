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

//	Quantity l = Quantity(munits::Volume, 2, "l3");
    int i = extrapolate_metric_from_unit(UnitNotationVector::compose_unit_vector("Pa"));
	TRACE(i);




#ifdef DEBUG
    cerr << "Press a key to close..." << endl;
//    getch();
#endif


    return 0;
}


