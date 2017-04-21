#include "gtest/gtest.h"
#include "quantity_test_conversion.hpp"
#include "quantity_test_comparison.hpp"
#include "quantity_test_mathop.hpp"
#include "quantity_test_input_validation.hpp"
#include "quantity_test_representation.hpp"
#include "resolver_test.hpp"
#include "converterfunction_test.hpp"

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}