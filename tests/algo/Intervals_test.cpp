#define BOOST_TEST_MODULE Intervals
#include <boost/test/unit_test.hpp>

#include "algo/Intervals.hpp"
#include "io/io.hpp"
#include "Base/Paths.hpp"

using namespace pc::algo;
using namespace pc::io;
using namespace pc::base::paths;

BOOST_AUTO_TEST_SUITE(Intervals_tests)

BOOST_AUTO_TEST_CASE(longest_interval_after_union_test)
{
    std::string path = algo_tests_path() + "/longest_interval_after_union/";
    for (int t = 1; t <= 6; ++t) {
        std::fstream input(path + std::to_string(t) + ".in");        
        std::fstream output(path + std::to_string(t) + ".out");
        auto elems = read_array<int, int>(input);
        auto ans = read_one<int>(output);
        BOOST_CHECK_EQUAL(longest_interval_after_union(elems), ans);
    }
}

BOOST_AUTO_TEST_SUITE_END()
