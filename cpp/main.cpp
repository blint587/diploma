#include <iostream>
#ifdef DEBUG
    #include <conio.h>
#endif
#include "Quantity.h"


using namespace std;
using namespace munits;





int main() {

    try {
        Quantity l1(Volume, 2, "l");
        Quantity l2(Volume, 1, "l");

        cout << &l1 << ": "  << l1 << endl;
        cout << &l2 << ": "  << l2 << endl;

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


