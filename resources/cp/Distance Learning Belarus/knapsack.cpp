#include <vector>
#include <algorithm>
#include <iostream>

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
int main()
{
	int k, n;
	std::cin >> k >> n;
	std::vector<std::pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].first >> a[i].second; 
	}
	std::cout <<  knapsack_classic(a, k) << std::endl;
	return 0;
}