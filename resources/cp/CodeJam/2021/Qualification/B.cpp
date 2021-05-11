#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

void solve()
{
    std::string s;
    int x, y;
    std::cin >> x >> y;
    std::cin >> s;

    std::vector<int> c(s.size(), 0);
    std::vector<int> j(s.size(), 0);

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'C') {
            j[i] = 100000000;
        }
        if (s[i] == 'J') {
            c[i] = 100000000;
        }
    }    

    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '?') {
            c[i] = std::min(c[i - 1], j[i - 1] + y);
            j[i] = std::min(j[i - 1], c[i - 1] + x);
        } 
        if (s[i] == 'C') {
            c[i] = std::min(c[i - 1], j[i - 1] + y);
        }               
        if (s[i] == 'J') {
            j[i] = std::min(j[i - 1], c[i - 1] + x);
        }
    }
    
    std::cout << std::min(c.back(), j.back()) << std::endl;
}


int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}