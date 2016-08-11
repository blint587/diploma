#include <iostream>
#ifdef DEBUG
    #include <conio.h>
#endif
#include "Quantity.h"


using namespace std;
using namespace munits;





int main() {

    try {
        Quantity l1(Concentration, 1, "kg m-3");

        double x = l1("g l-1");

        cout << x << endl;
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


