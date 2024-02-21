class Solution {
public:
    bool ch(const std::string& s, const std::string& quality)
    {
        for (auto c: s) {
            if (quality.find(c) == -1) {
                return false;
            }
        }
        return true;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        for (const auto& w: words) {
            ans += ch(w, allowed) ? 1 : 0;
        }
        return ans;
    }
};