#include <iostream>
#ifdef DEBUG
    #include <conio.h>
#endif
#include "Quantity.h"


using namespace std;
using namespace munits;





int main() {

    try {
        Quantity l1(Length, 2, "m");
//        Quantity l2(Length, 1, "m");
//        Quantity l3(  l1 / l2 );
        cout << l1 << endl;
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


