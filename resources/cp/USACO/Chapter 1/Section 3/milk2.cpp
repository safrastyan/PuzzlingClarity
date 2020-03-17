/*
ID: safrast1
TASK: milk2
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
    std::ifstream fin ("milk2.in");
    std::ofstream fout ("milk2.out");
    
    int n;
    fin >> n;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        fin >> a[i].first >> a[i].second;
    }

    std::sort(a.begin(), a.end());
    int bdo = a[0].second - a[0].first;
    int dur_so_far = bdo;
    int checkpoint = a[0].second;
    int bdont = 0;

    for (int i = 1; i < a.size(); ++i) {
        int p = a[i - 1].second;
        int c = a[i].first;
        if (c > checkpoint ) {
            bdont = std::max(bdont, c - checkpoint);
            dur_so_far = a[i].second - a[i].first;
            checkpoint = a[i].second;
            bdo = std::max(bdo, dur_so_far);
            continue;
        }
        checkpoint = std::max(checkpoint, a[i].second);
        dur_so_far += a[i].second - p;
        bdo = std::max(bdo, dur_so_far);
    }
    fout << bdo << " " << bdont << std::endl;
    return 0;
}