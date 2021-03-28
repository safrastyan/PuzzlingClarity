#pragma once

#include <vector>

namespace pc {
namespace algo {

/**
 * @brief We have intervals. We need to find what is the longest resuting interval when we unite all of them 
 * @param intervals array of itnervals, first is the start, second is the end
 **/
int longest_interval_after_union(const std::vector<std::pair<int, int>>& intervals);

}
}
