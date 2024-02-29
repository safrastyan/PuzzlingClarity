#include "algo/Strings.hpp"

#include <cassert>
#include <limits>
#include <stack>

namespace {
bool matching(char c1, char c2)
{
    return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
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

}
}
