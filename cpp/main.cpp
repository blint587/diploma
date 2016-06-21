#include <iostream>
#include "Quantity.h"

using namespace std;
using namespace quantity;


void foo(Quantity &);


int main() {

    Quantity m (Temperature, 0, "°C");

    cout << m("K") << endl;

    return 0;
}

void foo(Quantity & q){
    vector<int> v = q.getDimVector();
    for(int i = 0; i < 7; i++){
        cout << v[i] << endl;
    }

}