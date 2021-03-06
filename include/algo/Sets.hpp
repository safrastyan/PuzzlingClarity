#pragma once 

#include <vector>
#include <set>

namespace pc {
namespace algo {

/// uses bitmask on the number of elements and generates all the subsets. Be careful, very consuming process
template<typename T>
std::vector<std::vector<T>> generate_all_subsets(const std::vector<T>&);

/// receives an array and divides it into K subarray, the sub difference of which is minimal aka, non empty subsets which have almost equal sums. 
/// pass verbose=true if you want detailed output
std::vector<std::vector<int>> k_almost_equal_subsets(const std::vector<int>& a, int k, bool verbose=false);

/// intersect the second set with the first, the result is stored in the first
void intersect_with(std::set<int>& s1, const std::set<int>& s2);

}
}

#include "Sets_impl.hpp"
