#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <fstream>
#include <cmath>

bool fio = false;

void solve(int t)
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int res = 0;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i) {
        if (res + 1 <= a[i]) {
            ++res;
        }
    }
    std::cout << "Case #" << t << ": " << res << std::endl;
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