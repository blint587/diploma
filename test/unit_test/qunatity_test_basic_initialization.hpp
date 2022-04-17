#ifndef SANDBOX_QUNATITY_TEST_BASIC_INITIALIZATION_HPP
#define SANDBOX_QUNATITY_TEST_BASIC_INITIALIZATION_HPP

#include "gtest/gtest.h"
#include "../../src/quantity.h"
#include <stdexcept>

class TestQuantityBasicInitialization : public testing::Test{};



TEST_F(TestQuantityBasicInitialization, initializing_hPa){
    // [OCS-3306]
    EXPECT_NO_THROW(munits::Quantity p1(munits::Pressure, 1, "hPa"););

}



#endif //SANDBOX_QUNATITY_TEST_BASIC_INITIALIZATION_HPP
