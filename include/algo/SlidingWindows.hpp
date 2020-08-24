#pragma once

#include <vector>

namespace pc {
namespace algo {

/**
 * @brief the sliding window problem. Calculate the sum of numbers on each k subarray 
 * @param elems elems
 * @param k the size of the window
 **/
std::vector<int> sliding_window_sums(const std::vector<int>& elems,  int k);

}
} 