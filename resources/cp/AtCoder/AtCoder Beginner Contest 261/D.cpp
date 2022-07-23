#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;
using ll=long long;
using ull = unsigned long long;


int main()
{
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	std::vector<int> streak(n + 1, 0);
	for (int i = 0; i < m; ++i) {
		int x, y;
		std::cin >> x >> y;
		streak[x] = y;
	}

	std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(n + 1, -1));

	dp[0][0] = 0;

	for (int i = 1; i <= n; ++i) {
		///try tails
		
		for (int j = 0; j < n; ++j) {
			if (dp[i - 1][j] == -1) {
				continue;
			}
			dp[i][0] = std::max(dp[i][0], dp[i - 1][j]);
		}


		///try heads
		for (int j = 0; j < n; ++j) {
			if (dp[i - 1][j] == -1) {
				continue;
			}
			long long New = a[i - 1];
			New += dp[i - 1][j] + streak[j + 1];
			dp[i][j + 1] = std::max(dp[i][j + 1], New);
		}
		
	}
	std::cout << *std::max_element(dp.back().begin(), dp.back().end()) << std::endl;
	
	
	return 0;
}
