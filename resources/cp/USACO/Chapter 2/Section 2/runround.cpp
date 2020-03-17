/*
ID: safrast1
TASK: runround
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

bool check(const std::string& num)
{
    std::vector<char> b(num.size(), 0);
    b[0] = 1;
    int pos = 0;
    int count = num[0] - '0';

    for (int i = 0; i < num.size(); ++i) {
        pos += count;
        pos %= num.size();
        if (b[pos] == 1 && i != num.size() - 1) {
            return false;
        }
        b[pos] = 1;
        count = num[pos] - '0';
    }
    return pos == 0;
}

int main() 
{
    std::ifstream fin ("runround.in");
    std::ofstream fout ("runround.out");
    unsigned int n;
    fin >> n;
    int len = std::to_string(n).size();
    std::set<unsigned int> ans;
   
    for (int len = 1; len <= 9; ++len) {
        std::string num = "123456789";
        while (true)  {
            auto subs = num.substr(0, len);
            if (check(subs)) {
                ans.insert(stoul(subs));
            }
            if (!std::next_permutation(num.begin(), num.end())) {
                break;
            }
        }
    }
    for (auto c: ans) {
        if (c > n) {
            fout << c << std::endl;
            return 0;
        }
    }
    return 0;
}