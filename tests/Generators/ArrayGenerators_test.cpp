#define BOOST_TEST_MODULE ArrayGenerators
#include <boost/test/unit_test.hpp>

#include "Generators/ArrayGenerators.hpp"

#include <algorithm>

BOOST_AUTO_TEST_SUITE(ArrayGenerators_tests)

BOOST_AUTO_TEST_CASE(ArrayFrom1toN_test)
{
    auto gen = pc::Generators::ArrayFrom1toN(100);
    BOOST_CHECK_EQUAL(gen.size(), 100);
    int sum = std::accumulate(gen.begin(), gen.end(), 0);
    BOOST_CHECK_EQUAL(sum, 5050);
}

BOOST_AUTO_TEST_SUITE_END()
