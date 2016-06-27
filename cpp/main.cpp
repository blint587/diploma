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
    Quantity l1(Quantity::Volume, 1, "m3");
    Quantity l2(Quantity::Time, 1, "h");
    Quantity v = l1 /l2;
    cout << v("m3 d-1") << endl;







#ifdef DEBUG
    cerr << "Press a key to close..." << endl;
    getch();
#endif

    return 0;
}


