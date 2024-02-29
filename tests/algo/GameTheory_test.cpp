#define BOOST_TEST_MODULE GameTheory
#include <boost/test/unit_test.hpp>

#include "algo/GameTheory.hpp"

using namespace pc::algo;

BOOST_AUTO_TEST_SUITE(DGameTheory_tests)

BOOST_AUTO_TEST_CASE(josephus_test)
{
    BOOST_CHECK_EQUAL(josephus(5, 2), 3);
    BOOST_CHECK_EQUAL(josephus(6, 5), 1);
}

BOOST_AUTO_TEST_SUITE_END()
