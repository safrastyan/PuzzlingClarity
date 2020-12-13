#define BOOST_TEST_MODULE TextGenerators
#include <boost/test/unit_test.hpp>

#include "Generators/NumberGenerators.hpp"

#include <algorithm>

using namespace pc::Generators;

BOOST_AUTO_TEST_SUITE(NumberGenerators_tests)

BOOST_AUTO_TEST_CASE(random_number_test)
{
    for (int i = 0; i < 100; ++i) {
        auto n = random_number(1, 100);
        BOOST_CHECK(n >= 1 && n <= 100);
    }

}



BOOST_AUTO_TEST_SUITE_END()
