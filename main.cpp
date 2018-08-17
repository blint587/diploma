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

   Quantity p (Force, 1, "kg m s-2");
    TRACE(p);




#ifdef DEBUG
    cerr << "Press a key to close..." << endl;
    getch();
#endif


    return 0;
}


