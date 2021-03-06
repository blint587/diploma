#include "gtest/gtest.h"
#include "quantity_test_conversion.hpp"
#include "quantity_test_comparison.hpp"
#include "quantity_test_base_mathop.hpp"
#include "quantity_test_derived_mathop.hpp"
#include "quantity_test_input_validation.hpp"
#include "quantity_test_representation.hpp"
#include "resolver_test.hpp"
#include "converterfunction_test.hpp"
#include "qunatity_test_basic_initialization.hpp"
#include "unit_validation_test.hpp"

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}