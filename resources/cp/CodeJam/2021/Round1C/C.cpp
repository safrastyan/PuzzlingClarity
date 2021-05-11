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


static constexpr int CHEAT = 40;

std::string N(const std::string& s)
{
    std::string res = s;
    for (int i = 0; i < res.size(); ++i) {
        if (res[i] == '0') {
            res[i] = '1';
        } else {
            res[i] = '0';
        }
    }
    while (res.front() == '0') {
        res.erase(0, 1);
    }
    if (res.empty()) {
        return "0";
    }
    return res;
}

void solve()
{      
    std::string s, e;
    std::cin >> s >> e;

    if (s == e) {
        std::cout << "0";
        return;
    }
    std::map<std::string, int> all;
    all[s] = 1;
    all[e] = -1;
    std::queue<std::string> q;
    q.push(s);

    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        std::vector<std::string> cands;
        cands.push_back(N(s));
        if (s != "0") {
            cands.push_back(s + "0");
        }

        for (auto& n: cands) {
            if (n == e) {
                std::cout << all[s];
                return;
            }
        
            if (n.size() <= CHEAT && all[n] == 0) {
                all[n] = all[s] + 1;
                q.push(n);
            }
        }
    }

    

    if (all[e] == -1) {
        std::cout << "IMPOSSIBLE";
    }

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