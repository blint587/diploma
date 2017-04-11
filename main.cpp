#include <iostream>
#ifdef DEBUG
    #include <conio.h>
#endif
#include "src/quantity.h"
#include "src/unit_notation.hpp"

using namespace std;
using namespace munits;
//using namespace math;


int main() {

   auto uv = UnitNotation::compose_unit_vector("psi");

    TRACEITERABLE(uv);



#ifdef DEBUG
    cerr << "Press a key to close..." << endl;
    getch();
#endif


    return 0;
}


