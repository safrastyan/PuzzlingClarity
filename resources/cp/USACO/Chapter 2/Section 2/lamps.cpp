/*
ID: safrast1
TASK: lamps
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

char xo(char c1, char c2)
{
    return c1 == c2 ? '0': '1';
}

std::string action(const std::string& s, int x)
{
    std::string res = s;
    for (int i = 0; i < s.size(); ++i) {
        if (x == 1) {
            res[i] = xo('1', s[i]);
            continue;
        }
        if (x == 2) {
            if ((i + 1) % 2 == 1) {
                res[i] = xo('1', s[i]);
                continue;
            }
        }
        if (x == 3) {
            if ((i + 1) % 2 == 0) {
                res[i] = xo('1', s[i]);
                continue;
            }
        }
        if (x == 4) {
            if ((i + 1) % 3 == 1) {
                res[i] = xo('1', s[i]);
                continue;
            }
        }
    }
    return res;
}

bool valid(const std::string& s, const std::vector<int>& on, const std::vector<int>& off)
{
    for (auto c: on) {
        if (s[c - 1] == '0') {
            return false;
        }
    }
    for (auto c: off) {
        if (s[c - 1] == '1') {
            return false;
        }
    }
    return true;
}
int main() 
{
    std::ifstream fin ("lamps.in");
    std::ofstream fout ("lamps.out");
  
    int n, c;
    fin >> n >> c;
    std::vector<std::string> all;
    all.push_back(std::string(n, '1'));

    std::vector<int> on;
    std::vector<int> off;
    int x;
    while (fin >> x) {
        if (x == -1) {
            break;
        }
        on.push_back(x);
    }

    while (fin >> x) {
        if (x == -1) {
            break;
        }
        off.push_back(x);
    }

    /// collect 
    c = std::min(c, 4);
    for (int t = 0; t < c; ++t) {
        std::vector<std::string> new_vec;
        for (int i = 0; i < 4; ++i) {
            for (const auto& s: all) {
                new_vec.push_back(action(s, i + 1));
            }
        }

        all = new_vec;
    }

    std::sort(all.begin(), all.end());
    auto r = std::unique(all.begin(), all.end());
    all.erase(r, all.end());
    bool checked = false;
    for (const auto& s: all) {
        if (valid(s, on, off)) {
            checked = true;
            fout << s << std::endl;
        }
    }   
    if (!checked) {
        fout << "IMPOSSIBLE" << std::endl;
    }
    return 0;
}