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


    UnitNotation a ("mm2");
    UnitNotation b ("m2");

    cout << (double) (a / b) << endl;



#ifdef DEBUG
    cerr << "Press a key to close..." << endl;
    getch();
#endif

    return 0;
}


