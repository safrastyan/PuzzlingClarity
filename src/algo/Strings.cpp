#include "algo/Strings.hpp"

#include <cassert>

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

}
}
