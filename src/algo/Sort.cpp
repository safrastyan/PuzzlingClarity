#include "algo/Sort.hpp"


namespace {

void merge(std::vector<int>& arr, int left, int middle, int right)
{
    std::vector<int> left_arr;
    std::vector<int> right_arr;
    left_arr.insert(left_arr.begin(), arr.begin() + left, arr.begin() + middle + 1);
    right_arr.insert(right_arr.begin(), arr.begin() + middle + 1, arr.begin() + right + 1);

    int k = left;
    int left_i = 0;
    int right_i = 0;
    while (left_i < left_arr.size() && right_i < right_arr.size()) {
        if (left_arr[left_i] < right_arr[right_i]) {
            arr[k] = left_arr[left_i];
            ++left_i;
            ++k;
            continue;
        }
        arr[k] = right_arr[right_i];
        ++right_i;
        ++k;
    }

    //remaining elements
    for (int i = left_i; i < left_arr.size(); ++i) {
        arr[k] = left_arr[i];
        ++k;
    }

    for (int i = right_i; i < right_arr.size(); ++i) {
        arr[k] = right_arr[i];
        ++k;
    }
}

void merge_sort_rec(std::vector<int>& arr, int left, int right)
{
    if (left >= right) {
        return;
    }

    int mid = (right + left - 1) / 2;
    merge_sort_rec(arr, left, mid);
    merge_sort_rec(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


}


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
    auto res = arr;
    merge_sort_rec(res, 0, res.size());
    return res;
}


}
}