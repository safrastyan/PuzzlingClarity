#include "algo/Strings.hpp"

#include <algorithm>
#include <cassert>
#include <limits>
#include <stack>

namespace {
bool matching(char c1, char c2)
{
    return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
}


bool is_pattern_empty(const std::string& p)
{
    int c = std::count(p.begin(), p.end(), '*');
    return c == p.size() / 2 && p.size() % 2 == 0;
}

std::string cut_prefix(const std::string& s, int pref)
{
    return s.substr(pref, s.size() - pref);
}

void pattern_match_helper(const std::string& s, const std::string& p, bool& ans)
{
    if (p.empty()) {
        if (s.empty()) {
            ans = true;
        }
        return;
    }

    if (s.empty()) {
        if (is_pattern_empty(p)) {
            ans = true;
        }
        return;
    }

    if (p.size() == 1) {
        if (s[0] == p[0] || p[0] == '.') {
            pattern_match_helper(cut_prefix(s, 1), cut_prefix(p, 1), ans);
        }
        return;
    }

    if (p[1] == '*') {
        pattern_match_helper(s, cut_prefix(p, 2), ans);
        if (p[0] == '.' || p[0] == s[0]) {
            pattern_match_helper(cut_prefix(s, 1), p, ans);
        }
        return;
    }

    if (p[0] == s[0] || p[0] == '.') {
        pattern_match_helper(cut_prefix(s, 1),  cut_prefix(p, 1), ans);
    }

}

}

namespace pc {
namespace algo {


bool is_palindrome(const std::string& s)
{
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int hamming_distance(const std::string& s1, const std::string& s2)
{
    assert(s1.size() == s2.size());
    int res = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) {
            ++res;
        }
    }
    return res;
}

bool is_correct_bracket_expr(const std::string& s)
{
    std::stack<char> stack;
    for (auto c: s) {
        if (stack.empty()) {
            stack.push(c);
            continue;
        }
        auto cc = stack.top();
        if (matching(cc, c)) {
            stack.pop();
            continue;
        }
        stack.push(c);
    }
    return stack.empty();
}

bool is_vowel(char c)
{
    c = std::tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

std::vector<std::string> split(const std::string& s)
{
    std::stringstream ss(s);
    std::vector<std::string> res;
    std::string word;
    while (ss >> word) {
        res.push_back(word);
    }
    return res;
}


int edit_distance(const std::string& word1, const std::string& word2) 
{
    int n = word1.size();
    int m = word2.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, std::numeric_limits<int>::max()));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                continue;
            }
            int replace = dp[i - 1][j - 1];
            int insert = dp[i - 1][j];
            int del = dp[i][j - 1];
            dp[i][j] = std::min(replace, std::min(insert, del)) + 1;
        }
    }
    return dp[n][m];
}

std::vector<int> z_function(const std::string& s) {
    std::vector<int> z(s.size(), 0);
    int l = 0;
    int r = 0;
    for (int i = 1; i != s.size(); ++i) {
        if (r >= i) {
            z[i] = std::min(z[i - l], r - i + 1);
        }
    
        while (z[i] + i < s.size() && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }

        if (z[i] <= r - i + 1) {
            continue;
        }
        l = i;
        r = i + z[i] - 1;
    }
    
    return z;
}


bool pattern_match(const std::string& s, const std::string& p)
{
    bool ans = false;
    pattern_match_helper(s, p, ans);
    return ans;
}


}
}
