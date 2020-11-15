#include "algo/DivideAndConquer.hpp"

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

}
namespace pc {
namespace algo {


int median_of_array_divided_into_2_sorted_arrays(const std::vector<int>& p1, const std::vector<int>& p2)
{
    return median_of_2_helper(p1, 0, p1.size() - 1, p2, 0, p2.size() - 1);
}

}
}