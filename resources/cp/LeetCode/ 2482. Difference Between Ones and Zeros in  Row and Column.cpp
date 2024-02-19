class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        std::vector<int> Or, oc, zr, zc;
        Or = oc = zr = zc = std::vector<int>(n * m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    ++zr[i];
                    ++zc[j];
                    continue;
                }
                ++Or[i];
                ++oc[j];
            }
        }
        std::vector<std::vector<int>> res(n, std::vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[i][j] = Or[i] + oc[j] - zr[i] - zc[j];
            }
        }
        return res;
    }
};