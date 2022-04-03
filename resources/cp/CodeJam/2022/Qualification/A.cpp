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

/*
2 2

Case #2:
..+-+
..|.|
+-+-+
|.|.|
+-+-+

*/

void solve(int t)
{

    int n, m;
    std::cin >> n >> m;

    n = 2 * n + 1;
    m = 2 * m + 1;
    std::vector<std::vector<char>> a(n, std::vector<char>(m, '.'));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i <= 1 && j <= 1) {
                continue;
            }

            if (i % 2 == 0) {
                a[i][j] = (j % 2 == 0) ? '+' : '-';
                continue;
            }
            if (j % 2 == 0) {
                a[i][j] = '|';
            }
        }
    }

    std::cout << "Case #" << t << ":" << std::endl;
    for (auto& row: a) {
        for (auto elem: row) {
            std::cout << elem;
        }
        std::cout << std::endl;
    }


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