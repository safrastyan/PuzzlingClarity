/*
ID: safrast1
TASK: milk
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


int main() 
{
    std::ifstream fin ("milk.in");
    std::ofstream fout ("milk.out");

    int m, n;
    fin >> m >> n;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        fin >> a[i].first >> a[i].second;
    }
    int xop = 0;
    std::sort(a.begin(), a.end());
    for (const auto& p: a) {
        int u = std::min(m, p.second );
        xop += u * p.first;
        m -= u;
    }
    
    fout << xop << std::endl;
    return 0;
}