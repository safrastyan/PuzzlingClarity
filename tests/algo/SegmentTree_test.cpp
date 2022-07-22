#define BOOST_TEST_MODULE SegmentTree
#include <boost/test/unit_test.hpp>

#include "algo/SegmentTree.hpp"
#include "Generators/ArrayGenerators.hpp"
#include "Generators/NumberGenerators.hpp"

using namespace pc::algo;
using namespace pc::Generators;

BOOST_AUTO_TEST_SUITE(SegmentTree_tests)

BOOST_AUTO_TEST_CASE(full_test)
{

    int n = 100000;
    int t = 10000;
    auto data = random_array(n);
    
    auto min = range_minimum_query(data);
    auto max = range_maximum_query(data);

    for (int i = 0; i < t; ++i) {
        int left = random_number(0, n - 1);
        int right = random_number(0, n - 1);
        if (left > right) {
            std::swap(left, right);
        }

        int std_min = *std::min_element(data.begin() + left, data.begin() + right + 1);
        int rmq_min = min.query(left, right);
        BOOST_CHECK_EQUAL(std_min, rmq_min);


        int std_max = *std::max_element(data.begin() + left, data.begin() + right + 1);
        int rmq_max = max.query(left, right);
        BOOST_CHECK_EQUAL(std_min, rmq_min);
    }
}


BOOST_AUTO_TEST_SUITE_END()
