

#ifndef SANDBOX_RESOLVER_TEST_HPP
#define SANDBOX_RESOLVER_TEST_HPP

#include <list>
#include <string>
#include "gtest/gtest.h"
#include "../../src/uresolver.hpp"


class TestResolver : public testing::Test{};

TEST_F(TestResolver, resolve_W){
    /*
     * Resolves kw to 'Tg m2 s-3'
     * none recursive resolution
     * no prefix overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"W"};

    r.resolve(units.begin(), units.end(), units);

    auto expexc = std::list<std::string>{"kg", "m2", "s-3"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_kW){
    /*
     * Resolves kw to 'Mg m2 s-3'
     * none recursive resolution
     * no prefix overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"kW"};

    r.resolve(units.begin(), units.end(), units);

    auto expexc = std::list<std::string>{"Mg", "m2", "s-3"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_MW){
    /*
     * Resolves kw to 'Gg m2 s-3'
     * none recursive resolution
     * no prefix overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"MW"};

    r.resolve(units.begin(), units.end(), units);

    auto expexc = std::list<std::string>{"Gg", "m2", "s-3"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_GW){
    /*
     * Resolves kw to 'Tg m2 s-3'
     * none recursive resolution
     * no prefix overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"GW"};

    r.resolve(units.begin(), units.end(), units);

    auto expexc = std::list<std::string>{"Tg", "m2", "s-3"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_EW){
    /*
     * Resolves kw to 'Tg m2 s-3'
     * none recursive resolution
     * prefix overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"EW"};

    r.resolve(units.begin(), units.end(), units);

    auto expexc = std::list<std::string>{"Eg", "m2", "ds-3"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_mW){
    /*
     * Resolves mW to 'g m2 s-3'
     * none recursive resolution
     * no prefix underflow
     */
    munits::Resolver r;
    std::list<std::string> units {"mW"};

    r.resolve(units.begin(), units.end(), units);

    auto expexc = std::list<std::string>{"g", "m2", "s-3"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_aW){
    /*
     * Resolves aW to 'fg m2 s-3'
     * none recursive resolution
     * no prefix underflow - not possible in the lower range
     */
    munits::Resolver r;
    std::list<std::string> units {"aW"};

    r.resolve(units.begin(), units.end(), units);

    auto expexc = std::list<std::string>{"fg", "m2", "s-3"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_N){
    /*
     * Resolves N to 'kg m s-2'
     * none recursive resolution
     * no prefix under/overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"N"};

    r.resolve(units.begin(), units.end(), units);

    auto expexc = std::list<std::string>{"kg", "m", "s-2"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_kN){
    /*
     * Resolves N to 'kg m s-2'
     * none recursive resolution
     * no prefix under/overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"kN"};

    r.resolve(units.begin(), units.end(), units);

    auto expexc = std::list<std::string>{"Mg", "m", "s-2"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_Pa){
    /*
     * Resolves Pa to 'kg m s-2 m-2'
     * recursive resolution
     * no prefix under/overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"Pa"};

    r.resolve(units.begin(), units.end(), units);

    auto expexc = std::list<std::string>{"kg", "m", "s-2", "m-2"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_bar){
    /*
     * Resolves Pa to 'kg m s-2 m-2'
     * recursive resolution
     * no prefix under/overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"bar"};

    r.resolve(units.begin(), units.end(), units);

    auto expexc = std::list<std::string>{"Mg", "m", "s-2", "dm-2"};

    EXPECT_EQ(units, expexc);

}



#endif //SANDBOX_RESOLVER_TEST_HPP
