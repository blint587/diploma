#include <iostream>
#include "quantity.h"

using namespace std;
void foo(Quantity & m) {
    for(int i = 0; i < 7; i++){
        cout << m.dim_vector[i] << endl;
    }

}


int main() {
    Mass m;
//    Length l;

    foo(m);

    return 0;
}

