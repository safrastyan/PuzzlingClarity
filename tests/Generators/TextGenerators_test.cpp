#define BOOST_TEST_MODULE TextGenerators
#include <boost/test/unit_test.hpp>

#include "Generators/TextGenerators.hpp"

#include <algorithm>

using namespace pc::Generators;

BOOST_AUTO_TEST_SUITE(TextGenerators_tests)

BOOST_AUTO_TEST_CASE(random_string_test)
{
    for (int i = 0; i < 100; ++i) {
        int n = std::rand() % 200 + 1;
        BOOST_CHECK_EQUAL(random_string(n).size(), n);
    }

}

BOOST_AUTO_TEST_CASE(random_string_alnum_test)
{
    for (int i = 0; i < 100; ++i) {
        int n = std::rand() % 200 + 1;
        BOOST_CHECK_EQUAL(random_string_alnum(n).size(), n);
    }

}

BOOST_AUTO_TEST_CASE(random_string_hq_test)
{
    for (int i = 0; i < 100; ++i) {
        int n = std::rand() % 200 + 1;
        BOOST_CHECK_EQUAL(random_string_hq(n).size(), n);
    }

}



BOOST_AUTO_TEST_SUITE_END()
