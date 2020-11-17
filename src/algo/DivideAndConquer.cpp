#include "algo/DivideAndConquer.hpp"
#include "algo/Sort.hpp"

#include <algorithm>
#include <iostream>
#include "io/io.hpp"
namespace {

int median_of_2_helper(const std::vector<int>& half1, int half1_left, int half1_right, const std::vector<int>& half2, int half2_left, int half2_right)
{
   if (half1_right - half1_left <= 2) {        
        ///little bit of hacking
        std::vector<int> res;
        res.insert(res.begin(), half1.begin() + half1_left, half1.begin() + half1_right + 1);
        res.insert(res.end(), half2.begin() + half2_left, half2.begin() + half2_right + 1);
        std::sort(res.begin(), res.end());
        
        return res[res.size() / 2 - 1];
    } 
    int len = half1_right - half1_left + 1;

    int mid1_pos = (half1_left + half1_right) / 2;
    int mid2_pos = (half2_left + half2_right) / 2;
    
    if (half1[mid1_pos] < half2[mid2_pos]) {
        return median_of_2_helper(half1, mid1_pos , half1_right, half2, half2_left, mid2_pos + (len % 2 == 0 ? 1 : 0));
    }
    return median_of_2_helper(half1, half1_left, mid1_pos + (len % 2 == 0 ? 1 : 0), half2, mid2_pos, half2_right);
}


int significant_inversion_count_helper_rec(std::vector<int>& a, int left, int right)
{
    if (left >= right) {
        return 0;
    }

    int mid = (right + left - 1) / 2;
    int invs_left = significant_inversion_count_helper_rec(a, left, mid);
    int invs_right = significant_inversion_count_helper_rec(a, mid + 1, right);
    
    ///counting the significant inversiont
    int left_i = left;
    int right_i = mid + 1;
    int inv_current = 0;
    
    while (left_i <= mid && right_i <= right) {
        if (a[left_i] > 2 * a[right_i]) {
            inv_current += mid - left_i + 1;
            ++right_i;
        } else {
            ++left_i;
        }
    }
    
    pc::algo::merge(a, left, mid, right);


    return invs_left + invs_right + inv_current;
}   
    
}

namespace pc {
namespace algo {


int median_of_array_divided_into_2_sorted_arrays(const std::vector<int>& p1, const std::vector<int>& p2)
{
    return median_of_2_helper(p1, 0, p1.size() - 1, p2, 0, p2.size() - 1);
}

int significant_inversion_count(const std::vector<int>& a)
{
    auto arr = a;
    return significant_inversion_count_helper_rec(arr, 0, a.size() - 1);
}

int significant_inversion_count_bad(const std::vector<int>& a)
{
    int res = 0;
    for (int i = 0; i < a.size() - 1; ++i) {
        for (int j = i + 1; j < a.size(); ++j) {
            if (a[i] > a[j] * 2) {
                ++res;
            }
        }   
    }
    return res;
}

}
}