#pragma once

#include <vector>
#include <string>

namespace pc {
namespace algo {

/**
 * @brief the sliding window problem. Calculate the sum of numbers on each k subarray 
 * @param elems elems
 * @param k the size of the window
 **/
std::vector<int> sliding_window_sums(const std::vector<int>& elems,  int k);

/**
 * @brief the problem where for each k substring we need to find the number of unique characters
 * @param s input string
 * @param k the window size
 **/
std::vector<int> sliding_window_unique_chars(const std::string& s, int k);

}
} 