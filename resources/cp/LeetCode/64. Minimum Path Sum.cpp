class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        std::vector<std::vector<int>> a(grid.size(), std::vector<int>(grid[0].size(), 0));
        a[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); ++i) {
            a[i][0] = a[i - 1][0] + grid[i][0];
        }
        
        for (int i = 1; i < grid[0].size(); ++i) {
            a[0][i] = a[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                a[i][j] = std::min(a[i - 1][j], a[i][j - 1]) + grid[i][j];
            }
        }
        return a.back().back();
    }
};