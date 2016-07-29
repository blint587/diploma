#include <iostream>
#ifdef DEBUG
    #include <conio.h>
#endif
#include "Quantity.h"


using namespace std;
using namespace munits;





int main() {


//    UnitNotation u("m");
//
//    cout << "Prefix: " << u.GetPrefix() << endl;
//    cout <<  "Unit: " <<u.GetUnit() << endl;
//
    try {
        Quantity l1(Quantity::Volume, 1, "l");
        Quantity l2(Quantity::Volume, 1, "l");
        cout << (l1 > l2) << endl;
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


