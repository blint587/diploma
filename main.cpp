#include <iostream>
#include <set>
#ifdef DEBUG
    #include <conio.h>
#endif
#include "src/quantity.h"
#include "src/unit_notation.hpp"

using namespace std;
using namespace munits;
//using namespace math;


int main() {

	Quantity l = Quantity(munits::Length, 1, "μm");
    TRACE(l);



#ifdef DEBUG
    cerr << "Press a key to close..." << endl;
    getch();
#endif


    return 0;
}


