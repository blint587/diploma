/**
 * @author: Balint Molnar
 * @date: 2017.04.21
 */

#ifndef SANDBOX_RESOLVER_TEST_HPP
#define SANDBOX_RESOLVER_TEST_HPP

#include <list>
#include <string>
#include "gtest/gtest.h"
#include "../../src/uresolver.hpp"


class TestResolver : public testing::Test{};

TEST_F(TestResolver, resolve_W){
    /*
     * Resolves W to 'kg m2 s-3'
     * none recursive resolution
     * no prefix overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"W"};

    r.resolve(units);
    TRACEITERABLE(units);

    auto expexc = std::list<std::string>{"kg", "m2", "s-3"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_kW){
    /*
     * Resolves kW to 'Mg m2 s-3'
     * none recursive resolution
     * no prefix overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"kW"};

    r.resolve(units);

    auto expexc = std::list<std::string>{"Mg", "m2", "s-3"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_MW){
    /*
     * Resolves MW to 'Gg m2 s-3'
     * none recursive resolution
     * no prefix overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"MW"};

    r.resolve(units);

    auto expexc = std::list<std::string>{"Gg", "m2", "s-3"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_GW){
    /*
     * Resolves GW to 'Tg m2 s-3'
     * none recursive resolution
     * no prefix overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"GW"};

    r.resolve(units);

    auto expexc = std::list<std::string>{"Tg", "m2", "s-3"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_EW){
    /*
     * Resolves EW to 'Eg m2 s-3'
     * none recursive resolution
     * prefix overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"EW"};

    r.resolve(units);

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

    r.resolve(units);

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

    r.resolve(units);

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

    r.resolve(units);

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

    r.resolve(units);

    auto expexc = std::list<std::string>{"Mg", "m", "s-2"};

    EXPECT_EQ(units, expexc);

}
TEST_F(TestResolver, resolve_lbf){
    /*
     * Resolves lbf to 'slug ft s-2'
     * none recursive resolution
     * no prefix under/overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"lbf"};

    r.resolve(units);

    auto expexc = std::list<std::string>{"slug", "ft", "s-2"};

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

    r.resolve(units);

    auto expexc = std::list<std::string>{"kg", "s-2", "m-1"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_bar){
    /*
     * Resolves bar to 'Mg m s-2 m-2'
     * recursive resolution
     * no prefix under/overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"bar"};

    r.resolve(units);

    auto expexc = std::list<std::string>{"Mg", "ds-2", "m-1"};

    EXPECT_EQ(units, expexc);

}

TEST_F(TestResolver, resolve_Tesla){
    /*
     * Resolves T to "kg s-2 A-1"
     * no recursive resolution
     * no prefix under/overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"T"};

    r.resolve(units);

    auto expexc = std::list<std::string>{"kg",  "s-2",  "A-1"};

    EXPECT_EQ(units, expexc);

}
TEST_F(TestResolver, resolve_TerraTesla){
    /*
     * Resolves TT to "Pg s-2 A-1"
     * no recursive resolution
     * no prefix under/overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"TT"};

    r.resolve(units);
    TRACEITERABLE(units);
    auto expexc = std::list<std::string>{"Pg",  "s-2",  "A-1"};

    EXPECT_EQ(units, expexc);

}
TEST_F(TestResolver, resolve_ohm){
    /*
     * Resolves Ω to "Pg s-2 A-1"
     * no recursive resolution
     * no prefix under/overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"Ω"};

    r.resolve(units);
    TRACEITERABLE(units);
    auto expexc = std::list<std::string>{"kg",  "m2",  "s-3",  "A-2"};

    EXPECT_EQ(units, expexc);

}
TEST_F(TestResolver, resolve_psi){
    /*
     * Resolves psi to "Pg s-2 A-1"
     * no recursive resolution
     * no prefix under/overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"psi"};

    r.resolve(units);
    TRACEITERABLE(units);
    auto expexc = std::list<std::string>{"slug",  "ft",  "s-2",  "inc-2"};

    EXPECT_EQ(units, expexc);

}
TEST_F(TestResolver, resolve_W_h){
    /*
     * Resolves W h to "kg m2 s-3 h"
     * no recursive resolution
     * no prefix under/overflow
     */
    munits::Resolver r;
    std::list<std::string> units {"W", "h"};

    r.resolve(units);
    TRACEITERABLE(units);
    auto expexc = std::list<std::string>{"kg", "m2", "s-3", "h"};

    EXPECT_EQ(units, expexc);

}



#endif //SANDBOX_RESOLVER_TEST_HPP
