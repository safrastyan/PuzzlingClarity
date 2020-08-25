#include "algo/Intervals.hpp"

#include <algorithm>

namespace pc {
namespace algo {

int longest_interval_after_union(const std::vector<std::pair<int, int>>& intervals)
{
    auto a = intervals;
    std::sort(a.begin(), a.end());
    int res = a[0].second - a[0].first;
    int dur_so_far = res;
    int checkpoint = a[0].second;
    
    for (int i = 1; i < a.size(); ++i) {
        int p = a[i - 1].second;
        int c = a[i].first;
        if (c > checkpoint ) {
            dur_so_far = a[i].second - a[i].first;
            checkpoint = a[i].second;
            res = std::max(res, dur_so_far);
            continue;
        }
        checkpoint = std::max(checkpoint, a[i].second);
        dur_so_far += a[i].second - p;
        res = std::max(res, dur_so_far);
    }
    return res;
}

}
}