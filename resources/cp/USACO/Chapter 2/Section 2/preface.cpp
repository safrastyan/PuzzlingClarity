/*
ID: safrast1
TASK: preface
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

std::string to_roman(int n) 
{
    std::string res;
    static std::vector<int> num{1,4,5,9,10,40,50,90,100,400,500,900,1000};
    static std::vector<std::string> sym{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i = 12;  
    while (n > 0) {
        int div = n / num[i];
        n = n % num[i];
        while(div--) {
            res += sym[i];
        }
        i--;
    }
    return res;
}

int main() 
{
    
    std::ifstream fin ("preface.in");
    std::ofstream fout ("preface.out");
    int n;
    fin >> n;
    
    
    std::map<char, int> res;
    for (int i = 1; i <= n; ++i) {
        auto r = to_roman(i);
        for (auto c: r) {
            ++res[c];
        }
    }
    std::vector<char> chars {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    for (int i = 0; i < chars.size(); ++i) {
        if (res[chars[i]] == 0) {
            continue;
        }
        fout << chars[i] << " " <<res[chars[i]] << std::endl;
    }
    return 0;
}