/*
ID: safrast1
TASK: nocows
LANG: C++11          
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <array>
#include <cassert>


constexpr int MOD = 9901;

bool is_full(int h, int n)
{
    return (1 << h) & n == 0;
}

void update(std::vector<std::vector<int>>& a, int i, int j, int x)
{
    if (i < 1 || i >= a.size() || j < 1 || j >= a[0].size()) {
        return;
    }
    a[i][j] += x;
    a[i][j] %= MOD;
}

int main() 
{
    std::ifstream fin ("nocows.in");
    std::ofstream fout ("nocows.out");
    int n, h;
    fin >> n >> h;
    std::vector<std::vector<int>> a(h+ 10, std::vector<int>(n + 10, 0));
    a[1][1] = 1;
    for (int i = 1; i <= h - 1; ++i) {
        ///duplicating this height on left and right
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == 0) {
                continue;
            }
            for (int i1 = 1; i1 <= i - 1; ++i1) {
                for (int i2 = 1; i2 <= n; ++i2) {
                    if (a[i1][i2] == 0) {
                        continue;
                    }
                    
                    if (is_full(i + 1, j + i2 + 1)) {
                        a[i + 1][j + i2 + 1] = 1;
                        continue;
                    }
                    
                    if (i == i1 && j == i2) {
                        update(a, i + 1, j + i2 + 1, a[i][j]);
                        continue;
                    }

                     update(a, i + 1, j + i2 + 1, a[i1][i2] * a[i][j] * 2);                    
                }
            }

            /// same lenght
            for (int i1 = 1; i1 <= i; ++i1) {
                if (is_full(i + 1, i1 + j + 1)) {
                    a[i + 1][i1 + j + 1] = 1;
                    continue;
                }
                if (j == i1) {
                    update(a,i + 1, i1 + j + 1, a[i][j]);
                    continue;
                }
                update(a,  i + 1, j + i1 + 1, a[i][j] * a[i][i1] * 2);
                
            }
        }

    }
    fout << a[h][n] << std::endl;
    return 0;
}