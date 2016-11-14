#include <iostream>
#ifdef DEBUG
    #include <conio.h>
#endif
#include "src/quantity.h"
#include <ctime>
#include <math.h>


using namespace std;
using namespace munits;





int main() {

    Quantity c1 (Velocity, 2, "m s-1");
    Quantity c2 (Velocity, 4, "m s-1");

    Quantity c3 = c1 / c2;
    cout << (double)c3 << endl;

    try {
//        for (int j = 0; j < 10; ++j) {
//            clock_t start = clock();
//            for (int i = 0; i < 10000; ++i) {
//                Quantity l1(Length, 1, "m");
//                Quantity l2(Length, 1, "m");
//                Quantity l3 = l1 * l2;
//
//                l3("mm2");
//            }
//
//            clock_t stop = clock();
//            cout << (double(stop - start) / CLOCKS_PER_SEC) << endl;
//        }

//        munits::Quantity t (munits::Temperature, -40., "°C");
//        cout << t("K") << endl;
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


