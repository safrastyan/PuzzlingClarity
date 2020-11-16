#define BOOST_TEST_MODULE DivideAndConquer
#include <boost/test/unit_test.hpp>

#include "algo/DivideAndConquer.hpp"
#include "Base/Paths.hpp"
#include "io/io.hpp"
#include "Generators/ArrayGenerators.hpp"

#include <algorithm>

using namespace pc::algo;
using namespace pc::base::paths;
using namespace pc::io;
using namespace pc::Generators;

BOOST_AUTO_TEST_SUITE(DivideAndCOnquerTest_tests)

BOOST_AUTO_TEST_CASE(median_of_array_divided_into_2_sorted_arrays_test)
{   
    int test_count = 40;
    for (int i = 0; i < test_count; ++i) {
        int n = 2000;
        auto init_array = random_array(n, 1, 100);
        std::sort(init_array.begin(), init_array.end());
        auto un = std::unique(init_array.begin(), init_array.end());
        init_array.erase(un, init_array.end());
    
        if (init_array.size() % 2 == 1) {
            init_array.pop_back();
        }
        write(init_array.size(), "Size of the generated array");
        write(init_array, "initia array");
        
        n = init_array.size();
        int ans = init_array[n / 2 - 1];
        std::random_shuffle(init_array.begin(), init_array.end());

        std::vector<int> half1, half2;

        half1.insert(half1.begin(), init_array.begin(), init_array.begin() + n / 2);
        half2.insert(half2.begin(), init_array.begin() + n / 2, init_array.end());
        std::sort(half1.begin(), half1.end());
        std::sort(half2.begin(), half2.end());
        write(half1, "First half of the array");
        write(half2, "Second half of the array");
        auto res = median_of_array_divided_into_2_sorted_arrays(half1, half2);
        BOOST_CHECK_EQUAL(ans, res);

    }

}

BOOST_AUTO_TEST_CASE(significant_inversion_count_test)
{
    write("Testing significant inversion count");
    int test_count = 40;
    for (int i = 0; i < test_count; ++i) {
        int n = 1000;
        auto arr = random_array(n);
        auto g_res = significant_inversion_count(arr);
        auto b_res = significant_inversion_count_bad(arr);
        BOOST_CHECK_EQUAL(g_res, b_res);
    }
}

BOOST_AUTO_TEST_SUITE_END()
