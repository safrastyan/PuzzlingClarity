#define BOOST_TEST_MODULE fibonacci
#include <boost/test/unit_test.hpp>

#include "algo/fibonacci.hpp"

using namespace pc::algo;

BOOST_AUTO_TEST_SUITE(fibonacci_tests)

BOOST_AUTO_TEST_CASE(fib_rec_test)
{
    BOOST_CHECK_EQUAL(fib_rec(3), 2);
    BOOST_CHECK_EQUAL(fib_rec(6), 8);
}

BOOST_AUTO_TEST_CASE(fib_dp_test)
{
    for (int i = 4; i <= 10; ++i) {
        BOOST_CHECK_EQUAL(fib_rec(i), fib_dp(i));
    }
    BOOST_CHECK_EQUAL(fib_dp(3), 2);
    BOOST_CHECK_EQUAL(fib_dp(6), 8);
}


BOOST_AUTO_TEST_CASE(fib_tmp_test)
{
    static_assert(fib_tmp<6>::val == 8, "Fibonacci failed compile time");
}


BOOST_AUTO_TEST_SUITE_END()
