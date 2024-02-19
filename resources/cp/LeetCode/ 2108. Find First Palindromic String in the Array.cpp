class Solution {
public:
    bool ch(const std::string& s)
    {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (const auto& w: words) {
            if (ch(w)) {
                return w;
            }
        }
        return "";
    }
};