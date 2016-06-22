#include <iostream>
#include "Quantity.h"

using namespace std;
using namespace quantity;


void foo(Quantity &);


int main() {

    Quantity m (Mass, 25, "kg");

    cout << m("g") << endl;


    return 0;
}

void foo(Quantity & q){
    vector<int> v = q.getDimVector();
    for(int i = 0; i < 7; i++){
        cout << v[i] << endl;
    }

}