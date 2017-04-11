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

    munits::Quantity p1 (Pressure,  1, "bar");
    munits::Quantity p2 (Pressure,  1e5, "Pa");

    cout << p2 + p1  << endl;



#ifdef DEBUG
    cerr << "Press a key to close..." << endl;
    getch();
#endif


    return 0;
}


