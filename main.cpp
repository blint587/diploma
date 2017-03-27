#include <iostream>
#ifdef DEBUG
    #include <conio.h>
#endif
#include "src/quantity.h"
#include <ctime>
#include <math.h>
//#include "lib/Accesories/math.hpp"
#include "lib/Accesories/accessories.hpp"

using namespace std;
using namespace munits;
//using namespace math;


int main() {


    Quantity p {munits::Power, 1.0, "kW"};
    
    cout << p << '\n';


#ifdef DEBUG
    cerr << "Press a key to close..." << endl;
    getch();
#endif

    return 0;
}


