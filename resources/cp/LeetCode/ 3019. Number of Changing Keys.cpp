class Solution {
public:
    int countKeyChanges(string s) {
        int ans = 0;
        s.push_back(s.back());
        for (int i = 0; i < s.size() - 1; ++i) {
            if (std::tolower(s[i]) != std::tolower(s[i + 1])) {
                ++ans;
            }
        }
        return ans;
    }
};