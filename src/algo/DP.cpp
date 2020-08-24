#include "algo/DP.hpp"

#include <vector>

namespace pc {
namespace algo {

int zeros_and_ones(int n)
{
    std::vector<int> o(n + 1, 0), z(n + 1, 0);
    o[1] = z[1] = 1;
    for (int i = 2; i <= n; ++i) {
        z[i] = z[i - 1] + o[i - 1];
        o[i] = z[i - 1];
    }
    return o[n] + z[n];
}

int knapsack_infinte_elements(const std::vector<int>& elems, int k)
{
    std::vector<char> m(k + 1, 0);
    m[0] = 1;
    for (auto elem: elems) {
        for (int j = 0; j + elem <= k; ++j) {
            if (m[j] == 1) {
                m[j + elem] = 1;
            }
        }
    }
    for (int i = k; i >= 0; --i) {
        if (m[i] == 1) {
            return i;
        }
    }
    return 0;
}


} 
}
