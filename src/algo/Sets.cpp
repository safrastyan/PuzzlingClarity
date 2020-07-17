#include "algo/Sets.hpp"
#include "Utils/Distanes.hpp"
#include "Utils/Printer.hpp"

#include <algorithm>
#include <iostream>

namespace {

/// returns an empty array if at least one bucket is empty
std::vector<int> sums_of_buckets_if_valid(const std::vector<std::vector<int>>& buckets)
{
    std::vector<int> res;
    for (const auto& b: buckets) {
        if (b.size() == 0) {
            return std::vector<int>();
        }
        res.push_back(std::accumulate(b.begin(), b.end(), 0));
    }
    return res;
}

/// recrusive helper for k eqyal subsets problem
void k_almost_equal_subsets_helper(const std::vector<int>& elems, std::vector<std::vector<int>>& cur_buckets, std::vector<std::vector<int>>& best_buckets, int& best_sum, int current, bool verbose)
{
    if (verbose) {
        std::cout << "Current state of buckets is " << std::endl;
        pc::Utils::print(cur_buckets, "Bucket ");
    }

    if (current ==  elems.size()) {
        auto sums = sums_of_buckets_if_valid(cur_buckets);
        if (sums.size() == 0) {
            return;
        }
        auto dist = pc::Utils::cross_abs_dif_sum(sums);
        if (dist < best_sum || best_buckets.size() == 0) {
            best_buckets = cur_buckets;
            best_sum = dist;
        }
        return;
    }
    for (int i = current; i < elems.size(); ++i) {
        for (int j = 0; j < cur_buckets.size(); ++j) {
            cur_buckets[j].push_back(elems[i]);
            k_almost_equal_subsets_helper(elems, cur_buckets, best_buckets, best_sum, i + 1, verbose);
            cur_buckets[j].pop_back();
        }
    }
}

}


namespace pc {
namespace algo {



std::vector<std::vector<int>> k_almost_equal_subsets(const std::vector<int>& a, int k, bool verbose)
{
    std::vector<std::vector<int>> res;
    std::vector<std::vector<int>> cur_buckets(k);
    int best_sum = 0;
    k_almost_equal_subsets_helper(a, cur_buckets, res, best_sum, 0, verbose);
    return res;

}

}
}
