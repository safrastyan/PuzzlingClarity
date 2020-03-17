/*
ID: safrast1
TASK: barn1
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
    std::ifstream fin ("barn1.in");
    std::ofstream fout ("barn1.out");
    
    int m, s, n;
    fin >> m >> s >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }
    std::sort(a.begin(), a.end());
    std::vector<int> gaps;
    for (int i = 0; i < n - 1; ++i) {
        gaps.push_back(a[i + 1] - a[i] - 1);
    }
    s = a.back() - a.front() + 1;
    std::sort(gaps.begin(), gaps.end());
    for (int i = gaps.size() - 1; i > std::max(static_cast<int>(gaps.size() - m), -1); --i) {
        s -= gaps[i];
    }
    fout << s << std::endl;
    return 0;
}