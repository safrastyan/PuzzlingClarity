class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) 
    {
        std::vector<std::vector<int>> dp(a.size(), std::vector<int>(a[0].size(), 0));
        if (a[0][0] == 0) {
            dp[0][0] = 1;
        }
        for (int i = 1; i < a[0].size(); ++i) {
            if (a[0][i] != 1) {
                dp[0][i] = dp[0][i - 1];
            }
        }
        for (int i = 1; i < a.size(); ++i) {
            if (a[i][0] != 1) {
                dp[i][0] = dp[i - 1][0];
            }
        }
        
        for (int i = 1; i < a.size(); ++i) {
            for (int j = 1; j < a[0].size(); ++j) {
                if (a[i][j] != 1) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[a.size() - 1][a[0].size() - 1];
    }
};