
#ifndef MUSYS_ACCESORYS_HPP
#define MUSYS_ACCESORYS_HPP

#include <vector>
#include <iostream>
#include <map>

#ifdef DEBUG
    #include <iomanip>
    #define TRACE(x)  std::cerr << std::setprecision(18) << (x) << std::endl
    #define TRACEWHAT(x, what)  std::cerr << std::setprecision(18) << (what) << " " << (x) << std::endl
    #define TRACEITERABLE(x) accessories::print_iterable(x)
    #define TRACEMAP(x) accessories::print_map(x)
#else
    #define TRACE(x)
    #define TRACEMAP(x)
    #define TRACEWHAT(x, what)
    #define TRACEITERABLE(x)
#endif


namespace accessories{

    template<class C>
    void print_iterable(const C &a){
        std::cerr << "[ ";
        for( auto b = a.begin(); b != a.end(); ++b ){
            std::cerr << *b << ", ";
        }
        std::cerr << "]" << std::endl;

    }

    template<class K, class V>
    void print_map(const std::map<K, V> &m){
        std::cerr << "{ ";
        for( auto p = m.begin(); p != m.end(); ++p ){
            std::cerr << "Key: " << p->first << " Value: " << p->second << ", ";
        }
        std::cerr << "}" << std::endl;



    };    template<class K, class V>
    void print_map(const std::map<const K, V> &m){
        std::cerr << "{ ";
        for( auto p = m.begin(); p != m.end(); ++p ){
            std::cerr << "Key: " << p->first << " Value: " << p->second << ", ";
        }
        std::cerr << "}" << std::endl;



    };

}

#endif //MUSYS_ACCESORYS_HPP
