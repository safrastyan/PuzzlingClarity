#define BOOST_TEST_MODULE DateAndTime
#include <boost/test/unit_test.hpp>

#include "algo/Sets.hpp"

using namespace pc::algo;

BOOST_AUTO_TEST_SUITE(DateAndTime_tests)

BOOST_AUTO_TEST_CASE(Basic_test)
{
    std::vector<char> a{'a', 'b', 'c'};
    auto res = generate_all_subsets(a);
    BOOST_CHECK_EQUAL(res.size(), 8);
    
}

BOOST_AUTO_TEST_SUITE_END()
