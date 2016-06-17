//
// Created by bmolnar on 2016. 06. 17..
//

#ifndef MUSYS_QUANTITY_H
#define MUSYS_QUANTITY_H


template<class T>
class BaseQuantity {
    /*
    # 1. length
    # 2. mass
    # 3. time
    # 4. electric_current
    # 5. temperature
    # 6. amount_of_substance
    # 7. luminous_intensity
     */
public:
    const int dim_vector[7] = {0,0,0,0,0,0,0};

};


class Quantity : public BaseQuantity<Quantity>{

};

class Mass : public Quantity, public BaseQuantity<Mass> {
public:
    const int dim_vector[7] = {0,1,0,0,0,0,0};

};

//class Length : public Quantity{
//public:
//    const int dim_vector[7] = {1,0,0,0,0,0,0};
//
//};



//template <typename T>
//struct A
//{
//    static const int X = 1;
//
//    static void printX()
//    {
//        std::cout << "X=" << T::X << std::endl;
//    }
//};
//
//struct B : public A<B>
//{
//    static const int X = 2;
//};
//


#endif //MUSYS_QUANTITY_H
