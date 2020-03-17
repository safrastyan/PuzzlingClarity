/*
ID: safrast1
TASK: skidesign
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

int check_range(int x, int y, const std::vector<int>& a)
{
    int res = 0;
    for (auto c: a) {
        if (c >= x && c <= y) {
            continue;
        }
        int d = std::min( std::abs(x - c), std::abs(y - c));
        res += d * d;
    }
    return res;
}

int main() 
{
    std::ifstream fin ("skidesign.in");
    std::ofstream fout ("skidesign.out");
    
    int n;
    fin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }
    int res = check_range(0, 17, a);
    for (int i = 1; i <= 100 - 17; ++i) {
        res = std::min(res, check_range(i, i + 17, a));
    }
    fout << res << std::endl;
    return 0;
}