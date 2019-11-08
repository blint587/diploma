#include <iostream>
#include <set>
#ifdef DEBUG
//    #include <conio.h>
#endif
#include "src/quantity.h"
#include "src/unit_notation.hpp"

using namespace std;
using namespace munits;
//using namespace math;


int main() {

	Quantity l = Quantity(munits::Time, 2, "s");
	Quantity l2 = munits::mpow(l, -2);
	TRACE(l2);




#ifdef DEBUG
    cerr << "Press a key to close..." << endl;
//    getch();
#endif


    return 0;
}


