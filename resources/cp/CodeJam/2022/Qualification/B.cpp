#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
#include <algorithm>
#include <limits>
#include <fstream>
#include <cmath>

bool fio = false;

void solve(int t)
{   
    static constexpr int TARGET = 1000000;
    int n = 3;
    int m = 4;
    bool ans = true;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
            if (a[i][j] == 0) {
                ans = false;
            }
        }
    }

    std::vector<int> mins(4, 0);
    for (int i = 0; i < m; ++i) {
        mins[i] = std::min(std::min(a[0][i], a[1][i]), a[2][i]);
    }

    int total = std::accumulate(mins.begin(), mins.end(), 0);
    if (total < TARGET) {
        ans = false;
    }

    int index = 0;
    int diff = total - TARGET;
    while (diff != 0) {
        int dec = std::min(diff, mins[index] - 1);
        mins[index] -= dec;
        ++index;
        diff -= dec;
    }

    
    std::cout << "Case #" << t << ": ";
    if (!ans) {
        std::cout << "IMPOSSIBLE" << std::endl;
        return;
    }
    std::cout << mins[0] << " " << mins[1] << " " << mins[2] << " " << mins[3] << std::endl;
}

int main()
{
    if (fio) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }
    return 0;
}