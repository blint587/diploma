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


    Quantity mq (MassFlow, 1, "kg d-1");
//    Quantity r (_Last, 1, "kg m-2 d-1");
//
//    auto res = mq /r;




    try {
        Quantity a (Volume, 8.0, "gal");
        cout <<  ntrt(a, 3) << '\n';

    }
    catch (exception & e){
        cerr << e.what() << endl;

    }


#ifdef DEBUG
    cerr << "Press a key to close..." << endl;
    getch();
#endif

    return 0;
}


