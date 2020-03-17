/*
ID: safrast1
TASK: crypt1
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

std::vector<char> digits(int n)
{
    std::vector<char> res;
    if (n == 0) {
        res.push_back('0');
        return res;
    }
    while (n != 0) {
        res.push_back('0' + n % 10);
        n /= 10;
    }
    return res;
}

bool valid(int n, const std::vector<char>& digs)
{
    auto d = digits(n);
    for (auto c: d) {
        if (std::find(digs.begin(), digs.end(), c) == digs.end()) {
            return false;
        }
    }
    return true;
}

int main() 
{
    std::ifstream fin ("crypt1.in");
    std::ofstream fout ("crypt1.out");
    int n;
    fin >> n;
    std::vector<char> digs(n);
    for (int i = 0; i < n; ++i) {
        fin >> digs[i];
    }

    int res = 0;
    for (int i = 100; i <= 999; ++i) {
        for (int j = 10; j <= 99; ++j) {
            int m1 = (j % 10) * i;
            int m2 = (j / 10) * i;
            int m3 = i * j;
            
            if (valid(i, digs) && valid(j, digs) && valid(m1, digs) && valid(m2, digs) && valid(m3, digs) && digits(m1).size() == 3 && digits(m2).size() == 3 && digits(m3).size() == 4) {
                ++res;
            }
        }
    } 
    fout << res << std::endl;   
    return 0;

}