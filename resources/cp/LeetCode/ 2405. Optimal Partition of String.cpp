class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        std::vector<char> mark(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            if (mark[s[i] - 'a'] == 1) {
                ++ans;
                mark = std::vector<char>(26, 0);
                --i;
                continue;
            }
            mark[s[i] - 'a'] = 1;
        }
        return ans + 1;
    }
};