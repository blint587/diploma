#include <iostream>
#ifdef DEBUG
    #include <conio.h>
#endif
#include "Quantity.h"


using namespace std;
using namespace quantity;





int main() {


//    UnitNotation u("m");
//
//    cout << "Prefix: " << u.GetPrefix() << endl;
//    cout <<  "Unit: " <<u.GetUnit() << endl;
//
    Quantity l(Quantity::VolumetricFlow, 1, "m3 h-1");
//
    cout << l("m3 d-1") << endl;






#ifdef DEBUG
    cout << "Press a key to close..." << endl;
    getch();
#endif

    return 0;
}


