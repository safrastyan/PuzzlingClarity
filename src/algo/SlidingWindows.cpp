#include "algo/SlidingWindows.hpp"

#include <algorithm>
#include <numeric>

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

std::vector<int> sliding_window_unique_chars(const std::string& s, int k)
{
    int cur = 0;
    std::vector<int> m(256, 0); ///mapping the chars, maximum 256 for this case
    for (int i = 0; i < k; ++i) {
        if (m[s[i]] == 0) {
            ++cur;
        }
        ++m[s[i]];
    }
    std::vector<int> res;
    res.push_back(cur);
    for (int i = k; i < s.size(); ++i) {
        if (m[s[i - k]] == 1) {
            --cur;
        }
        --m[s[i - k]];
        if (m[s[i]] == 0) {
            ++cur;
        }
        ++m[s[i]];
        res.push_back(cur);
    }
    return res;
}

}
}