#include "algo/Numbers.hpp"

#include <algorithm>
#include <cmath>
#include <map>

namespace {
std::vector<std::pair<int, std::string>> int_roman_map{{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
                                                    {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} };

std::map<char , int> roman_chars ={{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
       
}

namespace pc {
namespace algo {

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

std::vector<int> prime_palindromes(int a, int b)
{
    ///TODO
    return std::vector<int>();
}

int gcd(int a, int b)
{
    if (a < b) {
        std::swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

std::string full_binary(int num, int length)
{
    std::string s(length, '0');
    int i = 0;
    while (num != 0) {
        s[i] = '0' + num % 2;
        num /= 2;
    ++i;
    }
    return s;
}

std::string int_to_roman(int n) 
{
    std::string res;
    for (int i = 0; n != 0; ++i) {
        auto r = int_roman_map[i];
        int c = n / r.first;
        n %= r.first;
        for (int j = 0; j < c; ++j) {
            res += r.second;
        }
    }
    return res;
}

int roman_to_int(const std::string& n)
{
    int res = 0;
    for(int i = 0 ; i < n.size()- 1 ; ++i){
        if (roman_chars[n[i]] < roman_chars[n[i+1]]) {
            res -= roman_chars[n[i]];
            continue;
        }
        res += roman_chars[n[i]];
    }
    res += roman_chars[n[n.size()-1]];
    return res;
}

std::vector<int> sieve_prime_numbers(int n)
{
    std::vector<char> m(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        if (m[i] == 0) {
            int j = i + i;
            while (j <= n) {
                m[j] = 1;
                j += i;
            }
        }
    }
    std::vector<int> res;
    for (int i = 2; i <= n; ++i) {
        if (m[i] == 0) {
            res.push_back(i);
        }
    }
    return res;
}

}
}
