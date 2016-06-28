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
    Quantity l1(Quantity::Length, 0, "m");
    cout << l1("Mm") << endl;







#ifdef DEBUG
    cerr << "Press a key to close..." << endl;
    getch();
#endif

    return 0;
}


