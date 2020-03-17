/*
ID: safrast1
TASK: sprime
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

bool is_prime(int n)
{
    if (n == 1) {
        return false;
    }

    for (int i = 2; i <= static_cast<int>(std::sqrt(static_cast<double>(n))); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() 
{
    std::ifstream fin ("sprime.in");
    std::ofstream fout ("sprime.out");

    int n;
    fin >> n;
    std::vector<int> cur{2, 3, 5, 7};
    std::vector<int> add{1, 3, 7, 9};
    
    for (int i = 2; i <= n; ++i) {
        std::vector<int> new_cur;
        for (auto k1: cur) {
            for (auto k2: add) {
                if (is_prime(k1 * 10 + k2)) {
                    new_cur.push_back(k1 * 10 + k2);
                }
            }
        }
        cur = new_cur;
    }
    for (int i = 0; i < cur.size(); ++i) {
        fout << cur[i] << std::endl;
    }
    return 0;
}