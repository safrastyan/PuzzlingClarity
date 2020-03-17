/*
ID: safrast1
TASK: ariprog
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
    std::ifstream fin ("ariprog.in");
    std::ofstream fout ("ariprog.out");
    
    int n, m;
    fin >> n >> m;
    int M = 2 * m * m;
    std::vector<int> all(M + 3, 0);
    std::vector<int> items;
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            all[i * i + j * j] = 1;
            items.push_back(i * i + j * j);
        }
    }

    std::sort(items.begin(), items.end());
    auto r = std::unique(items.begin(), items.end());
    items.erase(r, items.end());

    bool outputed = false;

    for (int d = 1; d <= M / (n - 1); ++d) {
        for (auto i: items) {
           
            int nn = n - 1;
            int cur = i;
            while (nn != 0 && cur + d <= M && all[cur + d] == 1) {
                cur += d;
                --nn;
            }

            if (nn == 0) {
                outputed = true;
                fout << i << " " << d << std::endl;
            }
        }    
    }
    
    if (!outputed) {
        fout << "NONE" << std::endl;
    }

    return 0;
}