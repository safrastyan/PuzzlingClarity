class Solution {
public:
    void rec(const std::vector<std::vector<int>>& grid, int r, int c, std::vector<std::vector<char>>& mark, int& ans, int free_cell)
    {
        static constexpr int px[] = {-1, 1, 0, 0};
        static constexpr int py[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; ++i) {
            int new_r = r + px[i];
            int new_c = c + py[i];
            if (new_r >= 0 && new_c >= 0 && new_r < grid.size() && new_c < grid[0].size() && mark[new_r][new_c] == 0 && grid[new_r][new_c] != -1) {
                if(grid[new_r][new_c] == 2 && free_cell == 0) {
                    ++ans;
                    continue;
                }
                mark[new_r][new_c] = 1;
                rec(grid, new_r, new_c, mark, ans, free_cell - 1);
                mark[new_r][new_c] = 0;
            }
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int r = -1, c = -1;
        int free_cell = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    ++free_cell;
                    continue;
                }
                if (grid[i][j] == 1) {
                    r = i;
                    c = j;
                }
            }
        }
        
        int ans = 0;
        std::vector<std::vector<char>> mark(n, std::vector<char>(m, 0));
        mark[r][c] = 1;
        rec(grid, r, c, mark, ans, free_cell);
        return ans;
    }
};