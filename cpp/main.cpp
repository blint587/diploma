#include <iostream>
#include "Quantity.h"


using namespace std;
using namespace quantity;



int main() {

    Quantity m (Quantity::Mass, 25, "kg");
//
    cout << m("g") << endl;




    return 0;
}


