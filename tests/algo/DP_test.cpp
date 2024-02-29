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

///TODO need to create a generic judge with tester and runner

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

BOOST_AUTO_TEST_CASE(knapsack_classic_test)
{
    std::string path = algo_tests_path() + "/knapsack_classic/";
    for (int t = 1; t <= 1; ++t) {
        std::fstream input(path + std::to_string(t) + ".in");        
        std::fstream output(path + std::to_string(t) + ".out");
        auto k = read_one<int>(input);
        auto elems = read_array<int, int>(input);
        auto ans = read_one<int>(output);
        BOOST_CHECK_EQUAL(knapsack_classic(elems, k), ans);
    }
}

BOOST_AUTO_TEST_CASE(coin_exchange_corner_case_test)
{
    BOOST_CHECK_EQUAL(coin_exchange({1, 2, 5}, 0), 1);
    BOOST_CHECK_EQUAL(coin_exchange({2, 4, 8}, 11), 0);
    BOOST_CHECK_EQUAL(coin_exchange({}, 0), 0);
}

BOOST_AUTO_TEST_CASE(coin_exchange_test)
{
    BOOST_CHECK_EQUAL(coin_exchange({1, 2, 3}, 4), 4);
    BOOST_CHECK_EQUAL(coin_exchange({2, 5, 3, 6}, 10), 5);
}

BOOST_AUTO_TEST_CASE(longest_increasing_subsequence_length_test)
{
    BOOST_CHECK_EQUAL(longest_increasing_subsequence_length(std::vector<int>{10,9,2,5,3,7,101,18}), 4);
    BOOST_CHECK_EQUAL(longest_increasing_subsequence_length(std::vector<int>{0,1,0,3,2,3}), 4);
    BOOST_CHECK_EQUAL(longest_increasing_subsequence_length(std::vector<int>{7,7,7,7,7,7,7}), 1);
}

BOOST_AUTO_TEST_CASE(longest_common_subsequence_length_test)
{
    BOOST_CHECK_EQUAL(longest_common_subsequence_length("abcde", "ace"), 3);
    BOOST_CHECK_EQUAL(longest_common_subsequence_length("abc", "abc"), 3);
    BOOST_CHECK_EQUAL(longest_common_subsequence_length("abc", "def"), 0);
    
}
BOOST_AUTO_TEST_SUITE_END()
