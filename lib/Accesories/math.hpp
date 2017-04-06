
#ifndef SANDBOX_MATH_HPP
#define SANDBOX_MATH_HPP


namespace math{

    unsigned long gcd(unsigned long u, unsigned long v ){
        while(v != 0){
            unsigned long r = u % v;
            u = v;
            v = r;
        }
        return u;
    }

//    unsigned int gcd(unsigned int u, unsigned int v ){
//        while(v != 0){
//            unsigned int r = u % v;
//            u = v;
//            v = r;
//        }
//        return u;
//    }

}

#endif //SANDBOX_MATH_HPP
