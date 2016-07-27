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
    try {
        Quantity l1(Quantity::VolumetricFlow, 1, "l s-1");
        cout << l1("m3 h") << endl;
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


