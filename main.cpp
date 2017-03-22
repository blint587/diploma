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


    Quantity mq (Power, 1, "kW");

    cout << mq << endl;




#ifdef DEBUG
    cerr << "Press a key to close..." << endl;
    getch();
#endif

    return 0;
}


