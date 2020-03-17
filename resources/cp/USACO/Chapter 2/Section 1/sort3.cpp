/*
ID: safrast1
TASK: sort3
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


int good_swap(long& s1, long& s2)
{
    int dif = std::min(s1, s2);
    s1 -= dif;
    s2 -= dif;
    return dif;
}

int main() 
{
    std::ifstream fin ("sort3.in");
    std::ofstream fout ("sort3.out");
    

    int n;
    fin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }

    std::vector<long> cor {std::count(a.begin(), a.end(), 1), std::count(a.begin(), a.end(), 2), std::count(a.begin(), a.end(), 3)};
    
    ///first number the correct one, and the second incorrect
    long t1_1 = std::count(a.begin(), a.begin() + cor[0], 1);
    long t1_2 = std::count(a.begin(), a.begin() + cor[0], 2);
    long t1_3 = std::count(a.begin(), a.begin() + cor[0], 3);


    long t2_1 = std::count(a.begin() + cor[0], a.begin() + cor[1] + cor[0], 1);
    long t2_2 = std::count(a.begin() + cor[0], a.begin() + cor[1] + cor[0], 2);
    long t2_3 = std::count(a.begin() + cor[0], a.begin() + cor[1] + cor[0], 3);
    
    
    long t3_1 = std::count(a.begin() + cor[0] + cor[1], a.end(), 1);
    long t3_2 = std::count(a.begin() + cor[0] + cor[1], a.end(), 2);
    long t3_3 = std::count(a.begin() + cor[0] + cor[1], a.end(), 3);
    
    int res = 0;

    res += good_swap(t1_2, t2_1);
    res += good_swap(t1_3, t3_1);
    res += good_swap(t2_3, t3_2);


    ///move ones from second section
    res += t2_1;
    t1_1 += t2_1;
    t1_3 -= t2_1;
    t2_3 += t2_1;
    t2_1 = 0;
    

    ///move ones from third setion
    res += t3_1;
    t1_1 += t3_1;
    t1_2 -= t3_1;
    t3_2 += t3_1;
    t3_1 = 0;

    fout << res + t2_3 << std::endl;
    

    return 0;
}