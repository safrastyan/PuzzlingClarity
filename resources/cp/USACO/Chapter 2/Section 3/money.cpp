/*
ID: safrast1
TASK: money
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


int main() 
{
    std::ifstream fin ("money.in");
    std::ofstream fout ("money.out");
    int n, m;
    fin >> n >> m;
    std::vector<long long> a(m + 1, 0);
    a[0] = 1;
    std::vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        fin >> coins[i];
    }
    for (auto c: coins) {
        for (int i = 0; i <= m; ++i) {
            if (i + c <= m) {
                a[i + c] += a[i];
            }
        }
    }
    fout << a[m] << std::endl;
    return 0;
}