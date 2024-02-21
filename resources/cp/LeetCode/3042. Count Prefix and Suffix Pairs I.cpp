class Solution {
public:
    bool ch(const std::string& s1, const std::string& s2)
    {
        if (s1.size() > s2.size()) {
            return false;
        }
        if (s2.find(s1) != 0) {
            return false;
        }
        if (s2.rfind(s1) != s2.size() - s1.size()) {
            return false;
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (!ch(words[i], words[j])) {
                    continue;
                }
                ++ans;
            }
        }
        return ans;
    }
};