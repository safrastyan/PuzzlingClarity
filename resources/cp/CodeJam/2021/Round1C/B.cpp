#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <cctype>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>



bool small(const std::string& s1, const std::string& s2)
{
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == s2[i]) {
            continue;
        }
        return s1[i] < s2[i];
    }
    return false;
}


void gen(int n, int size, std::set<std::string>& all)
{
    for (int i = 1; i <= n; ++i) {
        std::string r = std::to_string(i);
        for (int j = i + 1; j <= n; ++j) {
            r += std::to_string(j);
            if (r.size() > size) {
                break;
            }
            all.insert(r);
        }
    }
}

std::set<int> trans(const std::set<std::string>& all)
{
    std::set<int> res;
    for (auto& s: all) {
        res.insert(std::stoi(s));
    }
    return res;
}

std::string brute(std::string n)
{
    std::set<std::string> all;
    gen(std::stoi(n), n.size() + 1, all);
    auto alli = trans(all);
    for (auto i: alli) {
        if (std::stoi(n) < i) {
            return std::to_string(i);
        }
    }
}


std::string clever(std::string n)
{

}


void solve()
{
    std::string n;
    std::cin >> n;
    if (n == "1") {
        std::cout << 12;
        return;
    }
    if (n.size() <= 7) {
        std::cout << brute(n);
        return;
    }
    
    std::cout << clever(n) << std::endl;
}


int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cout << "Case #" << i + 1 << ": ";
        solve();
        std::cout << std::endl;
    }
    return 0;
}