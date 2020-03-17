/*
ID: safrast1
TASK: pprime
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

int len(int n)
{
    if (n == 0) {
        return 1;
    }

    int x = 0;
    while (n != 0) {
        ++x;
        n /= 10;
    }
    return x;
}

int reverse(int n)
{
    auto d = digits(n);
    int res = 0;
    int ten = 1;
    for (int i = d.size() - 1; i >= 0; --i) {
        res += ten * static_cast<int>(d[i] - '0');
        ten *= 10;
    }
    return res;
}

int concat(int x, int y)
{
    int l = len(y);
    int ten = 1;
    for (int i = 1; i <=l; ++i) {
        ten *= 10;
    }
    return x * ten + y;
}

bool is_prime(int n)
{
    if (n == 1) {
        return false;
    }

    for (int i = 2; i <= static_cast<int>(std::sqrt(static_cast<double>(n))); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
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

void candidates_with_length(std::vector<int>& res, int n)
{
    /// I have no nerve for this
    if (n == 2) {
        res = std::vector<int>{11};
        return;
    }
    if (n == 3) {
        for (int i = 100; i <= 999; ++i) {
            if (is_palindrome(std::to_string(i))) {
                res.push_back(i);
            }
        }
        return;
    }


    int d_n = (n - 2) / 2;
    int ten = 1;
    for (int i = 1; i <= d_n; ++i) {
        ten *= 10;
    }

    static const std::vector<int> start = {1, 3, 7, 9};

    for (int i = 0; i < ten; ++i) {
        int pad = len(i);
        std::string pad_s;
        for (int k = 0; k < d_n - pad; ++k) {
            pad_s += '0';
        } 
        
        for (auto ss: start) {
            std::string ress;
            ress += static_cast<char>(ss + '0');
            ress += pad_s;
            ress += std::to_string(i);
            
            std::string rev = ress;
            std::reverse(rev.begin(), rev.end());
            
            std::vector<int> pos_res;
            if (n % 2 == 1) {
                for (int j = 0; j <= 9; ++j) {
                    std::string resss = ress;
                    resss += static_cast<char>(j + '0');
                    resss += rev;
                    pos_res.push_back(std::stoi(resss));
                }
            } else {
                pos_res.push_back(std::stoi(ress + rev));
            }
            res.insert(res.end(), pos_res.begin(), pos_res.end());
        }
    }
}

void generate_all(std::vector<int>& all)
{
    ///1 length
    all.push_back(3);
    all.push_back(5);
    all.push_back(7);

    int lim = 4;

    for (int i = 2; i <= 8; ++i) {
        std::vector<int> maybe;
        candidates_with_length(maybe, i);
        for (auto j: maybe) {
            if (is_prime(j)) {
                all.push_back(j);
            }
        }
    }
}

int main() 
{
    std::ifstream fin ("pprime.in");
    std::ofstream fout ("pprime.out");
    
    int a, b;
    fin >> a >> b;
    std::vector<int> all;
    
    generate_all(all);
    std::sort(all.begin(), all.end());
    auto r = std::unique(all.begin(), all.end());
    all.erase(r, all.end());
    for (auto i: all) {
        if (i >= a && i <= b) {
            fout << i << std::endl;
        }
    }

    return 0;
}