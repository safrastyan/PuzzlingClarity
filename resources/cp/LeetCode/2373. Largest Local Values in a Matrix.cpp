class Solution {
public:
    int get(const std::vector<std::vector<int>>& a, int r, int c)
    {
        int b = a[r][c];
        for (int i = r; i < r + 3; ++i) {
            b = std::max(b, *std::max_element(a[i].begin() + c, a[i].begin() + c + 3));
        }
        return b;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<int>> res(n - 2, std::vector<int>(m - 2, 0));
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < m - 2; ++j) {
                res[i][j] = get(grid, i, j);
            }
        }    
        return res;
    }
};