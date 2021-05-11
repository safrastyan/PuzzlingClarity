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

struct I
{
    I(int xx, int yy): x(xx)
                     , y(yy)
                     , leftmost(false)
                     , rightmost(false)   {}

    int score2() const
    {
        if (!leftmost && !rightmost) {
            return (y - x) / 2;
        }
        return y - x;
    }   
    
    int score3() const
    {
        if (leftmost || rightmost) {
            return y - x;
        }
        
        return y - x - 1;
    }

    int x;
    int y;
    bool leftmost;
    bool rightmost;
};




double check(const std::vector<I>& inter, int i, int j, int k)
{
    int s = 0;
    if (i != j) {
        s += inter[i].score2();
        s += inter[j].score2();
    }  else {
        s += inter[i].score3();
    }

    return static_cast<double>(s) / static_cast<double>(k);
}

void solve()
{      
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    auto f = std::unique(a.begin(), a.end());
    a.erase(f, a.end());

    std::vector<I> inter;
    if (a.front() != 1) {
        I i(1, a.front());
        i.leftmost = true;
        inter.push_back(i);
    }


    
    for (int i = 0; i < a.size() - 1; ++i) {
        inter.push_back(I(a[i], a[i + 1]));    
    }

    if (a.back() != k) {
        I i(a.back(), k);
        i.rightmost = true;
        inter.push_back(i);
    }

    std::cout << "HGAd this many " << inter.size() << std::endl;


    double ans = 0.0;
    for (int i = 0; i < inter.size(); ++i) {
        for (int j = 0; j < inter.size(); ++j) {
            ans = std::max(ans, check(inter, i, j, k));
        }
    }

    std::cout << ans;
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