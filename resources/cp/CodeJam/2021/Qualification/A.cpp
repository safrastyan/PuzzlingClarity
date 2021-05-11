#include <iostream>
#include <vector>
#include <algorithm>


int reversort_weight(const std::vector<int>& vec)
{
    auto a = vec;
    int ans = 0;
    for (int i = 0; i < a.size() - 1; ++i) {
        auto elem = std::min_element(a.begin() + i, a.end());
        ans += elem - a.begin() - i + 1;
        std::reverse(a.begin() + i, elem + 1);
    }
    return ans;
}


void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::cout << reversort_weight(a) << std::endl;
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