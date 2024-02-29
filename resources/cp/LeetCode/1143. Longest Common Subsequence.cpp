class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
 
    std::vector<int> prev(m + 1, 0);
    std::vector<int> cur(m + 1, 0);

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                cur[j] = 1 + prev[j - 1];
                continue;
            }
            cur[j] = std::max(cur[j - 1], prev[j]);
        }
        prev = cur;
    }
 
    return cur[m];
    }
};