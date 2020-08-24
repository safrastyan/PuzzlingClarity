#include "algo/SlidingWindows.hpp"

#include <algorithm>

namespace pc {
namespace algo {

std::vector<int> sliding_window_sums(const std::vector<int>& elems,  int k)
{
    std::vector<int> res;
    int cur = std::accumulate(elems.begin(), elems.begin() + k, 0);
    res.push_back(cur);
    for (int i = k; i < elems.size(); ++i) {
        cur -= elems[i - k];
        cur += elems[i];
        res.push_back(cur);
    }
    return res;
}

}
}