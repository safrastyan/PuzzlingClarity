#define BOOST_TEST_MODULE Sort
#include <boost/test/unit_test.hpp>

#include "algo/Sort.hpp"
#include "io/io.hpp"
#include "Comparators/Comparators.hpp"
#include "Generators/ArrayGenerators.hpp"

#include <functional>
#include <algorithm>

using namespace pc::algo;
using namespace pc::io;
using namespace pc::Comparators;
using namespace pc::Generators;

namespace {
    bool sort_test_verify(const std::vector<int>& arr, std::function<std::vector<int>(const std::vector<int>&)> sorter)
    {
        auto correct = arr;
        std::sort(correct.begin(), correct.end());
        auto answer = sorter(arr);
        if (!is_same(correct, answer)) {
            write(correct ,"Correct output");
            write(answer, "my answer");
            write("\n");
            write("\n");
        }
        return is_same(correct, answer);
    }


    std::vector<bool> sort_test_helper(int test_count, int array_size, std::function<std::vector<int>(const std::vector<int>&)> sorter)
    {
        std::vector<bool> answers;    
        for (int i = 0; i < test_count; ++i) {
            auto arr = random_array(array_size, 0, 50);
            answers.push_back(sort_test_verify(arr, sorter));
        }
        return answers;
    }
}

BOOST_AUTO_TEST_SUITE(DP_tests)

BOOST_AUTO_TEST_CASE(bubble_sort_test)
{
    auto ans = sort_test_helper(20, 1000, bubble_sort);
    for (auto b: ans) {
        BOOST_CHECK(b);
    }
}

BOOST_AUTO_TEST_CASE(bucket_sort_test)
{
    int test_count = 20;
    int array_size = 100000;
    int max_elem = 1000;
    for (int i = 0; i < test_count; ++i) {
        auto arr = random_array(array_size, 0, max_elem);
        auto correct = arr;
        std::sort(correct.begin(), correct.end());
        auto ans = bucket_sort(arr, max_elem);
        BOOST_CHECK(is_same(correct, ans));
    }
}

BOOST_AUTO_TEST_CASE(merge_sort_test)
{
    auto ans = sort_test_helper(1000, 200, merge_sort);
    for (auto b: ans) {
        BOOST_CHECK(b);
    }
}


BOOST_AUTO_TEST_SUITE_END()