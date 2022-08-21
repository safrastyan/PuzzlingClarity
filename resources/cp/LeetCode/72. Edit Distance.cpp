class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int n = word1.size();
        int m = word2.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, std::numeric_limits<int>::max()));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                    continue;
                }
                int replace = dp[i - 1][j - 1];
                int insert = dp[i - 1][j];
                int del = dp[i][j - 1];
                dp[i][j] = std::min(replace, std::min(insert, del)) + 1;
            }
        }
        return dp[n][m];
    }
};