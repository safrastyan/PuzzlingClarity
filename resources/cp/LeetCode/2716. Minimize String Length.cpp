class Solution {
public:
    int minimizedStringLength(string s) {
        std::sort(s.begin(), s.end());
        auto u = std::unique(s.begin(), s.end());
        return u - s.begin();
    }
};