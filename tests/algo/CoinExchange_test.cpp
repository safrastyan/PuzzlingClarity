#define BOOST_TEST_MODULE fibonacci
#include <boost/test/unit_test.hpp>

#include "algo/CoinExchange.hpp"

using namespace pc::algo;

BOOST_AUTO_TEST_SUITE(coine_xchange_tests)

BOOST_AUTO_TEST_CASE(exchange__corner_case_test)
{
    BOOST_CHECK_EQUAL(coin_exchange({1,2,5}, 0), 1);
    BOOST_CHECK_EQUAL(coin_exchange({2,4,8}, 11), 0);
    BOOST_CHECK_EQUAL(coin_exchange({}, 0), 0);
}


BOOST_AUTO_TEST_CASE(exchange_test)
{
    BOOST_CHECK_EQUAL(coin_exchange({1,2,3}, 4), 4);
    BOOST_CHECK_EQUAL(coin_exchange({2, 5, 3, 6}, 10), 5);
}


BOOST_AUTO_TEST_SUITE_END()
