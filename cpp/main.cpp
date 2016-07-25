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
    Quantity l1(Quantity::Mass, 0, "g");
    cout << l1("mg") << endl;










#ifdef DEBUG
    cerr << "Press a key to close..." << endl;
    getch();
#endif

    return 0;
}


