class Solution {
public:
    bool isMatch(string s, string p)
    {
        int n = s.size() + 1;
        int m = p.size() + 1;
        std::vector<std::vector<char>> dp(n, std::vector<char>(m, 0));
        
        dp[0][0] = 1;
        
        for (int j = 1; j < m; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (p[j - 1] != '*') {
                    if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = false;
                    }
                    continue;
                }
                
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
        
        return dp[n - 1][m - 1];
    }
};