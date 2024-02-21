#include "algo/Strings.hpp"

#include <cassert>
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


}
}
