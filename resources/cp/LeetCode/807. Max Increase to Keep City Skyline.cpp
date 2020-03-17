class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
    {
        std::vector<int> top;
        std::vector<int> left;
        
        for (int i = 0; i < grid[0].size(); ++i) {
            int m = grid[0][i];
            for (int j = 1; j < grid.size(); ++j) {
                m = std::max(m, grid[j][i]);
            }
            top.push_back(m);
        }
        
        for (int i = 0; i < grid.size(); ++i) {
            left.push_back(*std::max_element(grid[i].begin(), grid[i].end()));
        }
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                int pos = std::min(left[i], top[j]);
                if (grid[i][j] < pos) {
                    res += pos - grid[i][j];
                }
            }
        }
        return res;
        
    }
};