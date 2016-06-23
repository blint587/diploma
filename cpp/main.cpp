#include <iostream>
#include "Quantity.h"


using namespace std;
using namespace quantity;



int main() {

    try {
        Quantity m1(Quantity::Mass, 25, "kg");
        Quantity m2(Quantity::Mass, 25, "kg");
        Quantity m3(Quantity::Mass, 25, "kg");
        Quantity m4(Quantity::Mass, 25, "kg");
        Quantity m5(Quantity::Mass, 25, "kg");

        cout << m1("g") << endl;
    }catch (...){

    }



    return 0;
}


