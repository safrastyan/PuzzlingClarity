#include "algo/DP.hpp"

#include <vector>
#include <algorithm>

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
    std::vector<char> dp(k + 1, 0);
    dp[0] = 1;
    for (auto elem: elems) {
        for (int j = 0; j + elem <= k; ++j) {
            if (dp[j] == 1) {
                dp[j + elem] = 1;
            }
        }
    }
    for (int i = k; i >= 0; --i) {
        if (dp[i] == 1) {
            return i;
        }
    }
    return 0;
}

int knapsack_classic(const std::vector<std::pair<int, int>>& elems, int k)
{
    std::vector<int> dp(k + 1, -1);
    dp[0] = 0;
    for (auto elem: elems) {
        for (int i = k; i >= 0; --i) {
            if (dp[i] != -1 && i + elem.first <= k) {
                dp[i + elem.first] = std::max(dp[i + elem.first], dp[i] + elem.second);
            }
        }
    }
    return *std::max_element(dp.begin(), dp.end());
}

int coin_exchange(const std::vector<int>& coins, int n) 
{
    if (n < 0) {
        return 0;
    }
    if (coins.empty()) {
        return 0;
    }
    std::vector<int> temp(n + 1, 0);
    temp[0] = 1;
    for (int coin: coins) {
        for (int i = coin; i <= n; ++i) {
            temp[i] += temp[i - coin];
        }
    }
    return temp[n];
}


} 
}
