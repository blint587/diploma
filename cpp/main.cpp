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
        Quantity l1(Quantity::Volume, 1, "ml ");
        cout << l1("g") << endl;
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


