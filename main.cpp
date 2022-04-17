#include <iostream>
#include <set>
#ifdef DEBUG
//    #include <conio.h>
#endif
#include <vector>
#include "src/quantity.h"
#include "src/unit_notation.hpp"
#include "src/unit_validator.hpp"

using namespace std;
using namespace munits;
//using namespace math;


int main() {

	Quantity l (munits::MassFlow, 2, "kg h-1");
	Quantity d (munits::Mass, 1, "kg");

	try {
        auto r = l + d;
        TRACE(r);
    }catch (logic_error &e){
	    TRACE(e.what());

	}
    vector<int> v1  {1,2,3,4};
    vector<int> v2  {1,2,3, 5};

    TRACE(v1 == v2);


#ifdef DEBUG
    cerr << "Press a key to close..." << endl;
//    getch();
#endif


    return 0;
}


