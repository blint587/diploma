#include <iostream>
#include "src/quantity.h"
#include "src/unit_validator.hpp"


using namespace munits;


int main() {

    Quantity n (munits::Time, 1, "s");

    std::cout << 1 / n << std::endl;
    std::cout << n.mpow(-1) << std::endl;

    Quantity v (munits::Volume, -8, "m3");
    std::cout << v.ntrt(3) << std::endl;

    Quantity v2 (munits::Volume, 8, "m3");
    std::cout << v2.ntrt(3) << std::endl;

    Quantity a (munits::Area,-2, "m2");
    std::cout << a.ntrt(2) << std::endl;


    /*Quantity q1 (munits::Length, 15, "m"); // initiat a object
    std::cout << "q1 is " << q1 <<  std::endl;
    Quantity q2 (munits::Length, 15000, "mm"); // initiat a object
    std::cout << "q2 is "<< q2 << std::endl;

    //add
    Quantity q3 = q1 + q2;
    std::cout << "q1 + q2 = "<< q3 << std::endl;

    //multiply
    Quantity q4 = q1 * q2;
    std::cout << "q1 * q2 = "<< q4 << std::endl;


    //division
    Quantity q7 (munits::Time, 1, "s");
    Quantity q8 = q1 / q7;
    std::cout << "q7 is " << q7 << std::endl;
    std::cout << "q1 / q7 = " << q8 << std::endl;

    //power function
    Quantity q5 = munits::mpow(q1, 3);
    std::cout << "q1 on 3rd power is " << q5 << std::endl;

    //root
    Quantity q6 = q5.ntrt(3);
    std::cout << q5 <<" on 3rd root is " << q6 << std::endl;

    //compare
    //To compare units us the comparison operator '<,>,<=,>=,==,!='
    std::cout << "q1 < q2 -> " << (q1 < q2 ? "True": "False") << std::endl;


    // get value in a spcific unit
    std::cout << "q1 in km is " << q1("km") << std::endl;

    // exception handling
    Quantity q11 (munits::Length, 1, "m");
    try {
        Quantity q12 = q11 / 0;
    }catch (std::overflow_error &e) {
        TRACE(e.what());
    }*/

    return 0;
}


