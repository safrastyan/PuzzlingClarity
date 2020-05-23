bool is_palindrome(std::string s)
{
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

std::string buildPalindrome(std::string st) 
{
    for (int i = 0; i <= st.size(); ++i) {
        std::string suf = st.substr(0, i);
        std::reverse(suf.begin(), suf.end());
        if (is_palindrome(st + suf)) {
            return st + suf;
        }
    }
    return "";
}
