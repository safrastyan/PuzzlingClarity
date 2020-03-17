/*
ID: safrast1
TASK: hamming
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


int hamming_distance(const std::string& s1, const std::string& s2)
{
    assert(s1.size() == s2.size());
    int res = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) {
            ++res;
        }
    }
    return res;
}

std::string full_binary(int num, int length)
{
    std::string s(length, '0');
    int i = 0;
    while (num != 0) {
        s[i] = '0' + num % 2;
        num /= 2;
        ++i;
    }
    return s;
}


int main() 
{
    std::ifstream fin ("hamming.in");
    std::ofstream fout ("hamming.out");


    int n, b, d;
    fin >> n >> b >> d;
    int m = (1 << b);

    std::vector<std::vector<int>> dist(m+ 1, std::vector<int>(m + 1, 0));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            dist[i][j] = hamming_distance(full_binary(i, b), full_binary(j, b));
        }
    }

    std::vector<int> res{0};

    for (int t = 0; t < n - 1; ++t) {
        int best = -1;
        int min_dist = 10000;
            
        
        for (int j = 0; j <= m; ++j) {
            
            if (std::find(res.begin(), res.end(), j) != res.end() ) {
                continue;
            }

            int max_val = 0;
            bool valid = true;
            for (auto col: res) {
                if (dist[col][j] < d) {
                    valid = false;
                    break;
                }
                max_val = std::max(dist[col][j], max_val);
            }
            if (valid) {
                if (max_val < min_dist) {
                    min_dist = max_val;
                    best = j;
                }
            }

        }
        res.push_back(best);
    }


    for (int i = 0; i < res.size(); ++i) {
        fout << res[i];
        if (i % 10 != 9 && i != res.size() - 1) {
            fout << " ";
        }
        if (i % 10 == 9) {
            fout << std::endl;
        }
    }
    if (res.size() % 10 != 0) {
        fout << std::endl;
    }
    return 0;
}