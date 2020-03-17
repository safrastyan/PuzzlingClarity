/*
ID: safrast1
TASK: palsquare
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


std::string to_base(int n, int b)
{
    std::string res;
    while (n != 0) {
        int r = n % b;
        res.push_back(r < 10 ? static_cast<char>(r + '0') : static_cast<char>(r + 'A' - 10));
        n /= b;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

bool is_palindrome(const std::string& s)
{
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() 
{
    std::ifstream fin ("palsquare.in");
    std::ofstream fout ("palsquare.out");
    int b;
    fin >> b;
    for (int i = 1; i <= 300; ++i) {
        if (is_palindrome(to_base(i * i, b))) {
            fout << to_base(i, b) <<  " " << to_base(i * i, b) << std::endl;
        }
    }
    return 0;
}