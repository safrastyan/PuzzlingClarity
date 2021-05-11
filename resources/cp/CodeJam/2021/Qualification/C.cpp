#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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


void exper(int n)
{
    std::map<int, std::vector<std::vector<int>>> all;

    std::vector<int> a(n);
    for (int i = 0; i < a.size(); ++i) {
        a[i] = i;
    }

    auto c = reversort_weight(a);
    all[c].push_back(a);
    while (std::next_permutation(a.begin(), a.end())) {
        c = reversort_weight(a);
        all[c].push_back(a);
    }
    
    
}

int main()
{


    exper();
    return 0;
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}