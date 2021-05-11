#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

std::vector<std::pair<int, int>> sort(const std::vector<std::string>& s)
{
    std::vector<std::pair<int, int>> res(100);
    for (int i = 0; i < res.size(); ++i) {
        res[i].second = i;
        res[i].first = std::count(s[i].begin(), s[i].end(), '1');
    }
    std::sort(res.begin(), res.end());
    return res;
}
void solve()
{
    int p;
    std::cin >> p;
    std::vector<std::string> s(100);
    for (int i = 0; i < 100; ++i) {
        std::cin >> s[i];
    }
    auto r = sort(s);
    std::cout << r.back().second + 1 << std::endl;

    for (int i = 0; i < r.size(); ++i) {
   //     std::cout << "{ " << r[i].first << ", " << r[i].second << "}, ";
    }
}


int main()
{
   std::freopen("input.txt", "r", stdin);
    
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}