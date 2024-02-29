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



int longest_increasing_subsequence_length(const std::vector<int>& a)
{
    int n = a.size();
    int ans = 0;
    std::vector<int> lis(n, 1);
   
   
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    
    return *std::max_element(lis.begin(), lis.end());
}

int longest_common_subsequence_length(const std::string&  s1, const std::string& s2)
{
    int n = s1.size();
    int m = s2.size();
 
    std::vector<int> prev(m + 1, 0);
    std::vector<int> cur(m + 1, 0);

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                cur[j] = 1 + prev[j - 1];
                continue;
            }
            cur[j] = std::max(cur[j - 1], prev[j]);
        }
        prev = cur;
    }
 
    return cur[m];

}


} 
}
