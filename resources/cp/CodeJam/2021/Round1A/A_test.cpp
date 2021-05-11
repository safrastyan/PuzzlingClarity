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


int add_0_to_second(const std::string& s1, std::string& s2)  
{
    int x = s1.size() - s2.size();
    for (int i = 0; i < x; ++i) {
        s2.push_back('0');
    }
    return x;
}

int first_smaller(const std::string& s1, const std::string& s2)
{
    for (int i = 0; i < s2.size(); ++i) {
        if (s2[i] < s1[i]) {
            return i;
        }
    }
    return -1;
}

bool all_nine(const std::string& s)
{
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '9') {
            return false;
        }
    }
    return true;
}

void pad(std::string& s, int x)
{
    for (int i = 0; i < x - s.size(); ++i) {
        s = std::string("0") + s;
    }
}


void solve()
{
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        s[i] = std::to_string(a[i]);
    }
    int res = 0;

    
    for (int i = 1; i < n; ++i) {
        if (std::stoll(s[i - 1]) < std::stoll(s[i])) {
            continue;
        }

        if (std::stoll(s[i - 1]) == std::stoll(s[i])) {
            s[i].push_back('0');
            ++res;
            continue;
        }


        int s1 = s[i - 1].size();
        int s2 = s[i].size();

        if (s1 == s2)  {
            s[i].push_back('0');
            ++res;
            continue;
        }
        
        std::string sub = s[i - 1].substr(0, s[i].size());
        
        if (std::stoll(sub) > std::stoll(s[i])) {
            res += add_0_to_second(s[i - 1], s[i]);
            s[i].push_back('0');
            ++res;
            continue;
        }
        
        if (std::stoll(sub) < std::stoll(s[i])) {
            res += add_0_to_second(s[i - 1], s[i]);
            continue;
        }

        
        std::string post = s[i - 1].substr(s[i].size(), s[i - 1].size() - s[i].size());

        if (all_nine(post)) {
            res += add_0_to_second(s[i - 1], s[i]);
            s[i].push_back('0');
            ++res;
            continue;            
        }
        
        std::string extra = std::to_string(std::stoll(post) + 1);
        pad(extra, post.size());
        s[i] += extra;
        res += post.size();
    }
    std::cout << res;
}


int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cout << "Case #" << i + 1 << ": ";
        solve();
        std::cout << std::endl;
    }
    return 0;
}