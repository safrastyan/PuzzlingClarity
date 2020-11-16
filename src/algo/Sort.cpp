#include "algo/Sort.hpp"

namespace pc {
namespace algo {


std::vector<int> bubble_sort(const std::vector<int>& arr)
{
    auto ans = arr;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < ans.size() - 1; ++i) {
            if (ans[i] > ans[i + 1]) {
                std::swap(ans[i], ans[i + 1]);
                sorted = false;
            }
        }
    }
    return ans;
}

std::vector<int> bucket_sort(const std::vector<int>& arr, int max_element)
{
    std::vector<int> count(max_element + 1, 0);
    for (int i = 0; i < arr.size(); ++i) {
        ++count[arr[i]];
    }
    std::vector<int> res;
    res.reserve(arr.size());
    for (int i = 0; i < count.size(); ++i) {
        for (int j = 0; j < count[i]; ++j) {
            res.push_back(i);
        }
    }
    return res;
}

std::vector<int> merge_sort(const std::vector<int>& arr)
{
    return arr;
}


}
}