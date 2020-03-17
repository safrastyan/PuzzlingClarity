#define BOOST_TEST_MODULE DateAndTime
#include <boost/test/unit_test.hpp>

#include "algo/DateAndTime.hpp"

using namespace pc::algo;

BOOST_AUTO_TEST_SUITE(DateAndTime_tests)

BOOST_AUTO_TEST_CASE(Basic_test)
{
    BOOST_CHECK(is_leap(400));
    BOOST_CHECK(!is_leap(100));
    BOOST_CHECK(!is_leap(11));
}

BOOST_AUTO_TEST_SUITE_END()
