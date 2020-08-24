#define BOOST_TEST_MODULE SlidingWindows
#include <boost/test/unit_test.hpp>

#include "algo/SlidingWindows.hpp"
#include "Base/Paths.hpp"
#include "io/io.hpp"
#include "Comparators/Comparators.hpp"
#include "Generators/ArrayGenerators.hpp"

using namespace pc::algo;
using namespace pc::base::paths;
using namespace pc::io;
using namespace pc::Comparators;

BOOST_AUTO_TEST_SUITE(SlidingWindows_tests)

BOOST_AUTO_TEST_CASE(sliding_window_sums_test)
{
    std::string path = algo_tests_path() + "/sliding_window_sums/";
    for (int t = 1; t <= 1; ++t) {
        std::fstream input(path + std::to_string(t) + ".in");        
        std::fstream output(path + std::to_string(t) + ".out");
        auto k = read_one<int>(input);
        auto elems = read_array<int>(input);
        auto res = read_array_u<int>(output);

        BOOST_CHECK(is_same(sliding_window_sums(elems, k), res));
    }


    /// this was the file test , also try with some runtime generated tests
    for (int t = 0; t <= 10; ++t) {
        int n = 1000;
        int k = 50;
    
        auto arr = pc::Generators::random_array(n);
        auto res1 = sliding_window_sums(arr,  k);

        std::vector<int> res;
        for (int i = 0; i + k <= arr.size(); ++i) {
            res.push_back(std::accumulate(arr.begin() + i, arr.begin() + i + k,  0));
        
        }
        BOOST_CHECK(is_same(res1, res));
    }
}

BOOST_AUTO_TEST_SUITE_END()
