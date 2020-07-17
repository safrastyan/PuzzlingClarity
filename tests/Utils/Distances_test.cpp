#define BOOST_TEST_MODULE Distances
#include <boost/test/unit_test.hpp>

#include "Utils/Distanes.hpp"

using namespace pc::Utils;

BOOST_AUTO_TEST_SUITE(Distances_tests)

BOOST_AUTO_TEST_CASE(cross_abs_dif_sum_test)
{
    std::vector<int> a{5, 5, 5, 5};
    BOOST_CHECK_EQUAL(cross_abs_dif_sum(a), 0);
    a = std::vector<int>{5, 4, 4, 4};
    BOOST_CHECK_EQUAL(cross_abs_dif_sum(a), 3);
}

BOOST_AUTO_TEST_SUITE_END()
