#define BOOST_TEST_MODULE DP
#include <boost/test/unit_test.hpp>

#include "algo/DP.hpp"
#include "algo/fibonacci.hpp"
#include "Base/Paths.hpp"
#include "io/io.hpp"

using namespace pc::algo;
using namespace pc::base::paths;
using namespace pc::io;

BOOST_AUTO_TEST_SUITE(DP_tests)

BOOST_AUTO_TEST_CASE(zeros_and_ones_test)
{
    for (int i = 1; i <= 10; ++i) {
        BOOST_CHECK_EQUAL(zeros_and_ones(i), fib_dp(i + 2));
    }
}

BOOST_AUTO_TEST_CASE(knapsack_infinte_elements_test)
{
    std::string path = algo_tests_path() + "/knapsack_infinte_elements/";
    for (int t = 1; t <= 2; ++t) {
        std::fstream input(path + std::to_string(t) + ".in");        
        std::fstream output(path + std::to_string(t) + ".out");
        auto elems = read_array<int>(input);
        auto k = read_one<int>(input);
        auto ans = read_one<int>(output);
        BOOST_CHECK_EQUAL(knapsack_infinte_elements(elems, k), ans);
    }
}

BOOST_AUTO_TEST_SUITE_END()
