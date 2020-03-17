/*
ID: safrast1
TASK: frac1
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

int gcd(int a, int b)
{
    if (a < b) {
        std::swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool comp (const std::pair<int, int>& p1, const std::pair<int, int>& p2)
{
    float f1 = static_cast<float>(p1.first) / static_cast<float>(p1.second);
    float f2 = static_cast<float>(p2.first) / static_cast<float>(p2.second);
    return f1 < f2;
}

int main() 
{
    std::ifstream fin ("frac1.in");
    std::ofstream fout ("frac1.out");
    
    std::set<std::pair<int, int>> res;
    int n;
    fin >> n;
    res.insert(std::make_pair(0, 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            res.insert(std::make_pair(i / gcd(i, j), j / gcd(i, j)));
        }
    }
    std::vector<std::pair<int, int>> R;
    for (const auto p: res) {
        R.push_back(p);
    }
    std::sort(R.begin(), R.end(), comp);
    for (const auto p: R) {
        fout <<p.first << "/" << p.second << std::endl;
    }
    return 0;
}