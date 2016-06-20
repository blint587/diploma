#include <iostream>
#include "quantity.h"
#include "ConverterFunction.h"

using namespace std;
using namespace quantity;


void foo(Quantity &);


int main() {

    quantity::Converter c("m");

    cout << c(1., "m", "Em") << endl;

    return 0;
}

void foo(Quantity & q){
    vector<int> v = q.getDimVector();
    for(int i = 0; i < 7; i++){
        cout << v[i] << endl;
    }

}