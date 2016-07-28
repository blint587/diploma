#include "gtest/gtest.h"
#include "quantity_test_conversion.hpp"
#include "quantity_test_comparison.hpp"

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}