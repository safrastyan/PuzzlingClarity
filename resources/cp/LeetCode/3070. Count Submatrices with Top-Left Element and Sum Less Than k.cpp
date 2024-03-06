class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(); 
        int m = grid[0].size();
       
        std::vector<std::vector<int>> sums(n + 1, std::vector<int>(m + 1, 0));
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
        int ans = 0;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                if (sums[i][j] <= k) {
                    ++ans;    
                }
            }
        }
        return ans;
     }
};