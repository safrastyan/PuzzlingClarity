/*
ID: safrast1
TASK: subset
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
#include <array>
#include <cassert>


int main() 
{
    std::ifstream fin ("subset.in");
    std::ofstream fout ("subset.out");
    

    int n;
    fin >> n;

    int s = (n * (n + 1)) / 2;
    if (s % 2 != 0) {
        fout << 0 << std::endl;
        return 0;
    }
    std::vector<long long> a(s + 20, 0);
    a[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = s - i; j >= 0; --j) {
            a[j + i] += a[j];
        }
    }
    fout << a[s / 2] / 2 << std::endl;

    return 0;
}