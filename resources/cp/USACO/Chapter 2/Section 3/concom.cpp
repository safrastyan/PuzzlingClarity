/*
ID: safrast1
TASK: concom
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

const int N = 103;

std::vector<std::pair<int, int>> solve(const std::vector<std::vector<int>>& a, int c, std::set<int>& controls)
{
    std::set<int> new_controls = controls;
    std::vector<int> table(N, 0);
    for (auto con: new_controls) {
        for (int j = 0; j < N; ++j) {
            table[j] += a[con][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        if (table[i] > 50 && i != c) {
            new_controls.insert(i);
        }
    }
    
    if (new_controls.size() == controls.size()) {
        std::vector<std::pair<int, int>> res;
        for (auto cc: controls) {
            if (cc != c) {
                res.push_back(std::make_pair(c, cc));
            }
        }
        return res;
    }
    return solve(a, c, new_controls);
}


int main() 
{
    std::ifstream fin ("concom.in");
    std::ofstream fout ("concom.out");
    
    int n;
    fin >> n;
    std::vector<std::vector<int>> a(N, std::vector<int>(N, 0));
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        fin >> x >> y >> z;
        a[x][y] = z;
    }
    for (int i = 0; i  < N; ++i) {
        std::set<int> controls;
        for (int j = 0; j < N; ++j) {
            if (a[i][j] > 50 && i != j) {
                controls.insert(j);
                continue;
            }
        }

        auto res = solve(a, i, controls);
        for (const auto& r: res) {
            fout << r.first << " " << r.second << std::endl;
        }
    }

    return 0;
}