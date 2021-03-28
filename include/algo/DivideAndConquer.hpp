#pragma once

#include <vector>

namespace pc {
namespace algo {

/// given 2 arrays, each of them are sorted. We need to find the median of the joint array of both
int median_of_array_divided_into_2_sorted_arrays(const std::vector<int>& p1, const std::vector<int>& p2);


/// count the number of pairs i and j where i < j and a[i] < 2 * a [j] with merge sort adaptation NlogN
int significant_inversion_count(const std::vector<int>&);


/// count the number of pairs i and j where i < j and a[i] < 2 * a [j] with brute force N^2
int significant_inversion_count_bad(const std::vector<int>& a);


}
}
