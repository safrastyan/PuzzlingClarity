#pragma once

#include <vector>

namespace pc {
namespace algo {

/// Performs binary search and returns the position of the elem. -1 if none exists. array must be sorted or else this doesn't make any sense
int binary_search(const std::vector<int>& a, int elem);

}
}