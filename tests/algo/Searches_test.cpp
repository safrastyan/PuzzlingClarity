#define BOOST_TEST_MODULE Searches
#include <boost/test/unit_test.hpp>

#include "algo/Searches.hpp"
#include "io/io.hpp"

using namespace pc::algo;
using namespace pc::io;

BOOST_AUTO_TEST_SUITE(Searches_tests)

BOOST_AUTO_TEST_CASE(binary_search_test)
{
    std::vector<int> a {1, 10, 100, 105, 1500000};
    
    for (int i = 0; i < a.size(); ++i) {
        BOOST_CHECK_EQUAL(binary_search(a, a[i]), i);
    }
    BOOST_CHECK_EQUAL(binary_search(a, 13), -1);
    
}

BOOST_AUTO_TEST_SUITE_END()
