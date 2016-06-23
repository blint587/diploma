#include <iostream>
#include "Quantity.h"


using namespace std;
using namespace quantity;



int main() {

    try {
        Quantity m1(Quantity::Mass, 25, "kg");
        Quantity m2(Quantity::Mass, 25, "kg");
        Quantity m3 = m1 + m2;

        cout << m3("g") << endl;
    }catch (...){

    }



    return 0;
}


