/*
ID: safrast1
TASK: numtri
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
#include <cmath>
#include <tuple>


int main() 
{
    std::ifstream fin ("numtri.in");
    std::ofstream fout ("numtri.out");
  
    int n;
    fin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            fin >> a[i][j];
        }
    }

    res[0][0] = a[0][0];
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j <= i; ++j) {
            res[i + 1][j] = std::max(res[i + 1][j], res[i][j] + a[i +1][j]);
            res[i + 1][j + 1] = std::max(res[i + 1][j + 1], res[i][j] + a[i + 1][j + 1]);
        }
    }
    fout << *std::max_element(res.back().begin(), res.back().end()) << std::endl;
    return 0;
}