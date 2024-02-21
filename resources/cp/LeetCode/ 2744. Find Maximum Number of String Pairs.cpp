class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ans = 0;
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                auto w = words[j];
                std::reverse(w.begin(), w.end());
                if (words[i] == w) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};